# Benchmarking

Trabalho de Algoritmos e Estrutura de Dados 2

Equipe:

2023002135 - Caio Mendes Ribeiro da Rosa
2023001272 - Davi Dias Monsores dos Santos
2023010208 - Gabriel Henrique dos Santos Alves
2023007374 - Paulo Alexandre de Oliveira N. Filho
2023009225 - Tiago de Figueiredo Reis

Professora Vanessa Cristina Oliveira de Souza

## Índice

- [Sobre](#sobre)
- [Instalação](#instalação)
- [Como usar](#como-usar)

## Sobre

Trabalho de Ordenação e Análise de Complexidade - TreeSort


## Como usar

Para a utilização do programa com vetores grandes, deverá ser usado os seguintes comandos no "CMakeList.txt"
MATH(EXPR stack_size "512 * 1024 * 1024") # 512 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")