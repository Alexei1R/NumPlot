//
// Created by toor on 6/17/24.
//

#ifndef NP_LOGGER_H
#define NP_LOGGER_H

#include "macros.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <string.h>

namespace np
{

class Log
{
  public:
    static void Init(std::string name);

    inline static Ref<spdlog::logger> &GetLogger() { return s_Logger; }

  private:
    static Ref<spdlog::logger> s_Logger;
};
} // namespace np

// Core log macros
#define LOG_TRACE(...) ::np::Log::GetLogger()->trace(__VA_ARGS__);
#define LOG_INFO(...) ::np::Log::GetLogger()->info(__VA_ARGS__);
#define LOG_WARN(...) ::np::Log::GetLogger()->warn(__VA_ARGS__);
#define LOG_ERROR(...) ::np::Log::GetLogger()->error(__VA_ARGS__);
#define LOG_CRITICAL(...) ::np::Log::GetLogger()->critical(__VA_ARGS__);

#endif // NP_LOGGER_H
