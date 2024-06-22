//
// Created by toor on 2024-06-17 .
//
#ifndef NP_WINDOW_H_H
#define NP_WINDOW_H_H

#include <NPlot/nplotpch.h>
#include <memory>

namespace np
{

struct WindowSpecs
{
    std::string Title;
    unsigned int Width, Height;

    WindowSpecs(const std::string &title = "NPlot", int width = 720,
                int height = 480)
        : Title(title), Width(width), Height(height)
    {
    }
};

class Window
{
  public:
    using EventCallbackFn = std::function<void(Event &)>;

    Window(const WindowSpecs &specs = WindowSpecs());
    ~Window();

    void OnUpdate();
    void ClearDisplay(glm::vec3 color);

    void SetVSync(bool enabled);
    void MakeFullscreen();
    unsigned int GetWidth() const { return m_Data.Width; }
    unsigned int GetHeight() const { return m_Data.Height; }
    void SetEventCallback(const EventCallbackFn &callback)
    {
        m_Data.m_EventCallback = callback;
    }
    bool IsVSync() const { return m_Data.VSync; }
    void *GetNativeWindow() const { return m_Window; };

  private:
    struct WindowData
    {
        std::string Title;
        unsigned int Width, Height;
        bool Fullscreen = false;
        bool VSync;
        EventCallbackFn m_EventCallback;
    };

    void SetCallBackEvents();

    GLFWwindow *m_Window;
    WindowSpecs m_WindowSpecs;
    WindowData m_Data;
};

} // namespace np

#endif
