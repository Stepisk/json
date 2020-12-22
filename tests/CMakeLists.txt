add_executable(unit_tests "main.cpp")
target_sources(unit_tests PRIVATE "factorial.cpp")

target_include_directories(unit_tests PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(unit_tests PRIVATE ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_compile_definitions(unit_tests PRIVATE -DBOOST_ALL_NO_LIB)
target_compile_features(unit_tests PRIVATE cxx_std_17)

add_custom_target(check ALL COMMAND unit_tests)
