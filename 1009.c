#include <stdio.h>

int main() {
    char nome[50];
    double salario, vendas, total;
    scanf("%s %lf %lf", nome, &salario, &vendas);
    total = salario + (vendas * 0.15);
    printf("TOTAL = R$ %.2lf\n", total);
    return 0;
}
