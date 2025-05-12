#include <stdio.h>

// Define o tamanho do tabuleiro como uma constante
#define DIMENSAO_TABULEIRO 10
// Define o tamanho dos navios como uma constante
#define COMPRIMENTO_NAVIO 3
// Define o valor que representa água no tabuleiro
#define AGUA 0
// Define o valor que representa um navio no tabuleiro
#define NAVIO 1

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com 0 (água)
    int campo_batalha[DIMENSAO_TABULEIRO][DIMENSAO_TABULEIRO] = {0};

    // Coordenadas iniciais do navio horizontal (linha, coluna)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    // Coordenadas iniciais do navio vertical (linha, coluna)
    int linha_navio_vertical = 6;
    int coluna_navio_vertical = 7;

    int indice; // Variável de índice para loops
    int possui_sobreposicao = 0; // Flag para indicar se há sobreposição de navios

    // ===== Posicionando o navio horizontal =====
    // Verifica se o navio horizontal cabe dentro dos limites do tabuleiro
    if (coluna_navio_horizontal + COMPRIMENTO_NAVIO <= DIMENSAO_TABULEIRO) {
        // Verifica se há sobreposição com outro navio antes de posicionar
        for (indice = 0; indice < COMPRIMENTO_NAVIO; indice++) {
            // Se a célula do tabuleiro na posição desejada não for água (já contém um navio)
            if (campo_batalha[linha_navio_horizontal][coluna_navio_horizontal + indice] != AGUA) {
                possui_sobreposicao = 1; // Indica que há sobreposição
                break; // Sai do loop, pois a sobreposição foi detectada
            }
        }

        // Posiciona o navio horizontal se não houver sobreposição
        if (!possui_sobreposicao) {
            for (indice = 0; indice < COMPRIMENTO_NAVIO; indice++) {
                campo_batalha[linha_navio_horizontal][coluna_navio_horizontal + indice] = NAVIO; // Marca a célula com o valor de navio
            }
        } else {
            printf("Erro: Navio horizontal se sobrepõe a outro navio!\n");
            return 1; // Indica que ocorreu um erro
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        return 1; // Indica que ocorreu um erro
    }

    // ===== Posicionando o navio vertical =====
    possui_sobreposicao = 0; // Reseta a flag de sobreposição para o navio vertical

    // Verifica se o navio vertical cabe dentro dos limites do tabuleiro
    if (linha_navio_vertical + COMPRIMENTO_NAVIO <= DIMENSAO_TABULEIRO) {
        // Verifica se há sobreposição com outro navio antes de posicionar
        for (indice = 0; indice < COMPRIMENTO_NAVIO; indice++) {
            // Se a célula do tabuleiro na posição desejada não for água (já contém um navio)
            if (campo_batalha[linha_navio_vertical + indice][coluna_navio_vertical] != AGUA) {
                possui_sobreposicao = 1; // Indica que há sobreposição
                break; // Sai do loop, pois a sobreposição foi detectada
            }
        }

        // Posiciona o navio vertical se não houver sobreposição
        if (!possui_sobreposicao) {
            for (indice = 0; indice < COMPRIMENTO_NAVIO; indice++) {
                campo_batalha[linha_navio_vertical + indice][coluna_navio_vertical] = NAVIO; // Marca a célula com o valor de navio
            }
        } else {
            printf("Erro: Navio vertical se sobrepõe a outro navio!\n");
            return 1; // Indica que ocorreu um erro
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro!\n");
        return 1; // Indica que ocorreu um erro
    }

    // ===== Exibindo o tabuleiro =====
    printf("\n===== Tabuleiro Batalha Naval =====\n");
    // Loop pelas linhas do tabuleiro
    for (int linha = 0; linha < DIMENSAO_TABULEIRO; linha++) {
        // Loop pelas colunas do tabuleiro
        for (int coluna = 0; coluna < DIMENSAO_TABULEIRO; coluna++) {
            printf("%d ", campo_batalha[linha][coluna]); // Imprime o valor de cada célula (0 ou 1) seguido de um espaço
        }
        printf("\n"); // Imprime uma nova linha ao final de cada linha do tabuleiro
    }

    return 0;
}