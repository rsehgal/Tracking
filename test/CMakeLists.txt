
set(TEST_EXECUTABLES ${CMAKE_SOURCE_DIR}/test/main.cpp
${CMAKE_SOURCE_DIR}/test/ScintillatorTest.cpp
${CMAKE_SOURCE_DIR}/test/TreeTest.cpp
)

macro(build_executables EXECUTABLES)
  foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(TARGET_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${TARGET_NAME} ${EXECUTABLE} ${sources} ${headers})
    target_link_libraries(${TARGET_NAME} ${ROOT_LIBRARIES})
  endforeach()
endmacro()                        

build_executables("${TEST_EXECUTABLES}")

