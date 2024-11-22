cmake_minimum_required(VERSION 3.14)

project(kayak-engine LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core  REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core  REQUIRED)

file(GLOB kayak_SRC
     "*.h"
     "*.cpp"
)

file(GLOB kayak_protocol_SRC
     "protocol/*.h"
     "protocol/*.cpp"
)
add_library(kayak-engine
  ${kayak_SRC}
  ${kayak_protocol_SRC}
)
target_link_libraries(kayak-engine Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::SerialPort)
qt5_use_modules(kayak-engine Core SerialPort)
target_include_directories (kayak-engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
