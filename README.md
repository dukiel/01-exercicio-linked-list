# 01 - Lista Simplesmente Encadeada (Linked List)

## Descricao
Exercício com Lista Simplesmente Encadeada (Linked List).

**Instituição:** Universidade do Vale do Itajaí (UNIVALI)

**Curso:** Ciência da Computação

**Aluno:** Daniel Luiz Cardoso

**Professor:** Luiz Henrique Américo Salazar


## Funcionalidades
- [x] Criação/Inicialização: criar uma lista vazia
- [x] Mostrar lista: imprime os elementos da lista
- [x] Lista Vazia: verifica se lista está vazia
- [x] Número de Elementos: quantidade de elementos na lista
- [x] Inserção: início da lista
- [x] Inserção: posição específica
- [x] Remoção: elemento (node) de posição específica
- [x] Inversão: Inverter os elementos da lista
- [x] Destruição: Liberar a memória da lista

## Pré-requisitos

- Sistema Operacional
- CMake (pra usa no vs code)
- Git

## Ferramentas de Desenvolvimento
1. **Compilador C++:**
    - Windows: gcc ou visual studio
2. **Debugger:**
    - Debugger nativo do VS
3. **Editor:**
    - Visual Studio Community 2026

## Instalação

1. **Clone o repositório:**
    `git clone https://github.com/dukiel/01-exercicio-linked-list.git>`

2. **Build do projeto:**
    - Windows (executando a partir de Windows):
        ```
        bash
        mkdir build && cd build

        # Gera os arquivos de build (usando MinGW)
        cmake .. -G "MinGW Makefiles"

        # Ou usando MSVC (se tiver Visual Studio instalado)
        cmake .. -G "Visual Studio 17 2022"

        # Compila
        cmake --build .
        ```
    - VS 2026
  
        ```
        mkdir build && cd build
        
        cmake .. -G "Visual Studio 18 2026"
        
        cmake --build .
        ```


# Execução

- o fluxo de execuço principal e os testes foram unificados no mesmo arquivo para facilitr a validação.

## Fluxo de Execução

- Apos buildar o projeto, executar via cli:
    ```./build/Debug/linked_list.exe```
    (NOTA: o caminho pode variar dependNdo do compilador.)

## Fluxo de Testes

- O cli irá mostrar algo como:

    ```
    =========================================
      INICIANDO TESTES DE LINKED LIST
    =========================================

    Testando criaLista()...
    criaLista() passou em todos os testes
    Testando mostraLista()...
      Esperado: [ 10 20 30 ]
      Obtido:   [ 10 20 30 ]
    mostraLista() concluido!
    Testando listaVazia()...
    listaVazia() passou!
    Testando tamanhoLista()...
    tamanhoLista() passou!
    Testando insere()...
    insere() passou em todos os testes
    Testando inserePosicao()...
    inserePosicao() passou!
    Testando removePosicao()...
    removePosicao() passou!
    Testando inverteLista()...
    inverteLista() passou!
    Testando destroiLista()...
    destroiLista() passou em todos os testes

    =========================================
      TODOS OS TESTES PASSARAM COM SUCESSO!
    =========================================
    ```
