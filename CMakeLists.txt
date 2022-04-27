cmake_minimum_required(VERSION 3.0)

# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_RPATH "\$ORIGIN" CACHE STRING "The runtime path given to the linker")

if (MSVC)
    add_compile_options(/W4)
    # add_compile_options(/WX)  # treat warnings as errors
else()
    add_compile_options(-Wextra)
    # add_compile_options(-Wall -pedantic)
    # add_compile_options(-Werror)
endif()

# ------------------ #
project(sysiphos)

include_directories(lib/include)

# specify the source files:
file(GLOB SOURCES lib/src/*.cpp)

# the target to be build:
add_library(sysiphos SHARED ${SOURCES})

# ------------------ #
project(testapp)

include_directories(app/include)

# specify the source files:
file(GLOB SOURCES app/src/*.cpp)

# the target to be build:
add_executable(testapp ${SOURCES})

# ..and link it to our library:
target_link_libraries(testapp sysiphos)
