project(GUIFromSratch )
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
file(GLOB SOURCES "src/*/*.cpp")
file(GLOB TESTS "tests/*/*.cpp")
file(GLOB HEADERS "include/*")
add_executable(main ${SOURCES})
add_executable(main ${TESTS})
add_executable(main tests/main.cpp)
set(CMAKE_BUILD_TYPE Debug)
target_link_libraries(main GTest::GTest GTest::Main Threads::Threads)
target_include_directories(main PRIVATE ${HEADERS})