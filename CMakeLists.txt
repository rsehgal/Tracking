cmake_minimum_required(VERSION 2.8.8)
project(VecGeom)

enable_language(CXX)

#Added to detect compiler support for C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

################################################################################
if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()
string(TOUPPER ${CMAKE_BUILD_TYPE} _build_type)

# Setting the C++ compiler to use
set("${CMAKE_CXX_COMPILER_ID}" TRUE CACHE STRING "C++ Compiler")
if (NOT GNU AND NOT Clang AND NOT Intel)
  message(WARNING "Unsupported compiler. Build will likely fail.")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)

include(MacroUtilities)
################################################################################

find_package(ROOT REQUIRED)
include_directories(AFTER SYSTEM ${ROOT_INCLUDE_DIR})
#find_package(Geant4 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/TreeExercise)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/TreeExercise/Tree.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.h ${PROJECT_SOURCE_DIR}/TreeExercise/Tree.h)

file(GLOB CFG_FILES ${PROJECT_SOURCE_DIR}/CfgFiles/*)
file(COPY ${CFG_FILES} DESTINATION ${PROJECT_SOURCE_DIR}/build)

#add_executable(main main.cpp ${sources} ${headers})
#target_link_libraries(main ${ROOT_LIBRARIES})

#add_executable(ScintillatorTest ScintillatorTest.cpp ${sources} ${headers})
#target_link_libraries(ScintillatorTest ${ROOT_LIBRARIES})

add_subdirectory(TreeExercise)
add_subdirectory(test)

