#include <cmath>
#include <UVector.h>

#define PI 3.141
float DegreeToRadian(float degree)
{
	return degree * (PI / 180);
}

float RadianToDegree(float radian)
{
	return radian * (180 / PI);
}
Vector3 ToPositionalVector(Vector3 angles)
{
	return { std::cos(DegreeToRadian(angles.x)) * std::cos(DegreeToRadian(angles.y)), std::cos(DegreeToRadian(angles.x)) * std::sin(DegreeToRadian(angles.y)), -std::sin(DegreeToRadian(angles.x)) };
}