//
// Created by toor on 2024-06-19 .
//

#ifndef NP_VERTEXARRAYBUFFER_H_H
#define NP_VERTEXARRAYBUFFER_H_H

#include "Buffer.h"
#include "NPlot/Renderer/IndexBuffer.h"
#include "NPlot/Renderer/VertexBuffer.h"
#include <vector>

namespace np
{
class VertexArrayBuffer : public Buffer
{
  public:
    VertexArrayBuffer();
    ~VertexArrayBuffer();

    void Bind() const override;
    void Unbind() const override;
    inline BufferType GetType() override { return BufferType::VertexBuffer; };

    void AddVertexBuffer(Ref<VertexBuffer> &vertexBuffer);
    void SetIndexBuffer(Ref<IndexBuffer> &indexBuffer);

  private:
    std::vector<Ref<VertexBuffer>> m_VertexBuffers;
    Ref<IndexBuffer> m_IndexBuffer;
    unsigned int m_RendererID;
};
} // namespace np

#endif
