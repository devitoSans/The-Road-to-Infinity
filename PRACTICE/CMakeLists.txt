cmake_minimum_required(VERSION 3.0.0)

project("my_project")

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

include_directories(
    resources/libraries/include
)
link_directories(
    resources/libraries/lib
)

set(LIBS glfw3dll.lib)

# static library?
add_library(STB_IMAGE stb_image.cpp)
set(LIBS ${LIBS} STB_IMAGE)

add_library(GLAD glad.c)
set(LIBS ${LIBS} GLAD)

add_library(EXECUTE execute.cpp)
target_link_libraries(EXECUTE ${LIBS})
set(LIBS ${LIBS} EXECUTE)


set(CHAPTERS
    chapter1.cpp
)
foreach(SOURCE_PATH ${CHAPTERS})

    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable("${EXECUTABLE_NAME}" "${SOURCE_PATH}")
    target_link_libraries(${EXECUTABLE_NAME} ${LIBS})

endforeach(SOURCE_PATH ${CHAPTERS})
