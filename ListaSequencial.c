// Implementação Lista Sequencial Estática

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAX 10 //Tamanho máximo da lista

// Estrutura do dado
typedef struct{
    int idade;
    char nome[30];
} PESSOA;

// Estrutura lista
typedef struct{
    PESSOA vetor[TAMANHO_MAX]; //Vetor do tipo pessoa de tamanho 10
    int qtdElem; //Quantidade de elementos que tem dentro da lista
} LISTA;

// Função para preencher um dado com nome e idade
PESSOA PreencheDado();

//Cria uma lista - não tem elemtos. Só espaço alocado na memória
void criarLista(LISTA * lista);

//Insere um elemento no final da lista
void inserirElementoNoFinal(LISTA * lista, PESSOA dado);

//insere um elemento no meio da lista
void inserirNoMeio(LISTA * lista, PESSOA dado, int posicao);

//Insere elemento no final da lista
void insereInicio(LISTA * lista, PESSOA dado);

//Busca um Item a apertir do inicio da lista
PESSOA * buscarAPartirInicio(LISTA * lista, int posicao);

//Busca um item a partir do fim da lista
PESSOA * buscarAPartirFim(LISTA * lista, int posicao);

//Exclui a lista
void excluirLista(LISTA * lista);

//Remove um item do fim da lista
void removerFimDaLista(LISTA * lista);

//Remove um item do meio da lista
void removerPosicaoLista(LISTA * lista, int posicao);

//Retorna o tamanho da lista
void tamanhoDaLista(LISTA * lista);

//Lista todos os itens
void listarItens(LISTA * lista);




int main(){
    
    LISTA listaPessoa;
    int opcao = -1;
    int posicao;
    PESSOA *pessoa;
    
    PESSOA dado_pessoa;
    
    do {
        printf("\n\n\nMENU DE OPCOES\n\n\n");
        printf("[1]. Criar Lista\n");
        printf("[2]. Excluir Lista\n");
        printf("[3]. Tamanho da Lista\n");
        printf("[4]. Listar todos os Itens da Lista\n");
        printf("[5]. Inserir Item na Lista\n");
        printf("[6]. Inserir Item na Lista em Posição Especifica\n");
        printf("[7]. Remover Item na Lista\n");
        printf("[8]. Remover Item na Posicao Especifica\n");
        printf("[9]. Buscar na Lista a Partir do Inicio\n");
        printf("[10].Buscar na Lista a Partir do Fim\n");
        printf("[0]. Sair do Programa\n\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                criarLista(&listaPessoa);
                break;
            case 2:
                excluirLista(&listaPessoa);
                break;
            case 3:
                tamanhoDaLista(&listaPessoa);
                break;
            case 4:
                if (listaPessoa.qtdElem == 0) {
                    printf("Nao há elementos na lista\n");
                }
                else
                    listarItens(&listaPessoa);
                break;
            case 5:
                dado_pessoa = PreencheDado();
                insereInicio(&listaPessoa, dado_pessoa);
                break;
            case 6:
                dado_pessoa = PreencheDado();
                printf("\n\nQual é a posicao: ");
                scanf("%d", &posicao);
                inserirNoMeio(&listaPessoa, dado_pessoa, posicao);
                break;
            case 7:
                removerFimDaLista(&listaPessoa);
                break;
            case 8:
                printf("\n\nQual é a posicao: ");
                scanf("%d", &posicao);
                removerPosicaoLista(&listaPessoa, posicao);
                break;
            case 9:
                printf("\n\nQual é a posicao: ");
                scanf("%d", &posicao);
                if (posicao > listaPessoa.qtdElem) {
                    printf("ERRO: Posicao inexistente\n");
                }
                else{
                    pessoa = buscarAPartirInicio(&listaPessoa, posicao);
                    printf("Nome: %s\n", pessoa->nome);
                    printf("Idade: %d\n", pessoa->idade);
                }
            case 10:
                printf("\n\nQual é a posicao: ");
                scanf("%d", &posicao);
                if (posicao > listaPessoa.qtdElem) {
                    printf("ERRO: Posicao inexistente\n");
                }
                else{
                    pessoa = buscarAPartirInicio(&listaPessoa, posicao);
                    printf("Nome: %d\n", pessoa->idade);
                    printf("Idade: %s\n", pessoa->nome);
                }
            case 0:
                break;
            default:
                printf("\n\n\n\nOpcao invalida!!!\n\n\n\n");
                break;
        }
    } while (opcao !=0);
}


// Função para preencher um dado com nome e idade
PESSOA PreencheDado(){
    
    PESSOA dado;
    
    printf("Digite um nome:\n");
    scanf(" %s", dado.nome);
    
    printf("Digite a idade de %s:\n", dado.nome);
    scanf("%d", &dado.idade);
    
    return dado;
}

void criarLista(LISTA * lista){
    lista->qtdElem = 0;
}

void inserirElementoNoFinal(LISTA * lista, PESSOA dado){
    lista->vetor[lista->qtdElem] = dado;
    lista->qtdElem++;
}


void inserirNoMeio(LISTA * lista, PESSOA dado, int posicao){
    //verifica se a posição já está ocupada
    if (posicao >= lista->qtdElem) {
        inserirElementoNoFinal(lista, dado);
    }
    //se a posição já esta ocupada, tenho que mover todas as informações um bloco para frente
    else{
        for (int i=lista->qtdElem; i>posicao; i--) {
            lista->vetor[i] = lista->vetor[i-1];
        }
        lista->vetor[posicao] = dado;
        lista->qtdElem++;
    }
}

void insereInicio(LISTA * lista, PESSOA dado){
    inserirNoMeio(lista, dado, 0);
}


PESSOA * buscarAPartirInicio(LISTA * lista, int posicao){
    if (posicao < lista->qtdElem) {
        return &lista->vetor[posicao];
    }
    else
        return NULL; //Não encontrou
}


PESSOA * buscarAPartirFim(LISTA * lista, int posicao){
    if (posicao < lista->qtdElem) {
        posicao = lista->qtdElem-posicao;//quantidades de posições que tenho que subtrair
        return &lista->vetor[lista->qtdElem-posicao] ;
    }
    else
        return NULL; //Não encontrou
}

void listar(LISTA * lista){
    for (int i = 0; i<lista->qtdElem; i++) {
        printf("Nome: %s\n", lista->vetor[i].nome);
        printf("\nIdade: %d\n", lista->vetor[i].idade);
    }
}

void excluirLista(LISTA * lista){
    criarLista(lista);
}

void removerFimDaLista(LISTA * lista){
    if (lista->qtdElem--){
        printf("Item Removido!\n\n");
    }
    else
        printf("ERRO!\n\n");
}

void removerPosicaoLista(LISTA * lista, int posicao){
    if (posicao > lista->qtdElem) {
        printf("ERRO: Posição inexistente\n\n");
    }
    else{
        for (int i=posicao; i<lista->qtdElem-1; i++) {
            lista->vetor[i] = lista->vetor[i+1];
        }
        lista->qtdElem--;
        printf("Intem removido com sucesso!\n\n");
    }
}

void tamanhoDaLista(LISTA * lista){
    printf("Tamanho da Lista: %d\n", lista->qtdElem);
}

void listarItens(LISTA * lista){
    for (int i=0; i<lista->qtdElem; i++) {
        printf("Posicao: %d\n", i);
        printf("Nome: %s\n", lista->vetor[i].nome);
        printf("Nome: %d\n", lista->vetor[i].idade);
        printf("\n\n");
    }
}
