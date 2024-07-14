# Add the test executable
add_executable(test_LinkedList test_LinkedList.c test_LinkedList_Runner.c unity/unity.c)
include_directories(unity)
if (BUILD_STATIC_LIBS)
    target_link_libraries(test_LinkedList LinkedList_static pthread)
endif()

if (BUILD_SHARED_LIBS)
    target_link_libraries(test_LinkedList LinkedList_shared pthread)
endif()

# Add tests
add_test(NAME test_LinkedList COMMAND test_LinkedList)
