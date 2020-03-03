#pragma once

#include <iostream>
#include "InitLibs.h"
#include"Shaders.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

#include "SimpleCamera.h"
#include "Vertex.h"
#include "Texture.h"


#pragma region Buffer Factory
class BufferFact
{
public:
	virtual void BindBuffers(GLuint bufferID) = 0;
	virtual void BufferData(GLsizeiptr size, const void* data, GLenum usage) = 0;

};

class ElementBuffer : public BufferFact
{
public:

	void BindBuffers(GLuint bufferID) override
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}
	void BufferData(GLsizeiptr size, const void* data, GLenum usage) override
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
	}
};

class VertexBuffer :public BufferFact
{
public:

	void BindBuffers(GLuint bufferID) override
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	}
	void BufferData(GLsizeiptr size, const void* data, GLenum usage) override
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	}
};

#pragma endregion 

#pragma region Vertex Atrribute Pointer



class VertexAttribFact
{
public:
	virtual void EnableVertexArray(GLuint index) = 0;
	virtual void VertexAttribPointer(GLuint index, GLsizeiptr size, GLsizei stride, const void* pointer) = 0;
};

//remember not normalized 
class VertAttribFloat : public VertexAttribFact
{
public:
	void EnableVertexArray(GLuint index) override
	{
		glEnableVertexAttribArray(index);
	}
	void VertexAttribPointer(GLuint index, GLsizeiptr size, GLsizei stride, const void* pointer) override
	{
		glVertexAttribPointer(
				index,		//INDEX, it's used to specify the vertex attribute that needs to be modified
				size,		//SIZE, used to understeand the number of components per generic vertex attribute
				GL_FLOAT,	//TYPE, used to determine the type of our components per generic vertex attribute
				GL_FALSE,	//NORMALIZED, Specifies whether fixed-point data values should be normalized or converted directly as fixed-point values.
				stride,		//STRIDE, specifies the byte offest between consecutive generic vertex attributes. If this is 0, it means that the arrays are packed thightly togherter
				pointer		//POINTER, this points to the first componnent of the first generic vertex attribute. The initial value is 0
			);
	}
	
};

#pragma endregion

class Factory
{
	enum VertType { //todo implement enum for easy readability 
		NOTNORMALIZED,
		NORMALIZED
	};
public: 
	static BufferFact* createBuffer(int type, GLuint bufferID,  GLsizeiptr size, const void* data, GLenum usage);
	static VertexAttribFact* createVertAttrib(int type, GLuint index, GLsizeiptr size, GLsizei stride, const void* pointer);
};