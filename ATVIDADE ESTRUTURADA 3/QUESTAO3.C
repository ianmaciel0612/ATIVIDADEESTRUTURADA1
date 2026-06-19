#include <stdio.h>
#include <string.h>

/* Utilizando a mesma struct da questao anterior */
struct Funcionario {
    int codigo;
    char nome[100];
    float salario;
};

/* Funcao responsavel por aplicar o aumento ao salario */
void aplicarAumento(struct Funcionario *f, float percentual) {

    /* Calculando o novo salario com base no percentual informado */
    f->salario = f->salario + (f->salario * percentual / 100);
}

int main() {

    struct Funcionario funcionario;

    /* Preenchendo alguns dados para teste */
    funcionario.codigo = 1;

    strcpy(funcionario.nome, "Joao");

    funcionario.salario = 3000.00;

    printf("Dados do funcionario\n");
    printf("Codigo: %d\n", funcionario.codigo);
    printf("Nome: %s\n", funcionario.nome);

    printf("\nSalario antes do aumento: %.2f\n", funcionario.salario);

    /* Passando o endereco da struct para a funcao */
    aplicarAumento(&funcionario, 10);

    printf("Salario depois do aumento: %.2f\n", funcionario.salario);

    return 0;
}