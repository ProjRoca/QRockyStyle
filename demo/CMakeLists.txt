cmake_minimum_required(VERSION 3.0)
project(QRockyStyleDemo)

set(CMAKE_AUTOMOC ON)

file(GLOB_RECURSE QROCKYSTYLEDEMO_SRC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp" "src/*.h")
add_executable(QRockyStyleDemo WIN32 ${QROCKYSTYLEDEMO_SRC})
set_target_properties(QRockyStyleDemo PROPERTIES
    CXX_STANDARD 11
    POSITION_INDEPENDENT_CODE ON
)

find_package(Qt5Widgets)
target_link_libraries(QRockyStyleDemo PUBLIC Qt5::Widgets)

add_subdirectory(".." QRockyStyle)
target_link_libraries(QRockyStyleDemo PUBLIC QRockyStyle)
