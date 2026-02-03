// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória e manipulação de strings 
#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TERRITORIOS 5
#define MAX_NOME 30
#define MAX_COR 10


// --- Criação da Estrutura (struct) ---
struct Territorio {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
};

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
   
// Vetor de territorios, responsavel por alocar um espaço na memoria para armazenar os 5 territorios. 
struct Territorio territorios [MAX_TERRITORIOS];

printf("=== Cadastro de Territorios do Jogo WAR ===\n");
// Laço 'for' para cadastro dos territorios e entrada de dados do usuario.
for (int i = 0; i < MAX_TERRITORIOS; i++) {
    printf("\nCadastro do Territorio %d\n", i + 1);

    printf("Digite o nome do Territorio: ");
    scanf("%s", territorios[i].nome);

    printf("Digite a cor do exercito: ");
    scanf("%s", territorios[i].cor);

    printf("Digite a quantidade de tropas: ");
    scanf("%d", &territorios[i].tropas);
}

// Exibição dos dados e territorios cadastrados. 
printf("\n---Territorios Cadastrados---\n");

for (int i = 0; i < MAX_TERRITORIOS; i++){
    printf("\nTerritorio %d\n", i + 1);
    printf("Nome: %s\n", territorios[i].nome);
    printf("Cor: %s\n", territorios[i].cor);
    printf("Tropas: %d\n", territorios[i].tropas);
}

    return 0;
}

// ============================================================================
