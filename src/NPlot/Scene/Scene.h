//
// Created by toor on 6/17/24.
//

#ifndef NPLOT_SCENE_H
#define NPLOT_SCENE_H
#include "NPlot/Renderer/Shader.h"
#include "NPlot/nplotpch.h"

#include "NPlot/Renderer/Window.h"

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
    Window *m_Window;

    // Nu permanent , numai perntru a crea meai usor
};

} // namespace np

#endif // NPLOT_SCENE_H
