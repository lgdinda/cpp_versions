project(cpp14)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        cpp14.h
   )

set(SOURCE_FILES
        cpp14.cpp
   )

add_executable(cpp14 ${SOURCE_FILES})