include(FetchContent)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML"
        GIT_TAG 2.6.1
)
add_subdirectory(sfml)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY "https://github.com/ocornut/imgui"
        GIT_TAG v1.90
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
        imgui-sfml
        GIT_REPOSITORY "https://github.com/SFML/imgui-sfml"
        GIT_TAG v2.6
)
add_subdirectory(imgui-sfml)