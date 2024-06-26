//
// Created by toor on 2024-06-18 .
//

#include "NPlot/Renderer/Shader.h"
#include "NPlot/Utils/Logger.h"

namespace np
{

Shader::Shader(std::string vertexShader, std::string fragmentShader)
    : program(0)
{
    vertexData = LoadShaderSRC(vertexShader.c_str());
    fragmentData = LoadShaderSRC(fragmentShader.c_str());

    CreateShader();
}

//++++++++++++ Load Shader Data ++++++++++

std::string Shader::LoadShaderSRC(const char *filepath)
{
    std::ifstream file;
    std::stringstream buf;
    std::string ret;

    file.open(filepath);

    if (file.is_open())
    {
        buf << file.rdbuf();
        ret = buf.str();
    }
    else
    {
        LOG_CRITICAL("Could not open file" + std::string(filepath) + "\n");
    }
    file.close();

    return ret;
}

//==== Compile Shader ======

unsigned int Shader::CompileShader(std::string &source, unsigned int type)
{

    const char *Data = source.c_str();

    unsigned int id = glCreateShader(type);

    glShaderSource(id, 1, &Data, nullptr);
    glCompileShader(id);

    // error
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        std::cout << "ERROR::SHADER::" + std::to_string(id) +
                         " ::COMPILATION_FAILED\n" + infoLog + "\n";
    }

    return id;
}

//+++++++++ Create Shader +++++++++
unsigned int Shader::CreateShader()
{
    program = glCreateProgram();
    unsigned int vshader = 0;
    unsigned int fshader = 0;

    vshader = CompileShader(vertexData, GL_VERTEX_SHADER);
    fshader = CompileShader(fragmentData, GL_FRAGMENT_SHADER);

    LOG_INFO("Shader Created\n");
    LOG_INFO("Vertex Shader : " + std::to_string(vshader) + "\n");
    LOG_INFO("Fragment Shader : " + std::to_string(fshader) + "\n");

    glAttachShader(program, vshader);
    glAttachShader(program, fshader);
    glLinkProgram(program);
    glValidateProgram(program);

    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }
    glDeleteShader(vshader);
    glDeleteShader(fshader);

    return 0;
}

//++++++++ Bind ++++++++++
void Shader::Bind() { glUseProgram(program); }

//++++++++ UnBind ++++++++
void Shader::UnBind() { glUseProgram(0); }

int Shader::GetUniformLocation(const std::string &name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];
    int location = glGetUniformLocation(program, name.c_str());
    if (location == -1)
    {
        LOG_WARN("warning :uniform " + name + "  doesn't exist ");
    }

    m_UniformLocationCache[name] = location;

    return location;
}

// send data to shader
void Shader::SetUniform1i(const std::string &name, int value)
{
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform1f(const std::string &name, float value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2,
                          float v3)
{
    glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::SetUniform3f(const std::string &name, float v0, float v1, float v2)
{
    glUniform3f(GetUniformLocation(name), v0, v1, v2);
}

void Shader::SetUniformMatrix4f(const std::string name, float *value,
                                unsigned int count)
{

    glUniformMatrix4fv(GetUniformLocation(name), count, GL_FALSE, value);
}
} // namespace np
