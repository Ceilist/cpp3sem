
cmake_minimum_required(VERSION 3.10)

project(Tests)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_library(matrix_lib STATIC src/matrix.cpp)

# Список тестов
file(GLOB TEST_SOURCES "tests/*.cpp")

# Для каждого теста создайте отдельный исполняемый файл
foreach (test_source ${TEST_SOURCES})
    # Получение имя теста без расширения
    get_filename_component(test_name ${test_source} NAME_WE) #получаем имя без расшерения
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} matrix_lib)
endforeach ()

#я собираю файлы в CLion, для удобства дублирую через Ubuntu в build