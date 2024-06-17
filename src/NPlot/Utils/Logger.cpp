//
// Created by toor on 6/17/24.
//

#include "Logger.h"

namespace np
{

    Ref<spdlog::logger> Log::s_Logger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("Bright");
        s_Logger->set_level(spdlog::level::trace);
    }

} // namespace np
