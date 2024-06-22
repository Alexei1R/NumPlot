//
// Created by toor on 2024-06-20 .
//

#ifndef NP_INDEXBUFFER_CPP_H
#define NP_INDEXBUFFER_CPP_H

#include "IndexBuffer.h"
#include "NPlot/Utils/Logger.h"
#include <cstdint>

namespace np
{
IndexBuffer::IndexBuffer(uint32_t *data, uint32_t count)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data,
                 GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &m_RendererID); }

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}
void IndexBuffer::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

} // namespace np

#endif
