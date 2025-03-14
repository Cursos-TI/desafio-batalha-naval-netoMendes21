#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void tabuleiro()
{
    int navio[1] = {3};
    int tabuleiroNaval[10][10] = {0};

    for (int i = 0; i < 10; i++)
    {
        tabuleiroNaval[0][0] = navio[0];
        tabuleiroNaval[0][1] = navio[0];
        tabuleiroNaval[0][2] = navio[0];

        tabuleiroNaval[2][0] = navio[0];
        tabuleiroNaval[3][0] = navio[0];
        tabuleiroNaval[4][0] = navio[0];

        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiroNaval[i][j]);
        }

        printf("\n");
    }
}

void coluna()
{
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("\n");
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c", colunas[i]);
    }

    printf("\n");
}

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int opcao;
    do
    {
        printf("\n----------------Bem Vindo ao Batalha Naval----------------\n");
        printf("1. Regras do Jogo\n");
        printf("2. Jogar\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Em manuntenção....\n");
            break;

        case 2:
            coluna();
            tabuleiro();
            break;

        default:
            printf("\n----------------###OPÇÃO INVÁLIDA###----------------\n\n");
            break;
        }
    } while (opcao != 3 || opcao > 3);
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
