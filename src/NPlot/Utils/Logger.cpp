//
// Created by toor on 6/17/24.
//

#include "Logger.h"

namespace np
{

Ref<spdlog::logger> Log::s_Logger;

void Log::Init(std::string name)
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_Logger = spdlog::stdout_color_mt(name);
    s_Logger->set_level(spdlog::level::trace);
}

} // namespace np
