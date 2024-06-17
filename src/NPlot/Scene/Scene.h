//
// Created by toor on 6/17/24.
//

#ifndef NPLOT_SCENE_H
#define NPLOT_SCENE_H
#include "NPlot/nplotpch.h"

namespace np
{
class Scene
{
  public:
    Scene(std::string name);
    ~Scene();


  private:
    void Init();
};
} // namespace np

#endif // NPLOT_SCENE_H
