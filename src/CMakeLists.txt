include_directories(.)
include_directories(utils)

add_executable(spaceshootan main.cpp
        utils/ecs.h
        utils/logger.h)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
