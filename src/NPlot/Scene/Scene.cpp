//
// Created by toor on 6/17/24.
//

#include "Scene.h"
#include "NPlot/Renderer/Window.h"
#include <memory>

namespace np
{
Scene::Scene(std::string name)
{
    Log::Init();
    LOG_INFO("Creating Scene " + name + "\n")
    Init();
}

Scene::~Scene() {}

void Scene::Init() { m_Window = Window::GetInstance(); }

void Scene::Update()
{
    m_Window->ClearDisplay(glm::vec3(0.5, 0.5, 0.5));

    m_Window->OnUpdate();
}
} // namespace np
