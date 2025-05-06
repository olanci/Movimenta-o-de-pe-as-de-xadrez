#include <stdio.h>
#include <stdbool.h>

// Constantes para direções
#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3

// Função recursiva para movimento da Torre
void moverTorre(int casas, int direcao) {
    if (casas <= 0) return; // Caso base
    
    switch(direcao) {
        case CIMA:
            printf("Cima\n");
            break;
        case BAIXO:
            printf("Baixo\n");
            break;
        case ESQUERDA:
            printf("Esquerda\n");
            break;
        case DIREITA:
            printf("Direita\n");
            break;
    }
    
    moverTorre(casas - 1, direcao); // Chamada recursiva
}

// Função recursiva para movimento do Bispo
void moverBispo(int casas, int direcaoVertical, int direcaoHorizontal) {
    if (casas <= 0) return; // Caso base
    
    // Movimento diagonal (combinação de vertical e horizontal)
    if (direcaoVertical == CIMA) printf("Cima ");
    else printf("Baixo ");
    
    if (direcaoHorizontal == DIREITA) printf("Direita\n");
    else printf("Esquerda\n");
    
    moverBispo(casas - 1, direcaoVertical, direcaoHorizontal); // Chamada recursiva
}

// Função recursiva para movimento da Rainha
void moverRainha(int casas, int direcao) {
    if (casas <= 0) return; // Caso base
    
    // A rainha pode se mover em qualquer direção (como torre ou bispo)
    switch(direcao) {
        case CIMA:
            printf("Cima\n");
            break;
        case BAIXO:
            printf("Baixo\n");
            break;
        case ESQUERDA:
            printf("Esquerda\n");
            break;
        case DIREITA:
            printf("Direita\n");
            break;
        default:
            // Movimento diagonal (para combinações acima de 3)
            if (direcao == 4) printf("Cima Direita\n");
            else if (direcao == 5) printf("Cima Esquerda\n");
            else if (direcao == 6) printf("Baixo Direita\n");
            else if (direcao == 7) printf("Baixo Esquerda\n");
    }
    
    moverRainha(casas - 1, direcao); // Chamada recursiva
}

// Função para movimento complexo do Cavalo
void moverCavalo(int passos) {
    for (int i = 0; i < passos; i++) {
        // Primeira parte do L: 2 casas para cima
        for (int j = 0; j < 2; j++) {
            if (i % 2 != 0) continue; // Controle de fluxo com continue
            printf("Cima\n");
        }
        
        // Segunda parte do L: 1 casa para a direita
        for (int k = 0; k < 1; k++) {
            if (i % 2 == 0) {
                printf("Direita\n");
                break; // Controle de fluxo com break
            }
        }
    }
}

// Função para movimento do Bispo com loops aninhados
void moverBispoLoops(int tamanho) {
    // Loop externo para movimento vertical
    for (int i = 0; i < tamanho; i++) {
        // Loop interno para movimento horizontal
        for (int j = 0; j < tamanho; j++) {
            if (i == j) { // Apenas nas diagonais
                printf("Cima Direita\n");
            }
        }
    }
}

int main() {
    int casas = 3; // Número de casas a mover
    
    printf("=== Movimento da Torre ===\n");
    moverTorre(casas, DIREITA);
    printf("\n");
    
    printf("=== Movimento do Bispo (recursivo) ===\n");
    moverBispo(casas, CIMA, DIREITA);
    printf("\n");
    
    printf("=== Movimento da Rainha ===\n");
    moverRainha(casas, 4); // 4 = diagonal superior direita
    printf("\n");
    
    printf("=== Movimento do Cavalo ===\n");
    moverCavalo(2); // 2 passos em L
    printf("\n");
    
    printf("=== Movimento do Bispo com Loops Aninhados ===\n");
    moverBispoLoops(3);
    printf("\n");
    
    return 0;
}