cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
string(TIMESTAMP GET_TIME "%Y.%m.%d %H:%M:%S")
set(TIME ${GET_TIME} CACHE INTERNAL "time")
set(CACHE_LOG ${Log} CACHE INTERNAL "log")
set(LOG_BUILD OFF CACHE INTERNAL "")

# ---------- OPTIONS ----------
option(LOG_BUILD "LOG_BUILD" OFF)
option(WITH_TESTS "WITH_TESTS" OFF)

#---------- PROGRAMM PROPERTIES ----------
set_property(CACHE TIME PROPERTY VALUE ${GET_TIME})
set_property(CACHE CACHE_LOG PROPERTY VALUE)

#---------- PROGRAMM MACRO ----------
function(Log textlog) 
    if(${LOG_BUILD})
        message(${textlog})
    endif()
endfunction()

project(MathC)

include_directories(inc/linear_algebra)
include_directories(inc/tests)
#add_subdirectory(src)

if (${WITH_TESTS})
    add_subdirectory(tests)
endif()