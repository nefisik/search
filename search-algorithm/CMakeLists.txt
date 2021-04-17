cmake_minimum_required(VERSION 3.5)
project(search)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++20
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED) 
find_package(Boost 1.67 REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

if(${TEST_MODE})
  add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/search/search.cpp
  )
else()
  add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/search.cpp
  )
endif()

# add_subdirectory(modules/utils)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${GTEST_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${Threads_INCLUDE_DIR}
)


  

target_link_libraries(${PROJECT_NAME} 
    ${GTEST_BOTH_LIBRARIES} 
    ${Boost_BOTH_LIBRARIES} 
    Threads::Threads 
    nlohmann_json::nlohmann_json
)