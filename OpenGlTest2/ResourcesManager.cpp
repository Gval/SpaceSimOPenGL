#include "stdafx.h"
#include "ResourcesManager.h"
#include "TriangleVertices.h"
#include "CubeVertices.h"
#include "verticesTiangle.h"
#include "adresse.h"

ResourcesManager::ResourcesManager()
{
	_shaderArray = new std::vector < ShaderInterface* >;
	ShaderInterface *shader = new ShaderInterface("VertexShader.fs", "ColorShader.fs");
	_shaderArray->push_back(shader);

	ShaderInterface *lightShader = new ShaderInterface("SimpleLightShader.vsh", "SimpleLightShader.fsh");
	_shaderArray->push_back(lightShader);

	_shaderData = new ShaderData(makeVector4(1.0f, 0.0f, 1.0f, 1.0f), makeVector3(1.0f,0.0f,1.0f));
	_shaderData2 = new ShaderData(makeVector4(0.0f, 0.0f, 0.0f, 1.0f), makeVector3(1.0f, 0.0f, 1.0f));

	glGenTextures(1, &textureObj);
	glBindTexture(GL_TEXTURE_2D, textureObj);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, adresse);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	_vertexBufferArray = new std::vector<VertexBuffer*>();
	VertexBuffer* _vertexBuff = new VertexBuffer(vertices, sizeof(vertices), GL_TRIANGLES, 3, sizeof(GLfloat) * 3, _shaderArray->at(0), _shaderData, NULL, NULL);
	_vertexBufferArray->push_back(_vertexBuff);

	VertexBuffer* _cubevertexBuff = new VertexBuffer(verticesCube, sizeof(verticesCube), GL_TRIANGLES, 36, sizeof(VertexDataPN), _shaderArray->at(1), _shaderData, (GLvoid*)(offsetof(VertexDataPN, positionCoordinates)), (GLvoid*)(offsetof(VertexDataPN, normalCoordinates)));
	_vertexBufferArray->push_back(_cubevertexBuff);

	
	VertexBuffer* _vertexBuffTriangle = new VertexBuffer(verticesTriangle, sizeof(verticesTriangle), GL_TRIANGLES, 12, sizeof(GLfloat) * 3, _shaderArray->at(0), _shaderData, NULL, NULL);
	_vertexBufferArray->push_back(_vertexBuffTriangle);

	VertexBuffer* _vertexBuffTriangle2 = new VertexBuffer(verticesTriangle, sizeof(verticesTriangle), GL_LINE_LOOP, 12, sizeof(GLfloat) * 3, _shaderArray->at(0), _shaderData2, NULL, NULL);
	_vertexBufferArray->push_back(_vertexBuffTriangle2);
}



ResourcesManager::~ResourcesManager()
{
	for (std::vector<ShaderInterface* >::iterator it = _shaderArray->begin(); it != _shaderArray->end(); it++)
	{
		delete *it;
	}

	delete _shaderArray;

	for (std::vector<VertexBuffer* >::iterator it = _vertexBufferArray->begin(); it != _vertexBufferArray->end(); it++)
	{
		delete *it;
	}

	delete _shaderData;
	delete _vertexBufferArray;
}



std::vector<ShaderInterface*>* ResourcesManager::getShaderArray()
{
	return _shaderArray;
}

std::vector<VertexBuffer*>* ResourcesManager::getVertexBufferArray()
{
	return _vertexBufferArray;
}

ResourcesManager& ResourcesManager::getResourcesManager()
{
	static ResourcesManager * resourcesManager = NULL;

	if (resourcesManager == NULL)
	{
		resourcesManager = new ResourcesManager();
	}

	return *resourcesManager;
}

void ResourcesManager::destroyResourcesManager()
{
	ResourcesManager * resourcesManager = &getResourcesManager();
	delete resourcesManager;
}
