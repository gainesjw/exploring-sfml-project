cmake_minimum_required(VERSION 3.15.0)
project(project_002 VERSION 0.1.0 LANGUAGES C CXX)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to build shared libraries
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

# Testing
include(CTest)
enable_testing()

# Source files
set(SOURCES
    src/quadtree.cpp
    src/sensing.cpp
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

# Executable
add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})

# Set macOS bundle properties
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.yourcompany.yourapp")
set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/Info.plist
)

# Set resources
set(MEDIA_DIRECTORY ${PROJECT_SOURCE_DIR}/media)

# Copy media directory into the app bundle's Resources directory during build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${MEDIA_DIRECTORY} $<TARGET_BUNDLE_DIR:${PROJECT_NAME}>/Contents/media
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)

# Compiler features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# CPack settings
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Install target
install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION . COMPONENT Runtime)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
