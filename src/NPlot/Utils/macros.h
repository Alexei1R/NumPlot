//
// Created by toor on 6/17/24.
//

#ifndef NP_MACROS_H
#define NP_MACROS_H

#include <memory>

namespace np
{

/////////////////////////////////////////////////////////
/// ASSERT////////////////////////////////////////////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
/// MEMORY////////////////////////////////////////////////
/////////////////////////////////////////////////////////

template <typename T> using Scope = std::unique_ptr<T>;

template <typename T, typename... Args>
constexpr Scope<T> CreateScope(Args &&...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T> using Ref = std::shared_ptr<T>;

template <typename T, typename... Args>
constexpr Ref<T> CreateRef(Args &&...args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

} // namespace np

#endif // NP_MACROS_H
