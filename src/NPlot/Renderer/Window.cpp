//
// Created by toor on 2024-06-17 .
//

#include "NPlot/Events/Event.h"
#include "NPlot/Events/ImplEvent.h"
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
    SetCallBackEvents();
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

void Window::SetCallBackEvents()
{
    // Set GLFW callbacks
    glfwSetWindowSizeCallback(
        m_Window,
        [](GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);

            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowEvent event(width, height, Action::Resize);
            data.m_EventCallback(event);
        });

    glfwSetWindowCloseCallback(
        m_Window,
        [](GLFWwindow *window)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            WindowEvent event(0, 0, Action::Close);
            data.m_EventCallback(event);
        });

    glfwSetKeyCallback(
        m_Window,
        [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyEvent event(key, Action::KeyPress);
                data.m_EventCallback(event);

                break;
            }
            case GLFW_RELEASE:
            {
                KeyEvent event(key, Action::KeyRelease);
                data.m_EventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyEvent event(key, Action::KeyRepeat);
                data.m_EventCallback(event);
                break;
            }
            }
        });

    glfwSetCharCallback(m_Window,
                        [](GLFWwindow *window, unsigned int keycode)
                        {
                            WindowData &data =
                                *(WindowData *)glfwGetWindowUserPointer(window);

                            KeyEvent event(keycode, Action::RegisterKeyChar);
                            data.m_EventCallback(event);
                        });

    glfwSetMouseButtonCallback(
        m_Window,
        [](GLFWwindow *window, int button, int action, int mods)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyEvent event(button, Action::KeyPress);
                data.m_EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyEvent event(button, Action::KeyRelease);
                data.m_EventCallback(event);
                break;
            }
            }
        });

    glfwSetScrollCallback(
        m_Window,
        [](GLFWwindow *window, double xOffset, double yOffset)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseEvent event(xOffset, yOffset, Action::Scroll);
            data.m_EventCallback(event);
        });

    glfwSetCursorPosCallback(
        m_Window,
        [](GLFWwindow *window, double xPos, double yPos)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseEvent event(xPos, yPos, Action::Move);
            data.m_EventCallback(event);
        });
}

} // namespace np
