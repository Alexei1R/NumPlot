//
// Created by toor on 6/17/24.
//

#include "Scene.h"
#include "NPlot/Events/ImplEvent.h"
#include "NPlot/Renderer/Buffer.h"
#include "NPlot/Renderer/IndexBuffer.h"
#include "NPlot/Renderer/VertexBuffer.h"
#include "NPlot/Renderer/Window.h"
#include "NPlot/Utils/Logger.h"
#include <memory>
#include <strings.h>

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

Scene::Scene(std::string name)
{
    Log::Init("Nplot");
    LOG_INFO("Creating Scene " + name + "\n")

    Init();
}

Scene::~Scene() { LOG_INFO("Destroying Scene") }
void Scene::Init()
{
    m_Window = std::make_shared<Window>();
    m_Window->SetEventCallback(
        std::bind(&Scene::HandleEvent, this, std::placeholders::_1));

    float vertices[] = {
        0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // top right
        0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // bottom left
        -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.5f, 1.0f  // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    }; // Generating VAO and binding it

    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    m_VertexBuffer = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
    m_VertexBuffer->Bind();

    m_IndexBuffer = std::make_shared<IndexBuffer>(
        indices, sizeof(indices) / sizeof(unsigned int));
    m_IndexBuffer->Bind();

    BufferLayout layout = {{ShaderDataType::Float3, "aPos"},
                           {ShaderDataType::Float4, "aColor"}};

    // Vertex Attributes Layout
    m_VertexBuffer->SetLayout(layout);

    int index = 0;
    for (auto const &element : m_VertexBuffer->GetLayout())
    {

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, element.GetComponentCount(),
                              ShaderDataTypeToOpenGLBaseType(element.Type),
                              element.Normalized ? GL_TRUE : GL_FALSE,
                              layout.GetStride(), (const void *)element.Offset);
        index++;
    }

    m_Shader = std::make_shared<Shader>(
        "/home/toor/Code/NumPlot/src/NPlot/Assets/default.vs",
        "/home/toor/Code/NumPlot/src/NPlot/Assets/default.fs");
    m_Shader->Bind();

    // Unbind VAO
    glBindVertexArray(0);
} // namespace np
void Scene::Update()
{
    m_Window->ClearDisplay(glm::vec3(0.5, 0.5, 0.5));

    // MY CODE
    // Bind shader
    m_Shader->Bind();

    // Bind Vertex Array Object
    glBindVertexArray(m_VAO);

    // Draw two squares
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

    // Unbind VAO and shader
    glBindVertexArray(0);
    m_Shader->UnBind();
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

    /*if (event.GetType() == EventType::Key)*/
    /*{*/
    /*    KeyEvent keyEvent = static_cast<const KeyEvent &>(event);*/
    /*    if (keyEvent.GetAction() == Action::KeyPress)*/
    /*    {*/
    /*        LOG_INFO("Key pressed {0} ", keyEvent.GetKey())*/
    /*    }*/
    /*}*/

    /*if (event.GetType() == EventType::Mouse)*/
    /*{*/
    /*    MouseEvent mouseEvent = static_cast<const MouseEvent &>(event);*/
    /*    if (mouseEvent.GetAction() == Action::Move)*/
    /*    {*/
    /*        LOG_INFO("Mouse Move {0} : {1}", mouseEvent.GetX(),*/
    /*                 mouseEvent.GetY())*/
    /*    }*/
    /*}*/
}
} // namespace np
