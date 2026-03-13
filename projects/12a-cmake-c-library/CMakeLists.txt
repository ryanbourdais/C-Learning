cmake_minimum_required(VERSION 3.20)

project(cmake_c_library_starter C)

add_library(stats STATIC
    stats.c
)

target_include_directories(stats PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(stats_tool
    main.c
)

target_link_libraries(stats_tool PRIVATE stats)
