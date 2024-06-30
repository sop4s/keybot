cmake_minimum_required(VERSION 3.10)
project(
  keybot
  LANGUAGES C
  VERSION 0.1
)

set(SOURCES
  src/main.c
  src/keyboard.c
  src/cli.c
  src/options.c
  src/utils.c
)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIRS})
link_directories(${X11_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES} Xext Xtst)
