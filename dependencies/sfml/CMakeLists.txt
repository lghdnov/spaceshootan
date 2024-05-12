message(STATUS "Fetching SFML...")

set(SFML_BUILD_AUDIO FALSE)

FetchContent_MakeAvailable(sfml)