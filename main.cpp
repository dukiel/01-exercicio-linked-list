#include <cassert>
#include <iostream>
#include "linked_list.h"

using namespace std;

static void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "criaLista() passou em todos os testes" << endl;
}

static void teste_insere() {
    cout << "Testando insere()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere primeiro elemento
    insere(*lista, 10);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio != NULL);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Insere segundo elemento (deve ficar no início)
    insere(*lista, 20);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 20);
    assert(lista->inicio->proximo->conteudo == 10);

    // Insere terceiro elemento
    insere(*lista, 30);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "insere() passou em todos os testes" << endl;
}

static void teste_destroiLista() {
    cout << "Testando destroiLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insere(*lista, 1);
    insere(*lista, 2);
    insere(*lista, 3);

    // Destrói a lista
    destroiLista(*lista);

    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "destroiLista() passou em todos os testes" << endl;
}

static void teste_listaVazia() {
    cout << "Testando listaVazia()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(listaVazia(*lista) == true);
    insere(*lista, 10);
    assert(listaVazia(*lista) == false);
    destroiLista(*lista);
    free(lista);
    cout << "listaVazia() passou!" << endl;
}

static void teste_tamanhoLista() {
    cout << "Testando tamanhoLista()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(tamanhoLista(*lista) == 0);
    insere(*lista, 10);
    assert(tamanhoLista(*lista) == 1);
    insere(*lista, 20);
    assert(tamanhoLista(*lista) == 2);
    destroiLista(*lista);
    free(lista);
    cout << "tamanhoLista() passou!" << endl;
}

static void teste_inserePosicao() {
    cout << "Testando inserePosicao()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    inserePosicao(*lista, 10, 0);
    assert(lista->inicio->conteudo == 10);
    inserePosicao(*lista, 30, 1);
    assert(lista->inicio->proximo->conteudo == 30);
    inserePosicao(*lista, 20, 1);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->cardinalidade == 3);
    destroiLista(*lista);
    free(lista);
    cout << "inserePosicao() passou!" << endl;
}

static void teste_removePosicao() {
    cout << "Testando removePosicao()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 30);
    insere(*lista, 20);
    insere(*lista, 10); // Fica: 10 -> 20 -> 30

    removePosicao(*lista, 1); // Remove o 20
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->proximo->conteudo == 30);

    removePosicao(*lista, 0); // Remove o 10
    assert(lista->inicio->conteudo == 30);
    assert(lista->cardinalidade == 1);

    destroiLista(*lista);
    free(lista);
    cout << "removePosicao() passou!" << endl;
}

static void teste_inverteLista() {
    cout << "Testando inverteLista()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 30);
    insere(*lista, 20);
    insere(*lista, 10); // Fica: 10 -> 20 -> 30

    inverteLista(*lista); // Deve ficar: 30 -> 20 -> 10
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "inverteLista() passou!" << endl;
}

static void teste_mostraLista() {
    cout << "Testando mostraLista()..." << endl;
    ListaSimplesmenteEncadeada* lista = criaLista();
    insere(*lista, 30);
    insere(*lista, 20);
    insere(*lista, 10);

    cout << "  Esperado: [ 10 20 30 ]" << endl;
    cout << "  Obtido:   ";
    mostraLista(*lista);

    destroiLista(*lista);
    free(lista);
    cout << "mostraLista() concluido!" << endl;
}

// ===== FUNÇÃO PRINCIPAL =====
int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    try {
        teste_criaLista();
        teste_mostraLista();
        teste_listaVazia();
        teste_tamanhoLista();
        teste_insere();
        teste_inserePosicao();
        teste_removePosicao();
        teste_inverteLista();
        teste_destroiLista();

        cout << "\n=========================================" << endl;
        cout << "  TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
        cout << "=========================================" << endl << endl;

        return 0;
    } catch (const exception& e) {
        cout << "\nErro durante os testes: " << e.what() << endl;
        return 1;
    } catch (const char* e) {
        cout << "\nErro durante os testes: " << e << endl;
        return 1;
    }
}
