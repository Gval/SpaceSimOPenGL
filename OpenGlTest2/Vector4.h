#pragma once

#include <iostream>
#include <Windows.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")
#include<GL/glew.h>
#include<GLFW\glfw3.h>
#include<GL\GLU.h>

#ifndef _SimpleFps_Vector4
#define _SimpleFps_Vector4

typedef struct {

	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
} Vector4;

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#endif
