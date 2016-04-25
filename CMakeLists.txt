cmake_minimum_required(VERSION 2.8.8)
project(Tracking)

#To put all the executables in build directory
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}) 

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

# see if we have CCACHE ( to avoid recompilation on branch switches )
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message(STATUS "found ccache")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)


if(EVE AND OPENGL)
message(STATUS "You have switched on both EVE and OPENGL, only one can work at a time, so i am Switching OFF both and using ROOTs default graphics")
set(EVE OFF)
set(OPENGL OFF)
endif()


if(EVE)
add_definitions(-DUSE_EVE)
else()
if(OPENGL)
add_definitions(-DUSE_OGL)
endif()
endif() 



find_package(ROOT REQUIRED)
include_directories(AFTER SYSTEM ${ROOT_INCLUDE_DIR})
#find_package(Geant4 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/TreeExercise)
include_directories(${PROJECT_SOURCE_DIR}/visualizer)



if(EVE)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.h ${PROJECT_SOURCE_DIR}/TreeExercise/Tree.h ${CMAKE_SOURCE_DIR}/visualizer/Eve/EveVisualizer.h)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/TreeExercise/Tree.cpp ${PROJECT_SOURCE_DIR}/TreeExercise/Stats.cpp ${CMAKE_SOURCE_DIR}/visualizer/Eve/EveVisualizer.cpp )
else()
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.h ${PROJECT_SOURCE_DIR}/TreeExercise/Tree.h ${CMAKE_SOURCE_DIR}/visualizer/Visualizer.h)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/TreeExercise/Tree.cpp ${PROJECT_SOURCE_DIR}/TreeExercise/Stats.cpp ${CMAKE_SOURCE_DIR}/visualizer/Visualizer.cpp )
endif(EVE)

file(GLOB CFG_FILES ${PROJECT_SOURCE_DIR}/CfgFiles/*)
file(COPY ${CFG_FILES} DESTINATION ${PROJECT_SOURCE_DIR}/build)

#add_executable(main main.cpp ${sources} ${headers})
#target_link_libraries(main ${ROOT_LIBRARIES})

#add_executable(ScintillatorTest ScintillatorTest.cpp ${sources} ${headers})
#target_link_libraries(ScintillatorTest ${ROOT_LIBRARIES})

add_subdirectory(TreeExercise)
add_subdirectory(test)

