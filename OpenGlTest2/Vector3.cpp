#include "stdafx.h"
#include"Vector3.h"

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z){
	Vector3 newVector;

	newVector.x = x;
	newVector.y = y;
	newVector.z = z;

	return newVector;
}

Vector3 addVector3(Vector3 A, Vector3 B){

	Vector3 newVector;

	newVector.x = A.x + B.x;
	newVector.y = A.y + B.y;
	newVector.z = A.z + B.z;

	return newVector;
}