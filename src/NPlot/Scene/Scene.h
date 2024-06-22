//
// Created by toor on 6/17/24.
//

#ifndef NPLOT_SCENE_H
#define NPLOT_SCENE_H

#include "NPlot/Renderer/Buffer.h"
#include "NPlot/Renderer/Window.h"

#include "NPlot/Renderer/IndexBuffer.h"
#include "NPlot/Renderer/Shader.h"
#include "NPlot/Renderer/VertexArrayBuffer.h"
#include "NPlot/Renderer/VertexBuffer.h"
namespace np
{
class Scene
{
  public:
    Scene(std::string name);
    ~Scene();

    void Update();
    bool IsRunning() { return m_Running; }

  private:
    void Init();

    void HandleEvent(const Event &event);

  private:
    bool m_Running = true;
    std::shared_ptr<Window> m_Window;

    // Nu permanent , numai perntru a crea meai usor
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<VertexBuffer> m_VertexBuffer;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
    unsigned int m_VAO;
};

} // namespace np

#endif // NPLOT_SCENE_H
