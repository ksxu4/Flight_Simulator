#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include"vector3.h"

class Aircraft 
{
public:
	Aircraft():mass(1) {};
	~Aircraft() {};
	// public members
	Vector3 locationEarth;
	Vector3 velocity;
	Vector3 acceleration;
	// functions for private members
	void setMass(double m);
	double getMass() const;
	// print function
	void print() const;
private:
	double mass;
};

#endif