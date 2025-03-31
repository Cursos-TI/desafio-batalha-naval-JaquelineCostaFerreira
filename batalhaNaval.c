#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 0) {
            tabuleiro[linha][coluna + i] = 3; // Horizontal
        } else if (direcao == 1) {
            tabuleiro[linha + i][coluna] = 3; // Vertical
        } else if (direcao == 2) {
            tabuleiro[linha + i][coluna + i] = 3; // Diagonal principal
        } else {
            tabuleiro[linha + i][coluna - i] = 3; // Diagonal secundária
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavio(tabuleiro, 2, 3, 0); // Horizontal
    posicionarNavio(tabuleiro, 5, 6, 1); // Vertical
    posicionarNavio(tabuleiro, 0, 0, 2); // Diagonal principal
    posicionarNavio(tabuleiro, 0, 9, 3); // Diagonal secundária
    
    exibirTabuleiro(tabuleiro);
    return 0;
}