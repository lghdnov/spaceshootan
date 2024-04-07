include_directories(.)
include_directories(rendering)
include_directories(components)
include_directories(playerlogic)

add_executable(spaceshootan main.cpp
        utils/ecs.h
        utils/logger.h
        rendering/Renderer.cpp
        rendering/Renderer.h
        playerlogic/PlayerController.cpp
        playerlogic/PlayerController.h
        utils/impl.h
        components/PhysicalObject.h
        components/GraphicObject.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
