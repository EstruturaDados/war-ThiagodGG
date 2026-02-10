// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória e manipulação de strings 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// --- Constantes Globais ---
#define MAX_TERRITORIOS 5
#define MAX_NOME 30
#define MAX_COR 10


// --- Criação da Estrutura (struct) ---
typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;


// Função para cadastrar os territórios, onde o usuário insere os dados de cada território, como nome, cor e quantidade de tropas.
void cadastrarTerritorios (Territorio* mapa, int n){
    for (int i = 0; i < n; i++) {
        printf("\nCadastro do Territorio %d\n", i + 1);

        printf("Digite o nome do Territorio: ");
        scanf("%s", mapa[i].nome);

        printf("Digite a cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

//Função para exibir os territórios cadastrados, mostrando as informações de cada território, como nome, cor e quantidade de tropas.
void exibirTerritorios (Territorio* mapa, int n){
    printf("\n---Territorios Cadastrados---\n");    
    for (int i = 0; i < n; i++){
      printf("%d. Territorio: %s | Cor: %s | Tropas: %d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

//Função para simular um ataque entre dois territórios
void simularAtaque (Territorio* atacante, Territorio* defensor){
   if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Ataque inválido! %s e %s pertencem ao mesmo jogador.\n", atacante->nome, defensor->nome);
        return;
    }
    
    int dadoatacante = rand() % 6 + 1; // Simula um dado de 6 lados para o atacante
    int dadodefensor = rand() % 6 + 1; // Simula um dado de 6 lados para o defensor
    printf("\n Dado do Atacante: %d", dadoatacante);
    printf("\n Dado do Defensor: %d\n", dadodefensor);

    if (dadoatacante > dadodefensor){
        printf("\n O atacante venceu! \n");

        int tropastransferidas = atacante->tropas / 2; // O atacante transfere metade de suas tropas para o território conquistado
        defensor->tropas = tropastransferidas; // O defensor recebe as tropas transferidas
        atacante->tropas -= tropastransferidas; // O atacante perde as tropas transferidas

        strncpy(defensor->cor, atacante->cor, MAX_COR); // O defensor adota a cor do atacante
    } else {
        printf("\n O atacante perdeu e perde 1 tropa! \n");
        if (atacante->tropas > 0){
            atacante->tropas--; // Garante que o número de tropas do atacante não fique negativo
        }
    }
}
// Função para liberar memoria
void liberarMemoria (Territorio* mapa){
    free(mapa);
}


// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual

    int n;
    printf("Informe o numero de territorios: ");
    scanf("%d", &n);

     Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        fprintf(stderr, "Erro ao alocar memoria para os territorios.\n");
        return 1; // Encerra o programa com código de erro
    }

    cadastrarTerritorios(mapa, n); // Chama a função para cadastrar os territórios
    exibirTerritorios(mapa, n); // Chama a função para exibir os territórios cadastrados

    int atk, def;
    printf("\nInforme o numero do territorio atacante: ");
    scanf("%d", &atk);

    printf("\nInforme o numero do territorio defensor: ");
    scanf("%d", &def);

    atk--; // Ajusta os índices para 1
    def--;

    if (atk >= 0 && atk < n && def >= 0 && def < n){
        simularAtaque(&mapa[atk], &mapa[def]);
    } else {
        printf("\nIndices Invalidos!\n");
    }

    exibirTerritorios(mapa, n); // Exibe os territórios após o ataque para mostrar as mudanças
    liberarMemoria(mapa); // Libera a memória alocada para os territórios

return 0;
}



// Vetor de territorios, responsavel por alocar um espaço na memoria para armazenar os 5 territorios. 
// struct Territorio territorios [MAX_TERRITORIOS];

// printf("=== Cadastro de Territorios do Jogo WAR ===\n");
// Laço 'for' para cadastro dos territorios e entrada de dados do usuario.
// for (int i = 0; i < MAX_TERRITORIOS; i++) {
//    printf("\nCadastro do Territorio %d\n", i + 1);

//    printf("Digite o nome do Territorio: ");
//    scanf("%s", territorios[i].nome);

//    printf("Digite a cor do exercito: ");
//    scanf("%s", territorios[i].cor);

//    printf("Digite a quantidade de tropas: ");
//    scanf("%d", &territorios[i].tropas);
// }

// Exibição dos dados e territorios cadastrados. 
// printf("\n---Territorios Cadastrados---\n");

//for (int i = 0; i < MAX_TERRITORIOS; i++){
//    printf("\nTerritorio %d\n", i + 1);
//    printf("Nome: %s\n", territorios[i].nome);
//    printf("Cor: %s\n", territorios[i].cor);
//    printf("Tropas: %d\n", territorios[i].tropas);
//}

//    return 0;
// }

// ============================================================================
