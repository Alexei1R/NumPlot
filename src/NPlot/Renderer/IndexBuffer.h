//
// Created by toor on 2024-06-20 .
//

#ifndef NP_INDEXBUFFER_H_H
#define NP_INDEXBUFFER_H_H

#include "Buffer.h"
#include "NPlot/nplotpch.h"

namespace np
{
class IndexBuffer : public Buffer
{
  public:
    IndexBuffer(uint32_t *data, uint32_t count);
    ~IndexBuffer();

    IndexBuffer(const IndexBuffer &) = delete;
    IndexBuffer &operator=(const IndexBuffer &) = delete;

    void Bind() const override;
    void Unbind() const override;
    inline BufferType GetType() override { return BufferType::IndexBuffer; };

    inline unsigned int GetCount() const { return m_Count; }

  private:
    unsigned int m_RendererID;
    unsigned int m_Count;
};
} // namespace np

#endif
