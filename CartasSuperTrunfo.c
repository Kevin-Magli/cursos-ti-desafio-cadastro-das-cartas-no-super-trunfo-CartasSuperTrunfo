#include <stdio.h>
#include <string.h>

// Eu tava bem frustrado com a ideia de escrever um codigo onde eu tenho que refazer 8 (ou mais) variaveis pra cada instancia da carta, então aprendi sobre struct e coloquei aqui as declarações com seus tamanhos apropriados, fora da main pra ser usado na função abaixo.
struct Carta {
    char estado[4];
    char cidade[30];
    char codigo[4];
    char cod_estado[10]; 
    int populacao;
    int pontos_turisticos;
    float area;
    float pib;
    float dens_populacional;
    float pib_per_capita;
};

// Essa função é responsavel por fazer o calculo de densidade populacional e pip per capita para qualquer carta (chamado na main pra executar o calculo)
struct Carta calcularPropriedades(struct Carta c) {
    // Densidade populacional calculado como população / area
    c.dens_populacional = (float)c.populacao / c.area;
    // Pip per capita calculado usando o pib (vezes um bilhão pra ficar correto) / população
    c.pib_per_capita = (c.pib * 1000000000) / c.populacao;
    // retorna a carta com esses valores formatados (o que significa que eu só posso chamar essa função após declarar população, area e pib.)
    return c;
}

// Função para comparar as cartas com base em um atributo e exibir o resultado no formato exigido.
void comparar(struct Carta carta1, struct Carta carta2, char atributo[20]) {
    int vencedor; // 1 para carta1, 2 para carta2

    printf("Comparação de cartas (Atributo: %s):\n\n", atributo);

    // Estrutura condicional para tratar cada atributo, exibir seus valores e determinar o vencedor.
    if (strcmp(atributo, "populacao") == 0) {
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
        vencedor = (carta1.populacao > carta2.populacao) ? 1 : 2;
    } else if (strcmp(atributo, "area") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.area);
        vencedor = (carta1.area > carta2.area) ? 1 : 2;
    } else if (strcmp(atributo, "pib") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib);
        vencedor = (carta1.pib > carta2.pib) ? 1 : 2;
    } else if (strcmp(atributo, "pontos_turisticos") == 0) {
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.pontos_turisticos);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.pontos_turisticos);
        vencedor = (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 2;
    } else if (strcmp(atributo, "dens_populacional") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.dens_populacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.dens_populacional);
        vencedor = (carta1.dens_populacional < carta2.dens_populacional) ? 1 : 2; // Menor vence
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
        vencedor = (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2;
    } else {
        printf("Atributo inválido.\n");
        return;
    }

    printf("\n");

    // Exibe o resultado final da comparação
    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    }
}

int main(){
   
    // declaramos as duas cartas
    struct Carta carta1, carta2;

    // strcpy é usado pra adicionar uma string de maneira simplificada à variavel
    strcpy(carta1.estado, "SP");
    strcpy(carta1.cidade, "São Bernardo Do Campo");
    strcpy(carta1.codigo, "01");
    // sprintf é usado como "template literal" em C juntando as strings de estado com codigo
    sprintf(carta1.cod_estado, "%s%s", carta1.estado, carta1.codigo);
    carta1.populacao = 840499;
    carta1.pontos_turisticos = 35;
    carta1.area = 409.5;
    carta1.pib = 58.2;

    strcpy(carta2.estado, "RS");
    strcpy(carta2.cidade, "Porto Alegre");
    strcpy(carta2.codigo, "02");
    sprintf(carta2.cod_estado, "%s%s", carta2.estado, carta2.codigo);
    carta2.populacao = 1332845;
    carta2.pontos_turisticos = 38;
    carta2.area = 495.3;
    carta2.pib = 104.7;

    // após darmos valores à população, area, pib, aplicamos o calculo de densidade populacional e pib per capita (melhor do que ter que aplicar a conta de novo e de novo varias vezes)
    carta1 = calcularPropriedades(carta1);
    carta2 = calcularPropriedades(carta2);

    // declaramos atributo que vai receber uma string que vai representar um dos atributos
    char atributo[20];
    strcpy(atributo, "pib_per_capita");
    // executamos a função comparar e passamos as duas cartas e um atributo hardcoded de nossa escolha como parametros.
    comparar(carta1, carta2, atributo);

    return 0;
}
