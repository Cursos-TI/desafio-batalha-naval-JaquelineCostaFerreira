#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

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

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int origemX, int origemY, char tipo) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX + i - TAM_HABILIDADE / 2;
            int y = origemY + j - TAM_HABILIDADE / 2;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                if (tipo == 'C' && (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)) {
                    tabuleiro[x][y] = 5; // Cruz
                } else if (tipo == 'O' && abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)) {
                    tabuleiro[x][y] = 5; // Octaedro
                } else if (tipo == 'N' && j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) {
                    tabuleiro[x][y] = 5; // Cone
                }
            }
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
    
    // Aplicar habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cruz
    aplicarHabilidade(tabuleiro, 6, 6, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 2, 2, 'N'); // Cone
    
    exibirTabuleiro(tabuleiro);
    return 0;
}