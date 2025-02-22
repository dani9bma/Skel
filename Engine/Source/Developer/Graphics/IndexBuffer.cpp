#include "IndexBuffer.h"

namespace Skel
{
	IndexBuffer::IndexBuffer(unsigned int data[], int count)
		: m_count(count)
	{
		glGenBuffers(1, &m_EBO);
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count, data, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		unbind();
	}

	void IndexBuffer::draw()
	{
		glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, 0);
	}

	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	}

	void IndexBuffer::unbind()
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}