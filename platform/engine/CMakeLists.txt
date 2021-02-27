cmake_minimum_required(VERSION 3.10)

# set the project name
project(kayak-engine)

file(GLOB kayak_SRC
     "*.h"
     "*.cpp"
)

add_library(kayak-engine ${kayak_SRC})
