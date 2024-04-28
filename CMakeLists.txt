cmake_minimum_required(VERSION 3.27)
project(Ep1 C)

set(CMAKE_C_STANDARD 11)

include_directories(Funcoes)

add_executable(Ep1
        Funcoes/Algoritmos_Ordenação/Algoritmos.h
        Funcoes/GeraVetor/GeraVetor.c
        Funcoes/GeraVetor/GeraVetor.h
        Funcoes/Algoritmos_Ordenação/Insertion.c
        Funcoes/main.c
        Funcoes/Algoritmos_Ordenação/Mergesort.c
        Funcoes/Algoritmos_Ordenação/Quicksort.c
        Funcoes/Algoritmos_Ordenação/Selection.c
        Funcoes/Tabela/Tabela.c
        Funcoes/TreeSort/TreeSort.c
        Funcoes/TreeSort/TreeSort.h
        Funcoes/iniciarFuncoes/iniciarFuncoes.h
        Funcoes/iniciarFuncoes/iniciarFuncoes.c
        Funcoes/Tabela/Tabela.h
        Funcoes/Menu/Menu.h
        Funcoes/Menu/Menu.c)

MATH(EXPR stack_size "512 * 1024 * 1024") # 512 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
