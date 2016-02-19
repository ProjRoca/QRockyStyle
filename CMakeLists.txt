cmake_minimum_required(VERSION 3.0)
project(QRockyStyle)

set(CMAKE_AUTOMOC ON)

file(GLOB_RECURSE QROCKYSTYLE_SRC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp" "src/*.h")
add_library(QRockyStyle SHARED ${QROCKYSTYLE_SRC})
add_library(QRockyStyle_s STATIC ${QROCKYSTYLE_SRC})

set_target_properties(QRockyStyle PROPERTIES
    CXX_STANDARD 11 POSITION_INDEPENDENT_CODE ON)
set_target_properties(QRockyStyle_s PROPERTIES
    CXX_STANDARD 11 POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(QRockyStyle PRIVATE "QROCKYSTYLE_EXPORT")
target_compile_definitions(QRockyStyle_s PRIVATE "QROCKYSTYLE_EXPORT")

find_package(Qt5Widgets)
target_link_libraries(QRockyStyle PUBLIC Qt5::Widgets)
target_link_libraries(QRockyStyle_s PUBLIC Qt5::Widgets)
target_include_directories(QRockyStyle PUBLIC "src")
target_include_directories(QRockyStyle_s PUBLIC "src")
