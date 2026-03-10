#include <stdio.h>
#include <string.h>

// Eu tava bem frustrado com a ideia de escrever um codigo onde eu tenho que refazer 8 (ou mais) variaveis pra cada instancia da carta, então aprendi sobre struct e coloquei aqui as declarações com seus tamanhos apropriados, fora da main pra ser usado na função abaixo.
struct Carta {
    char estado[4];
    char cidade[30];
    char codigo[4];
    char cod_estado[10]; 
    unsigned long int populacao;
    int pontos_turisticos;
    float area;
    float pib;
    float dens_populacional;
    float pib_per_capita;
    float super_poder;
};

// Essa função é responsavel por fazer o calculo de densidade populacional e pip per capita para qualquer carta (chamado na main pra executar o calculo)
struct Carta calcularPropriedades(struct Carta c) {
    // Densidade populacional calculado como população / area
    c.dens_populacional = c.populacao / c.area;
    // Pip per capita calculado usando o pib (vezes um bilhão pra ficar correto) / população
    c.pib_per_capita = (c.pib * 1000000000) / c.populacao;
    // retorna a carta com esses valores formatados (o que significa que eu só posso chamar essa função após declarar população, area e pib.)
    return c;
}


int main() {
    // Criamos as instancias de carta pra carta1 e carta2
    struct Carta carta1, carta2;

    // Coletamos os dados da primeira carta.
    printf("--- Cadastro da Carta 1 ---\n");
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Coletamos os dados da segunda carta.
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Realizamos o calculo de densidade e pib per capita.
    carta1 = calcularPropriedades(carta1);
    carta2 = calcularPropriedades(carta2);

    // Cálculo do Super Poder: soma de todos os atributos (com densidade invertida, pois menor é melhor).
    carta1.super_poder = (float)carta1.populacao + carta1.area + carta1.pib + (float)carta1.pontos_turisticos + carta1.pib_per_capita + (1.0f / carta1.dens_populacional);
    carta2.super_poder = (float)carta2.populacao + carta2.area + carta2.pib + (float)carta2.pontos_turisticos + carta2.pib_per_capita + (1.0f / carta2.dens_populacional);

    printf("\n--- Comparação de Cartas ---\n");

    // Variável auxiliar para armazenar o resultado da comparação (1 para verdadeiro/Carta 1, 0 para falso/Carta 2).
    int carta1_venceu;

    // Bloco de comparações atributo por atributo usando condicional ternario, exibindo o vencedor e o valor booleano do resultado.
    carta1_venceu = carta1.populacao > carta2.populacao;
    printf("População: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    carta1_venceu = carta1.area > carta2.area;
    printf("Área: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    carta1_venceu = carta1.pib > carta2.pib;
    printf("PIB: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    carta1_venceu = carta1.pontos_turisticos > carta2.pontos_turisticos;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    // Na densidade populacional, a carta com o MENOR valor vence.
    carta1_venceu = carta1.dens_populacional < carta2.dens_populacional;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    carta1_venceu = carta1.pib_per_capita > carta2.pib_per_capita;
    printf("PIB per Capita: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    carta1_venceu = carta1.super_poder > carta2.super_poder;
    printf("Super Poder: Carta %d venceu (%d)\n", carta1_venceu ? 1 : 2, carta1_venceu);

    return 0;
}