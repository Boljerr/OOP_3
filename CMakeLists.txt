cmake_minimum_required(VERSION 3.10)
project(StudentaiV2)

set (CMAKE_CXX_STANDARD 17)

add_executable(Studentai
	Objektinis/main.cpp
	Objektinis/Bendra.cpp
	Objektinis/Studentas.cpp
	Objektinis/VectorFunkcijos.cpp
	Objektinis/ListFunkcijos.cpp
	Objektinis/DequeFunkcijos.cpp
	Objektinis/Tyrimai.cpp
	Objektinis/generator.cpp
	Objektinis/Testai.cpp
	Objektinis/Zmogus.cpp
)