
add_executable(main main.cpp ${sources} ${headers})
target_link_libraries(main ${ROOT_LIBRARIES})

add_executable(ScintillatorTest ScintillatorTest.cpp ${sources} ${headers})
target_link_libraries(ScintillatorTest ${ROOT_LIBRARIES})

add_executable(tree TreeTest.cpp ${sources} ${headers})
target_link_libraries(tree ${ROOT_LIBRARIES})
