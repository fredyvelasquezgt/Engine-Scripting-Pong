#pragma once
#include <entt/entt.hpp>
#include <sol/sol.hpp>

class LuaBindings {
public:
    static void bind(sol::state& lua, entt::registry& registry);
};
