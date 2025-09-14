#include <stdio.h>

double calcular_inss(double salario_bruto) {
    double desconto_inss = 0.0;

    if (salario_bruto <= 1320.00) {
        desconto_inss = salario_bruto * 0.075;
    } else if (salario_bruto <= 2571.29) {
        desconto_inss = salario_bruto * 0.09;
    } else if (salario_bruto <= 3856.94) {
        desconto_inss = salario_bruto * 0.12;
    } else if (salario_bruto <= 7507.49) {
        desconto_inss = salario_bruto * 0.14;
    } else {
        // Teto do INSS
        desconto_inss = 7507.49 * 0.14;
    }

    return desconto_inss;
}

double calcular_ir(double salario_base_ir) {
    double desconto_ir = 0.0;

    if (salario_base_ir <= 1903.98) {
        desconto_ir = 0.0;
    } else if (salario_base_ir <= 2826.65) {
        desconto_ir = salario_base_ir * 0.075;
    } else if (salario_base_ir <= 3751.05) {
        desconto_ir = salario_base_ir * 0.15;
    } else if (salario_base_ir <= 4664.68) {
        desconto_ir = salario_base_ir * 0.225;
    } else {
        desconto_ir = salario_base_ir * 0.275;
    }

    return desconto_ir;
}

int main() {
    double salario_bruto;
    double salario_base_ir;
    double desconto_inss;
    double desconto_ir;
    double salario_liquido;

    printf("Informe o salario bruto do colaborador: R$ ");
    scanf("%lf", &salario_bruto);

    desconto_inss = calcular_inss(salario_bruto);

    salario_base_ir = salario_bruto - desconto_inss;

    desconto_ir = calcular_ir(salario_base_ir);

    salario_liquido = salario_base_ir - desconto_ir;

    printf("\n--- Relatorio de Salario ---\n");
    printf("Salario Bruto       : R$ %.2f\n", salario_bruto);
    printf("Desconto INSS       : R$ %.2f\n", desconto_inss);
    printf("Desconto Imposto IR : R$ %.2f\n", desconto_ir);
    printf("------------------------------\n");
    printf("Salario Liquido     : R$ %.2f\n", salario_liquido);

    return 0;
}
