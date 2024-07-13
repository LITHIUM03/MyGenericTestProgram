if (BUILD_STATIC_LIBS)
    add_library(LinkedList_static STATIC LinkedList.c)
    target_include_directories(LinkedList_static PUBLIC ./include)
endif()

if (BUILD_SHARED_LIBS)
    add_library(LinkedList_shared SHARED LinkedList.c)
    target_include_directories(LinkedList_shared PUBLIC ./include)
endif()