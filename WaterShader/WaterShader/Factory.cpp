#include "Factory.h"


BufferFact* Factory::createBuffer(int type, GLuint bufferID, GLsizeiptr size, const void* data, GLenum usage)
{
	BufferFact* bf = NULL;

	switch (type)
	{
		case 1: {
			bf = new ElementBuffer;
			break;
		}
		case 2: {
			bf = new VertexBuffer;
			break;
		}
			
	}
	bf->BindBuffers(bufferID);
	bf->BufferData(size, data, usage);

	return bf;
}

VertexAttribFact* Factory::createVertAttrib(int type, GLuint index, GLsizeiptr size, GLsizei stride, const void* pointer)
{
	VertexAttribFact * vf = NULL;

	switch (type)
	{
		case 1: {
			vf = new VertAttribFloat;
			break;
		}
			
	}
	vf->EnableVertexArray(index);
	vf->VertexAttribPointer(index, size, stride, pointer);

	return vf;
}
