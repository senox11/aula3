#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int matricula;
    char alturaStr[32], pesoStr[32];
    float altura, peso;

    printf("Qual sua matrícula?\n");
    if (scanf("%d", &matricula) != 1) {
        printf("Entrada inválida para matrícula.\n");
        return 1;
    }

    // limpa o \n restante (evita pular próximas leituras em alguns ambientes)
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    printf("Qual sua altura?\n");
    if (scanf("%31s", alturaStr) != 1) {
        printf("Entrada inválida para altura.\n");
        return 1;
    }
    for (int i = 0; alturaStr[i] != '\0'; i++)
        if (alturaStr[i] == ',') alturaStr[i] = '.';
    altura = strtof(alturaStr, NULL);

    printf("Qual sua massa corporal?\n");
    if (scanf("%31s", pesoStr) != 1) {
        printf("Entrada inválida para peso.\n");
        return 1;
    }
    for (int i = 0; pesoStr[i] != '\0'; i++)
        if (pesoStr[i] == ',') pesoStr[i] = '.';
    peso = strtof(pesoStr, NULL);

    printf("\nDisciplina: Algoritmo de programação\n");
    printf("Turma: GPE172024\n");
    printf("Nome: Miguel Sena Cardoso\n");
    printf("Matrícula: %d\n", matricula);
    printf("Altura: %.2f m\n", altura);   // 2 casas
    printf("Peso: %.3f kg\n", peso);      // 3 casas

    return 0;
}

