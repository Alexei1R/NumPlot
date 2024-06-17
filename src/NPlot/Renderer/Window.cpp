//
// Created by toor on 2024-06-17 .
//

#include "NPlot/Utils/Logger.h"
#include <NPlot/Renderer/Window.h>

namespace np
{

static void GLFWErrorCallback(int error, const char *description)
{
    LOG_ERROR("GLFW Error ({0}): {1}", error, description);
}

Window *Window::s_WindowInstance = nullptr;

Window *Window::GetInstance(const WindowSpecs &spec)
{

    if (!s_WindowInstance)
    {
        s_WindowInstance = new Window(spec);
    }
    return s_WindowInstance;
}

Window::Window(const WindowSpecs &specs) : m_WindowSpecs(specs)
{
    LOG_INFO("Creating Instance")

    m_Data.Title = specs.Title;
    m_Data.Width = specs.Width;
    m_Data.Height = specs.Height;

    LOG_INFO("Creating Window ::  {0}, {1}:{2}", m_Data.Title, m_Data.Width,
             m_Data.Height)
    int success = glfwInit();
    if (success != 1)
    {
        LOG_CRITICAL("!Succes glfw")
    }
    glfwSetErrorCallback(GLFWErrorCallback);
    m_Window = glfwCreateWindow(
        (int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(),
        m_Data.Fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);
    int version = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!version)
    {
        LOG_CRITICAL("Failed to initialize OpenGL context")
        return;
    }
    LOG_INFO("WINDOW Init with succes")
    LOG_INFO("OpenGL Info:");
    LOG_INFO("  Vendor: {}",
             reinterpret_cast<const char *>(glGetString(GL_VENDOR)));
    LOG_INFO("  Renderer: {}",
             reinterpret_cast<const char *>(glGetString(GL_RENDERER)));
    LOG_INFO("  Version: {}",
             reinterpret_cast<const char *>(glGetString(GL_VERSION)));

    glfwSetWindowUserPointer(m_Window, &m_Data);
    // Enables the Depth Buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Window::~Window()
{

    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Window::OnUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

void Window::ClearDisplay(glm::vec3 color)
{
    glClearColor(color.r, color.g, color.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::MakeFullscreen()
{
    glfwSetWindowMonitor(m_Window, glfwGetPrimaryMonitor(), 0, 0, m_Data.Width,
                         m_Data.Height, GLFW_DONT_CARE);
}

// Window attributes
void Window::SetVSync(bool enabled)
{
    m_Data.VSync = enabled;
    glfwSwapInterval(enabled ? 1 : 0);
}

} // namespace np
