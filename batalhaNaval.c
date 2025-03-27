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

int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    if (direcao == 0) { // Horizontal
        if (coluna + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else { // Vertical
        if (linha + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 0) {
            tabuleiro[linha][coluna + i] = 3;
        } else {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição fixa das coordenadas dos navios
    int linha1 = 2, coluna1 = 3, direcao1 = 0; // Horizontal
    int linha2 = 5, coluna2 = 6, direcao2 = 1; // Vertical

    // Validando e posicionando os navios
    if (podePosicionar(tabuleiro, linha1, coluna1, direcao1)) {
        posicionarNavio(tabuleiro, linha1, coluna1, direcao1);
    }
    if (podePosicionar(tabuleiro, linha2, coluna2, direcao2)) {
        posicionarNavio(tabuleiro, linha2, coluna2, direcao2);
    }
    
    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);
    return 0;
}