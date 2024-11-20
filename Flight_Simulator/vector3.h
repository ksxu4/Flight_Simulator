#ifndef VECTOR3_H
#define VECTOR3_H
#include<iostream>
class Vector3
{
public:
	// Default constructor
	Vector3() : vector3{ 0.0, 0.0, 0.0 } {};
	// Constructor with xyz
	Vector3(double vecX, double vecY, double vecZ);
	//Copy constructor
	Vector3(const Vector3& vec);
	// Destructor
	~Vector3() {};
	// Operator overloads
	Vector3 operator+(const Vector3& vec) const;
	Vector3 operator+(double num) const;
	Vector3 operator-(const Vector3& vec) const;
	Vector3 operator-(double num) const;
	Vector3 operator*(const Vector3& vec) const; // cross product
	friend Vector3 cross(const Vector3& vec1, const Vector3& vec2); // cross product
	Vector3 operator*(double scalar) const;
	friend Vector3 operator*(double scalar, const Vector3& vec);
	Vector3 operator/(double scalar) const;
	Vector3& operator=(const Vector3& vec);
	bool operator==(const Vector3& vec) const;
	bool operator!=(const Vector3& vec) const;
	Vector3& operator+=(const Vector3& vec);
	Vector3& operator+=(double num);
	Vector3& operator-=(const Vector3& vec);
	Vector3& operator-=(double num);
	Vector3& operator*=(double scalar);
	Vector3& operator/=(double scalar);
	double operator()(int index) const;
	double& operator()(int index);
	double operator[](int index) const;
	double& operator[](int index);
	friend double dot(const Vector3& vec1, const Vector3& vec2); // dot product
	// Magnitude
	double magnitude() const;
	// Write
	void setVector(double vecX, double vecY, double vecZ);
	// Copy from another vector
	void setVector(const Vector3& vec);
	// Read
	void getVector(double& vecX, double& vecY, double& vecZ) const;
	// Copy to another vector
	void getVector(Vector3& vec) const;
	// Print
	void printVector() const;
	// std::ostream overload
	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);
private:
	double vector3[3];
};

#endif