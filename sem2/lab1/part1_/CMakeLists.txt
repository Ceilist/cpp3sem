    cmake_minimum_required(VERSION 3.16)
project(lab1_part1)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES
        main.cpp
        Parser.cpp
        Field.cpp
        Cow.cpp
        Cloud.cpp
        ASCIIPicture.cpp)
# можно было сделать папку src с исходникам и в ней через рекурсию брать все файлы, а не писать вручную
# но я не стал. (в корневой папке не выйдет, т.к. рекурсия подтягивает лишнее из cmake-build-debug)
add_executable(${PROJECT_NAME} ${SOURCES})
