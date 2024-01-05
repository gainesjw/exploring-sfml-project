cmake_minimum_required(VERSION 3.5.0)
project(project_002 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

include(CTest)
enable_testing()

set(SOURCES
    src/world.cpp
    src/entity.cpp
    src/detect.cpp
    src/action.cpp
    src/configuration.cpp
    src/enemy.cpp
    src/game.cpp
    src/player.cpp
    src/main.cpp

)

add_executable(project_002 ${SOURCES})

target_link_libraries(project_002 PRIVATE sfml-graphics)
target_compile_features(project_002 PRIVATE cxx_std_17)
target_include_directories(project_002 PRIVATE ${PROJECT_SOURCE_DIR}/include)
file(COPY ${PROJECT_SOURCE_DIR}/media DESTINATION ${CMAKE_BINARY_DIR}/bin)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

install(TARGETS project_002)