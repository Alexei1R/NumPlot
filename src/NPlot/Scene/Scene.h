//
// Created by toor on 6/17/24.
//

#ifndef NPLOT_SCENE_H
#define NPLOT_SCENE_H
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

  private:
    void Init();

  private:
    Window *m_Window;
};

} // namespace np

#endif // NPLOT_SCENE_H
