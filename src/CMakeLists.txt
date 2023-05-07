cmake_minimum_required(VERSION 3.16)

if (NOT WINDOWS) 
    if (CMAKE_BUILD_TYPE MATCHES Coverage) # testing code coverage 
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    endif()
endif()

set(SOURCES Map.h
            Map.cpp
            Engine.h
            Engine.cpp
            Player.h
            Player.cpp
            Game.h
            Game.cpp) 

add_library(${LIBRARY_NAME} SHARED ${SOURCES})

target_include_directories(${LIBRARY_NAME} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${LIBRARY_NAME} PRIVATE ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME} jwt-cpp)
