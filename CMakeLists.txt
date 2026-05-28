cmake_minimum_required(VERSION 3.10)

project(StudentaiV3 VERSION 3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Studentai
    Objektinis/main.cpp
    Objektinis/Bendra.cpp
    Objektinis/Studentas.cpp
    Objektinis/Zmogus.cpp
    Objektinis/VectorFunkcijos.cpp
    Objektinis/ListFunkcijos.cpp
    Objektinis/DequeFunkcijos.cpp
    Objektinis/Tyrimai.cpp
    Objektinis/generator.cpp
    Objektinis/Testai.cpp

    Objektinis/Bendra.h
    Objektinis/Studentas.h
    Objektinis/Zmogus.h
    Objektinis/Vector.h
    Objektinis/VectorFunkcijos.h
    Objektinis/ListFunkcijos.h
    Objektinis/DequeFunkcijos.h
    Objektinis/Tyrimai.h
    Objektinis/Testai.h
    Objektinis/struktura.h
)

target_include_directories(Studentai PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Objektinis
)