cmake_minimum_required(VERSION 3.31)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoFinal main.cpp
        Criature.cpp
        Criature.h
        Nodo.cpp
        Nodo.h
        Serializador.cpp
        Serializador.h
        Mundo.cpp
        Mundo.h
        Herbivoro.cpp
        Herbivoro.h
        Carnivoro.cpp
        Carnivoro.h)
