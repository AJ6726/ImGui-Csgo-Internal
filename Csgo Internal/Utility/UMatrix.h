#include <UVector.h>

#ifndef UMATRIX_H  
#define UMATRIX_H  

struct Matrix_3x4
{
	float matrix[3][4];
	float* operator[](int index)
	{
		return matrix[index];
	}

	Vector3 Get3DPosition()
	{
		return { matrix[0][3],  matrix[1][3],  matrix[2][3] };
	}
}; 

struct Matrix_4x4
{
	float matrix[4][4];
}; 

#endif  