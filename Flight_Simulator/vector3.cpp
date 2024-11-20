#include<iostream>
#include"vector3.h"
// Constructor with xyz
Vector3::Vector3(double vecX = 0, double vecY = 0, double vecZ = 0)
{
	vector3[0] = vecX;
	vector3[1] = vecY;
	vector3[2] = vecZ;
}
// Copy constructor
Vector3::Vector3(const Vector3& vec)
{
	vector3[0] = vec.vector3[0];
	vector3[1] = vec.vector3[1];
	vector3[2] = vec.vector3[2];
}
// Overloaded operators+
Vector3 Vector3::operator+(const Vector3& vec) const
{
	return Vector3(vector3[0] + vec.vector3[0], vector3[1] + vec.vector3[1], vector3[2] + vec.vector3[2]);
}
Vector3	Vector3::operator+(double num) const
{
	return Vector3(vector3[0] + num, vector3[1] + num, vector3[2] + num);
}
// Overloaded operators-
Vector3 Vector3::operator-(const Vector3& vec) const
{
	return Vector3(vector3[0] - vec.vector3[0], vector3[1] - vec.vector3[1], vector3[2] - vec.vector3[2]);
}
Vector3	Vector3::operator-(double num) const
{
	return Vector3(vector3[0] - num, vector3[1] - num, vector3[2] - num);
}
// Overloaded operators* (cross product)
Vector3 Vector3::operator*(const Vector3& vec) const
{
	return Vector3
	(
		vector3[1] * vec.vector3[2] - vector3[2] * vec.vector3[1],
		vector3[2] * vec.vector3[0] - vector3[0] * vec.vector3[2],
		vector3[0] * vec.vector3[1] - vector3[1] * vec.vector3[0]
	);
}
Vector3 cross(const Vector3& vec1, const Vector3& vec2) 
{
	return Vector3
	(
		vec1.vector3[1] * vec2.vector3[2] - vec1.vector3[2] * vec2.vector3[1],
		vec1.vector3[2] * vec2.vector3[0] - vec1.vector3[0] * vec2.vector3[2],
		vec1.vector3[0] * vec2.vector3[1] - vec1.vector3[1] * vec2.vector3[0]
	);
}
Vector3 Vector3::operator*(double scalar) const
{
	return Vector3(vector3[0] * scalar, vector3[1] * scalar, vector3[2] * scalar);
}
Vector3 operator*(double scalar, const Vector3& vec) 
{
	return Vector3(vec.vector3[0] * scalar, vec.vector3[1] * scalar, vec.vector3[2] * scalar);
}
// Overloaded operators/
Vector3 Vector3::operator/(double scalar) const
{
	if(scalar == 0) throw std::invalid_argument("Division by zero.");
	return Vector3(vector3[0] / scalar, vector3[1] / scalar, vector3[2] / scalar);
}
// Overloaded operators=
Vector3& Vector3::operator=(const Vector3& vec)
{
	vector3[0] = vec.vector3[0];
	vector3[1] = vec.vector3[1];
	vector3[2] = vec.vector3[2];
	return *this;
}
// Overloaded operators==
bool Vector3::operator==(const Vector3& vec) const
{
	return (vector3[0] == vec.vector3[0] && vector3[1] == vec.vector3[1] && vector3[2] == vec.vector3[2]);
}
// Overloaded operators!=
bool Vector3::operator!=(const Vector3& vec) const
{
	return (vector3[0] != vec.vector3[0] || vector3[1] != vec.vector3[1] || vector3[2] != vec.vector3[2]);
	// return !(*this == vec);
}
// Overloaded operators+=
Vector3& Vector3::operator+=(const Vector3& vec)
{
	vector3[0] += vec.vector3[0];
	vector3[1] += vec.vector3[1];
	vector3[2] += vec.vector3[2];
	return *this;
}
Vector3& Vector3::operator+=(double num)
{
	vector3[0] += num;
	vector3[1] += num;
	vector3[2] += num;
	return *this;
}
// Overloaded operators-=
Vector3& Vector3::operator-=(const Vector3& vec)
{
	vector3[0] -= vec.vector3[0];
	vector3[1] -= vec.vector3[1];
	vector3[2] -= vec.vector3[2];
	return *this;
}
Vector3& Vector3::operator-=(double num)
{
	vector3[0] -= num;
	vector3[1] -= num;
	vector3[2] -= num;
	return *this;
}
// Overloaded operators*=
Vector3& Vector3::operator*=(double scalar)
{
	vector3[0] *= scalar;
	vector3[1] *= scalar;
	vector3[2] *= scalar;
	return *this;
}
// Overloaded operators/=
Vector3& Vector3::operator/=(double scalar)
{
	if(scalar == 0) throw std::invalid_argument("Division by zero.");
	vector3[0] /= scalar;
	vector3[1] /= scalar;
	vector3[2] /= scalar;
	return *this;
}
// Overloaded operators()
double Vector3::operator()(int index) const
{
	if (index < 0 || index > 3) throw std::out_of_range("Index out of range.");
	return vector3[index - 1];
}
double& Vector3::operator()(int index)
{
	if (index < 0 || index > 3) throw std::out_of_range("Index out of range.");
	return vector3[index - 1];
}
// Overloaded operators[]
double Vector3::operator[](int index) const 
{
	if (index < 0 || index >= 3) throw std::out_of_range("Index out of range.");
	return vector3[index];
}
double& Vector3::operator[](int index)
{
	if (index < 0 || index >= 3) throw std::out_of_range("Index out of range.");
	return vector3[index];
}
// Dot product
double dot(const Vector3& vec1, const Vector3& vec2)
{
	return vec1.vector3[0] * vec2.vector3[0] + vec1.vector3[1] * vec2.vector3[1] + vec1.vector3[2] * vec2.vector3[2];
}
// Magnitude
double Vector3::magnitude() const
{
	return sqrt(vector3[0] * vector3[0] + vector3[1] * vector3[1] + vector3[2] * vector3[2]);
}
// Write
void Vector3::setVector(double vecX, double vecY, double vecZ)
{
	vector3[0] = vecX;
	vector3[1] = vecY;
	vector3[2] = vecZ;
}
//Copy from another vector
void Vector3::setVector(const Vector3& vec)
{
	vector3[0] = vec.vector3[0];
	vector3[1] = vec.vector3[1];
	vector3[2] = vec.vector3[2];
}
// Read
void Vector3::getVector(double& vecX, double& vecY, double& vecZ) const
{
	vecX = vector3[0];
	vecY = vector3[1];
	vecZ = vector3[2];
}
// Copy to another vector
void Vector3::getVector(Vector3& vec) const
{
	vec.vector3[0] = vector3[0];
	vec.vector3[1] = vector3[1];
	vec.vector3[2] = vector3[2];
}
// Print
void Vector3::printVector() const
{
	std::cout << "(" << vector3[0] << ", " << vector3[1] << ", " << vector3[2] << ")" << std::endl;
}
// std::ostream overload
std::ostream& operator<<(std::ostream& os, const Vector3& vec)
{
	os << "(" << vec.vector3[0] << ", " << vec.vector3[1] << ", " << vec.vector3[2] << ")";
	return os;
}