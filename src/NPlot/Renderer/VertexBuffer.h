//
// Created by toor on 2024-06-20 .
//

#ifndef NP_VERTEXBUFFER_H_H
#define NP_VERTEXBUFFER_H_H

#include "Buffer.h"
#include "NPlot/nplotpch.h"

namespace np
{
class VertexBuffer : public Buffer
{
  public:
    VertexBuffer(float *data, uint32_t count);
    ~VertexBuffer();

    void Bind() const override;
    void Unbind() const override;
    inline BufferType GetType() override { return BufferType::VertexBuffer; };
    const BufferLayout &GetLayout() { return m_Layout; }
    void SetLayout(const BufferLayout &layout) { m_Layout = layout; }

  private:
    unsigned int m_RendererID;
    BufferLayout m_Layout;
};
} // namespace np

#endif
