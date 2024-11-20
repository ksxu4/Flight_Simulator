#include<iostream>
#include<vector>
using std::cout; using std::endl;
#include"constants.h"
#include"integrate.h"
#include"vector3.h"
#include"aircraft.h"
#include"interpolate1.h"
#include"interpolate2.h"

double t = 0;

int main()
{
	Aircraft ball;
	ball.locationEarth = Vector3(0,0,10);
	ball.velocity = Vector3(0,0,0);
	ball.acceleration = Vector3(0,0,-GRAVITY);
	do
	{
		Integrate(&ball.velocity[2],ball.acceleration[2]);
		Integrate(&ball.locationEarth[2], ball.velocity[2]);
		t += TIMESTEP;
	} 
	while (ball.locationEarth[2]>=0);

	cout << ball.locationEarth[2] << endl;
	cout << ball.velocity[2] << endl;
	cout << t << endl;
	ball.print();

	std::vector<double> x = { 1.0, 2.0, 3.0, 4.0 };
	std::vector<double> y = { 2.0, 4.0, 6.0, 8.0 };
	double x_interp = 2.5;
	double y_interp = interpolate1(x, y, x_interp);
	cout << "Interpolated value (vector): " << y_interp << endl;

	double x_array[] = { 1.0, 2.0, 3.0, 4.0 };
	double y_array[] = { 2.0, 4.0, 6.0, 8.0 };
	size_t size = 4;
	x_interp = 3.5;
	y_interp = interpolate1(x_array, y_array, size, x_interp);
	cout << "Interpolated value (array): " << y_interp << endl;

	x_interp = 1.5;
	y_interp = interpolate1(x_array, y_array, x_interp);
	cout << "Interpolated value (array): " << y_interp << endl;

	return 0;
}