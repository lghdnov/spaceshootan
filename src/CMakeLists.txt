include_directories(.)
include_directories(utils)
include_directories(rendering)

add_executable(spaceshootan main.cpp
        utils/ecs.h
        utils/logger.h
        rendering/Renderer.cpp
        rendering/Renderer.h)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
