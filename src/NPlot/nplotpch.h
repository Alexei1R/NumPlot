//
// Created by toor
//

#ifndef NP_NPLOTPCH_H
#define NP_NPLOTPCH_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>

#include <array>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <assert.h>
#include <cctype>
#include <chrono>
#include <map>
#include <mutex>
#include <queue>
#include <random>
#include <set>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <thread>

#include <cmath>

#ifdef _WIN32
#include <windows.h> // Ug, for NukeProcess -- see below
#else

#include <signal.h>
#include <unistd.h>

#endif

#include "glm/glm.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

// My Styff

#include "NPlot/Utils/macros.h"

#include "NPlot/Utils/Logger.h"

#endif
