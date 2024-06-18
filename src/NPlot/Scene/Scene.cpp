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

Scene::~Scene()
{

    LOG_INFO("Destroying Scene")
    delete m_Window;
}

void Scene::Init()
{
    m_Window = Window::GetInstance();
    m_Window->SetEventCallback(
        std::bind(&Scene::HandleEvent, this, std::placeholders::_1));

    // Shader setup
    // new Shader("/home/toor/Code/NumPlot/src/NPlot/Assets/default.vs",
    //            "/home/toor/Code/NumPlot/src/NPlot/Assets/default.fs");
}

void Scene::Update()
{
    m_Window->ClearDisplay(glm::vec3(0.5, 0.5, 0.5));

    // MY CODE
    // Draw the triangle

    m_Window->OnUpdate();
}

void Scene::HandleEvent(const Event &event)
{
    // Close Window
    if (event.GetType() == EventType::Window)
    {
        WindowEvent windowEvent = static_cast<const WindowEvent &>(event);
        if (windowEvent.GetAction() == Action::Close)
        {
            LOG_INFO("Window Closed")
            m_Running = false;
        }
    }
}
} // namespace np
