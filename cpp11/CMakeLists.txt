project(cpp11)

set(CMAKE_CXX_STANDARD 11)

set(HEADER_FILES
     cpp11.h
   )

set(SOURCE_FILES
    cpp11.cpp
   )

add_executable(cpp11 ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(cpp11 Threads::Threads)
