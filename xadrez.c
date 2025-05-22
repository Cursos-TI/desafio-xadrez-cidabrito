#include <stdio.h>
#include <string.h>

struct Carta {
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

struct Carta cadastrarCarta(int numero) {
    struct Carta c;

    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Código: ");
    scanf("%s", c.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c.nome);

    printf("População: ");
    scanf("%d", &c.populacao);

    printf("Área (km²): ");
    scanf("%f", &c.area);

    printf("PIB (em milhões): ");
    scanf("%f", &c.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    c.densidade = c.populacao / c.area;

    return c;
}

void exibirCarta(struct Carta c) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Código: %s\n", c.codigo);
    printf("Nome: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f milhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
}

void comparar(struct Carta c1, struct Carta c2, char atributo[]) {
    printf("\n--- Comparando atributo: %s ---\n", atributo);

    if (strcmp(atributo, "populacao") == 0) {
        if (c1.populacao > c2.populacao) printf("Vencedora: %s\n", c1.nome);
        else if (c2.populacao > c1.populacao) printf("Vencedora: %s\n", c2.nome);
        else printf("Empate!\n");
    } else if (strcmp(atributo, "area") == 0) {
        if (c1.area > c2.area) printf("Vencedora: %s\n", c1.nome);
        else if (c2.area > c1.area) printf("Vencedora: %s\n", c2.nome);
        else printf("Empate!\n");
    } else if (strcmp(atributo, "pib") == 0) {
        if (c1.pib > c2.pib) printf("Vencedora: %s\n", c1.nome);
        else if (c2.pib > c1.pib) printf("Vencedora: %s\n", c2.nome);
        else printf("Empate!\n");
    } else if (strcmp(atributo, "pontos_turisticos") == 0) {
        if (c1.pontos_turisticos > c2.pontos_turisticos) printf("Vencedora: %s\n", c1.nome);
        else if (c2.pontos_turisticos > c1.pontos_turisticos) printf("Vencedora: %s\n", c2.nome);
        else printf("Empate!\n");
    } else if (strcmp(atributo, "densidade") == 0) {
        if (c1.densidade < c2.densidade) printf("Vencedora: %s\n", c1.nome);
        else if (c2.densidade < c1.densidade) printf("Vencedora: %s\n", c2.nome);
        else printf("Empate!\n");
    } else {
        printf("Atributo inválido.\n");
    }
}

int main() {
    struct Carta carta1 = cadastrarCarta(1);
    struct Carta carta2 = cadastrarCarta(2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    char atributo[20];
    printf("\nAtributos disponíveis: populacao, area, pib, pontos_turisticos, densidade\n");
    printf("Digite o atributo para comparar: ");
    scanf("%s", atributo);

    comparar(carta1, carta2, atributo);

    return 0;
}g