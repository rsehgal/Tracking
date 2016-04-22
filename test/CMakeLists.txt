
set(TEST_EXECUTABLES ${CMAKE_SOURCE_DIR}/test/main.cpp
${CMAKE_SOURCE_DIR}/test/ScintillatorTest.cpp
${CMAKE_SOURCE_DIR}/test/StatTest.cpp
${CMAKE_SOURCE_DIR}/test/TreeTest.cpp
${CMAKE_SOURCE_DIR}/test/Test2.cpp
${CMAKE_SOURCE_DIR}/test/RpcTest.cpp
${CMAKE_SOURCE_DIR}/test/HodoscopeTest.cpp
${CMAKE_SOURCE_DIR}/test/ShowerDetectionTest.cpp
${CMAKE_SOURCE_DIR}/test/EfficiencyTest.cpp
#${CMAKE_SOURCE_DIR}/test/visualization/TestVisualization.cpp

)

#LIST of viusalization file
set(TEST_VISUALIZATION_EXECUTABLES ${CMAKE_SOURCE_DIR}/test/visualization/TestVisualization.cpp
)


macro(build_executables EXECUTABLES)
  foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(TARGET_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${TARGET_NAME} ${EXECUTABLE} ${sources} ${headers})
    target_link_libraries(${TARGET_NAME} ${ROOT_LIBRARIES} Geom)
  endforeach()
endmacro()                        

#macro to build visualization files
macro(build_visualization_executables EXECUTABLES)
  foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(TARGET_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${TARGET_NAME} ${EXECUTABLE} ${CMAKE_SOURCE_DIR}/visualizer/Visualizer.cpp ${CMAKE_SOURCE_DIR}/visualizer/Visualizer.h)
    target_link_libraries(${TARGET_NAME} ${ROOT_LIBRARIES} Geom)
  endforeach()
endmacro() 

build_executables("${TEST_EXECUTABLES}")
build_executables("${TEST_VISUALIZATION_EXECUTABLES}")
#build_visualization_executables("${TEST_VISUALIZATION_EXECUTABLES}")

