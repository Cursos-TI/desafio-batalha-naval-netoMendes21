#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para usar toupper()

#define TAMANHO 10

void imprimirTabuleiro(int tabuleiroVisivel[TAMANHO][TAMANHO])
{
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("\n  ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiroVisivel[i][j] == 3) // Acertou um navio
                printf("3 ");
            else if (tabuleiroVisivel[i][j] == -1) // Tiro errado
                printf("X ");
            else // Posição ainda não revelada
                printf("0 ");
        }
        printf("\n");
    }
}

void inicializarTabuleiros(int tabuleiro[TAMANHO][TAMANHO], int tabuleiroVisivel[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = 0;        // 0 representa água
            tabuleiroVisivel[i][j] = 0; // Tabuleiro visível inicial sem revelações
        }
    }

    // Posicionamento fixo dos navios (3 representa um navio)
    tabuleiro[0][0] = 3;
    tabuleiro[0][1] = 3;
    tabuleiro[0][2] = 3;

    tabuleiro[2][0] = 3;
    tabuleiro[3][0] = 3;
    tabuleiro[4][0] = 3;

    tabuleiro[4][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;

    tabuleiro[6][3] = 3;
    tabuleiro[7][2] = 3;
    tabuleiro[8][1] = 3;
}

int jogar(int tabuleiro[TAMANHO][TAMANHO], int tabuleiroVisivel[TAMANHO][TAMANHO])
{
    char entrada[10];
    int linha;
    char coluna;
    int colunaIndex;

    while (1)
    {
        printf("\nDigite a linha (1-10) ou 'S' para sair: ");
        scanf("%s", entrada);

        // Converte para maiúscula e verifica se é "S"
        if (toupper(entrada[0]) == 'S')
        {
            printf("Jogo encerrado!\n");
            return 0;
        }

        linha = atoi(entrada); // Converte para número

        printf("Digite a coluna (A-J) ou 'S' para sair: ");
        scanf(" %s", entrada);

        if (toupper(entrada[0]) == 'S')
        {
            printf("Jogo encerrado!\n");
            return 0;
        }

        coluna = toupper(entrada[0]);

        // Ajusta para índice do array
        linha -= 1;
        colunaIndex = coluna - 'A';

        if (linha < 0 || linha >= TAMANHO || colunaIndex < 0 || colunaIndex >= TAMANHO)
        {
            printf("Coordenada inválida! Tente novamente.\n");
            continue;
        }

        if (tabuleiroVisivel[linha][colunaIndex] != 0)
        {
            printf("⚠️ Você já atirou aqui! Escolha outra posição.\n");
            continue;
        }

        if (tabuleiro[linha][colunaIndex] == 3)
        {
            printf("\n💥 Acertou um navio!\n");
            tabuleiroVisivel[linha][colunaIndex] = 3;
        }
        else
        {
            printf("\n🌊 Água! Nenhum navio aqui.\n");
            tabuleiroVisivel[linha][colunaIndex] = -1;
        }

        return 1; // Continua o jogo
    }
}

int main()
{
    int opcao;
    int tabuleiro[TAMANHO][TAMANHO];
    int tabuleiroVisivel[TAMANHO][TAMANHO];

    inicializarTabuleiros(tabuleiro, tabuleiroVisivel);

    do
    {
        printf("\n---------------- Bem-Vindo ao Batalha Naval ----------------\n");
        printf("1. Regras do Jogo\n");
        printf("2. Jogar\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\n---------------------------- ### REGRAS DO JOGO ### ----------------------------\n\n");
            printf("Ao iniciar o jogo o usuário deverá digitar um número para selecionar a Linha desejada, que estará entre 1 - 10(sentido horizontal);\n");
            printf("Logo depois será requerido do usuário que ele escolha a Coluna desejada, escolha uma letra entre A - J ;\n");
            printf("Selecionando as coordenadas, você receberá a mensagem dizendo se acertou algum navio ou não e será mostrado no tabuleiro;\n");
            printf("Se você acertou o barco será impresso no tabuleiro: 3 senão X;\n\n");
            printf("---------------------------- ### REGRAS DO JOGO ### ----------------------------\n\n");
            break;

        case 2:
            while (1)
            {
                imprimirTabuleiro(tabuleiroVisivel);
                if (!jogar(tabuleiro, tabuleiroVisivel))
                    break; // Sai do jogo se o jogador digitar "S"
            }
            break;

        case 3:
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("\n----------------### OPÇÃO INVÁLIDA ###----------------\n\n");
            break;
        }
    } while (opcao != 3);

    return 0;
}
