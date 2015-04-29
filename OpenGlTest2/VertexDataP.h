#include <iostream>
#include <Windows.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")
#include<GL/glew.h>
#include<GLFW\glfw3.h>
#include<GL\GLU.h>

#ifndef simpleFPSVertex_DATA
#define simpleFPSVertex_DATA
#include "Vector3.h"

typedef struct {

	Vector3 positionCoordinates;

} VertexDataP;

typedef struct {

	Vector3 positionCoordinates;
	Vector3 normalCoordinates;

} VertexDataPN;

#endif

