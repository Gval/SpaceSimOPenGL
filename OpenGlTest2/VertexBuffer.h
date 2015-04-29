#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "opengl32.lib")
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include "ShaderInterface.h"
#include "ShaderData.h"


class VertexBuffer
{
private :
	GLuint _vertexBufferID;
	ShaderInterface* _shader;
	ShaderData *_shaderData;

	GLenum _mode;
	GLsizei _count;
	GLsizei _stride;
	GLvoid *_positionOffset;
	GLvoid *_normalOffset;

public:
	GLuint getVertexBuffer();
	ShaderInterface* get_Shader();
	ShaderData* get_shaderData();

	VertexBuffer(const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride, ShaderInterface* shader, ShaderData* shaderData, GLvoid*positionOffset, GLvoid *normalOffset);
	~VertexBuffer();

	void configureVertexAttributes();
	void renderVertexBuffer();
};

