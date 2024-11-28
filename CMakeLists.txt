cmake_minimum_required(VERSION 3.10)

    project(GTK_MACRO_FRAMEWORK)

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

    # Add GTK3 compiler flags and link directories
    include_directories(${GTK3_INCLUDE_DIRS})
    link_directories(${GTK3_LIBRARY_DIRS})
    add_definitions(${GTK3_CFLAGS_OTHER})

    include_directories(headers)
    file(GLOB SOURCES "src/*.c")

    add_executable(GTKMacroFramework ${SOURCES})

    target_link_libraries(GTKMacroFramework ${GTK3_LIBRARIES})