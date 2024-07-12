cmake_minimum_required(VERSION 3.10)
project(sld_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encuentra la librería SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Encuentra la librería SDL2_ttf
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

# Añadir el ejecutable
add_executable(sld_test main.cpp player.cpp projectile.cpp enemy.cpp)

# Especificar las rutas manualmente para SDL2 y SDL2_ttf en macOS
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Vincular SDL2 y SDL2_ttf con tu ejecutable
target_link_libraries(sld_test /opt/homebrew/lib/libSDL2.dylib /opt/homebrew/lib/libSDL2_ttf.dylib)

# Configurar los flags de compilación
target_compile_definitions(sld_test PRIVATE SDL_MAIN_HANDLED)

message(STATUS "SDL2 libraries: ${SDL2_LIBRARIES}")
message(STATUS "SDL2_ttf libraries: ${SDL2_TTF_LIBRARIES}")
