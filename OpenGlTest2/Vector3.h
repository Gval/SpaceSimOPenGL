#include <iostream>
#include <Windows.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")
#include<GL/glew.h>
#include<GLFW\glfw3.h>
#include<GL\GLU.h>

#ifndef simpleFPSVertex_VertexDATA
#define simpleFPSVertex_VertexDATA

typedef struct {

		GLfloat x;
		GLfloat y;
		GLfloat z;

} Vector3;

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z);
Vector3 addVector3(Vector3 A, Vector3 B);

#endif