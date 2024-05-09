include_directories(.)
include_directories(rendering)
include_directories(components)
include_directories(playerlogic)
include_directories(garbage)
include_directories(physics)
include_directories(networking)

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
        components/LocalPlayer.h
        components/GarbageMark.h
        garbage/GarbageCleaner.cpp
        garbage/GarbageCleaner.h
        components/Window.h
        components/RotationVelocity.h
        components/PositionVelocity.h
        physics/VelocitySystem.cpp
        physics/VelocitySystem.h
        networking/Networking.h
        networking/NetSystem.cpp
        networking/NetSystem.h
        components/Packet.h
        networking/packet/Connection.cpp
        networking/packet/Connection.h
        networking/NetServer.cpp
        networking/NetClient.cpp
        networking/packet/SetId.cpp
        networking/packet/SetId.h
        components/NetworkingC.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-network)
