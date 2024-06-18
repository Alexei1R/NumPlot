//
// Created by toor on 2024-06-18 .
//

#ifndef NP_CAMERA_H_H
#define NP_CAMERA_H_H

#include "NPlot/nplotpch.h"

enum class Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

namespace np
{
class Camera
{

  private:
    const float YAW = -90.0f;
    const float PITCH = 0.0f;
    const float SPEED = 0.003f;
    const float SENSITIVITY = 0.6f;
    const float ZOOM = 120.0f;
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 Right;
    glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    // euler Angles
    float Yaw = -90.0f;
    float Pitch = 0.0f;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

  public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));

    glm::vec3 GetCameraPos();
    glm::vec3 GetCameraFront();

    glm::mat4 GetViewMatrix();
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset,
                              GLboolean constrainPitch = true);

    void ProcessMouseScroll(float yoffset);

  public:
    void Update();

  private:
    void updateCameraVectors();
};

} // namespace np

#endif
