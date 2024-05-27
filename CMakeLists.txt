project(cppBasedScheduler)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_CXX_STANDARD 17)

SET(SCH_SOURCE_FILES 
    source/task.cpp
    source/taskScheduler.cpp
    cppScheduler.cpp
    )
    
add_executable(scheduler.exe ${SCH_SOURCE_FILES})
target_include_directories( scheduler.exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
