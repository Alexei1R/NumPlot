//
// Created by toor on 2024-06-17 .
//

#ifndef NP_EVENT_H_H
#define NP_EVENT_H_H

#include <string>
namespace np
{

enum class EventType
{
    None = 0,
    Window,
    Key,
    Mouse,
};
enum class Action
{
    // KeyBoard And Mouse
    None = 0,
    KeyPress,
    KeyRelease,
    KeyRepeat,
    RegisterKeyChar,
    Scroll,
    // Window
    Resize,
    Move,
    Close,
    Focus,
    LoseFocus,
};

class Event
{
  public:
    virtual ~Event() = default;
    virtual EventType GetType() const = 0;
    virtual Action GetAction() const = 0;
    virtual std::string ToString() const = 0;
};

//
} // namespace np

#endif
