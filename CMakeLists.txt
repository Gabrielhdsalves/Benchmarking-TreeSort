cmake_minimum_required(VERSION 3.28)
project(Benchmarking_TreeSort C)

set(CMAKE_C_STANDARD 11)

include_directories(Funcoes/Algoritmos_Ordenacao)
include_directories(Funcoes/GeraVetor)
include_directories(Funcoes/iniciarFuncoes)
include_directories(Funcoes/Menu)
include_directories(Funcoes/Tabela)
include_directories(Funcoes/TreeSort)

add_executable(Benchmarking_TreeSort
        Funcoes/Algoritmos_Ordenacao/Algoritmos.h
        Funcoes/Algoritmos_Ordenacao/Insertion.c
        Funcoes/Algoritmos_Ordenacao/Mergesort.c
        Funcoes/Algoritmos_Ordenacao/Quicksort.c
        Funcoes/Algoritmos_Ordenacao/Selection.c
        Funcoes/GeraVetor/GeraVetor.c
        Funcoes/GeraVetor/GeraVetor.h
        Funcoes/iniciarFuncoes/iniciarFuncoes.c
        Funcoes/iniciarFuncoes/iniciarFuncoes.h
        Funcoes/Menu/Menu.c
        Funcoes/Menu/Menu.h
        Funcoes/Tabela/Tabela.c
        Funcoes/Tabela/Tabela.h
        Funcoes/TreeSort/TreeSort.c
        Funcoes/TreeSort/TreeSort.h
        Funcoes/main.c)


MATH(EXPR stack_size "512 * 1024 * 1024") # 512 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")