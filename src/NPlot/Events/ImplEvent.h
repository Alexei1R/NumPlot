//
// Created by toor on 2024-06-17 .
//

#ifndef NPLOT_EVENTS_EVENT_H
#define NPLOT_EVENTS_EVENT_H

#include "NPlot/Events/Event.h"
#include <sstream>

namespace np
{

class KeyEvent : public Event
{
  public:
    KeyEvent(int key, Action action) : key_(key), action_(action){};
    int GetKey() const { return key_; }
    EventType GetType() const override { return EventType::Key; }
    Action GetAction() const override { return action_; };
    virtual std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyEvent: " << key_ << "\n";
        return ss.str();
    };

  private:
    int key_;
    Action action_;
};

class MouseEvent : public Event
{
  public:
    MouseEvent(double x, double y, Action action)
        : x_(x), y_(y), action_(action)
    {
    }
    double GetX() const { return x_; }
    double GetY() const { return y_; }

    EventType GetType() const override { return EventType::Mouse; }
    Action GetAction() const override { return action_; };

    virtual std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseEvent: x: " << x_ << " y: " << y_ << "\n";
        return ss.str();
    };

  private:
    double x_, y_;
    Action action_;
};

class WindowEvent : public Event
{
  public:
    WindowEvent(int x, int y, Action action) : x_(x), y_(y), action_(action) {}
    double GetX() const { return x_; }
    double GetY() const { return y_; }

    EventType GetType() const override { return EventType::Window; }
    Action GetAction() const override { return action_; };

    virtual std::string ToString() const override
    {
        std::stringstream ss;
        ss << "WindowEvent: x: " << x_ << " y: " << y_ << "\n";
        return ss.str();
    };

  private:
    int x_, y_;
    Action action_;
};

} // namespace np
#endif
