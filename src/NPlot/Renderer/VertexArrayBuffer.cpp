//
// Created by toor on 2024-06-19 .
//

#include "NPlot/Renderer/VertexArrayBuffer.h"
#include "NPlot/Utils/Logger.h"
namespace np
{
static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
{
    switch (type)
    {
    case ShaderDataType::Float:
        return GL_FLOAT;
    case ShaderDataType::Float2:
        return GL_FLOAT;
    case ShaderDataType::Float3:
        return GL_FLOAT;
    case ShaderDataType::Float4:
        return GL_FLOAT;
    case ShaderDataType::Mat3:
        return GL_FLOAT;
    case ShaderDataType::Mat4:
        return GL_FLOAT;
    case ShaderDataType::Int:
        return GL_INT;
    case ShaderDataType::Int2:
        return GL_INT;
    case ShaderDataType::Int3:
        return GL_INT;
    case ShaderDataType::Int4:
        return GL_INT;
    case ShaderDataType::Bool:
        return GL_BOOL;
    }

    return 0;
}

VertexArrayBuffer::VertexArrayBuffer()
{
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
}

VertexArrayBuffer::~VertexArrayBuffer() {}

void VertexArrayBuffer::Bind() const { glBindVertexArray(m_RendererID); }

void VertexArrayBuffer::Unbind() const { glBindVertexArray(0); }

void VertexArrayBuffer::AddVertexBuffer(Ref<VertexBuffer> &vertexBuffer)
{
    glBindVertexArray(m_RendererID);
    vertexBuffer->Bind();

    int index = 0;
    auto const &layout = vertexBuffer->GetLayout();
    if (layout.GetElements().size() <= 0)
    {
        LOG_CRITICAL("Layout is not set beffore VertexArray ")
    }
    for (auto const &element : layout)
    {

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, element.GetComponentCount(),
                              ShaderDataTypeToOpenGLBaseType(element.Type),
                              element.Normalized ? GL_TRUE : GL_FALSE,
                              layout.GetStride(), (const void *)element.Offset);
        index++;
    }

    m_VertexBuffers.push_back(vertexBuffer);
}
void VertexArrayBuffer::SetIndexBuffer(Ref<IndexBuffer> &indexBuffer)
{
    glGenVertexArrays(1, &m_RendererID);
    m_IndexBuffer = indexBuffer;
    indexBuffer->Bind();
}

} // namespace np
