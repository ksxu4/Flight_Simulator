#include"aircraft.h"
#include<iostream>

void Aircraft::setMass(double m)
{
	mass = m;
}

double Aircraft::getMass() const
{
	return mass;
}

void Aircraft::print() const
{
	std::cout << "Location: " << locationEarth << std::endl;
	std::cout << "Velocity: " << velocity << std::endl;
	std::cout << "Acceleration: " << acceleration << std::endl;
	std::cout << "Mass: " << mass << std::endl;
}