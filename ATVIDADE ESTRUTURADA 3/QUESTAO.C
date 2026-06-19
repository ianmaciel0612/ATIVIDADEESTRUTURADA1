#include <stdio.h>

/* Struct para armazenar os dados dos funcionarios */
struct Funcionario {
    int codigo;
    char nome[100];
    float salario;
};

/* Funcao para cadastrar os funcionarios */
void cadastrarFuncionarios(struct Funcionario funcionarios[], int n) {

    int i;

    for(i = 0; i < n; i++) {

        printf("\n--- Funcionario %d ---\n", i + 1);

        printf("Digite o codigo: ");
        scanf("%d", &funcionarios[i].codigo);

        /* Espaco antes do scanf para evitar problemas com o ENTER */
        printf("Digite o nome: ");
        scanf(" %[^\n]", funcionarios[i].nome);

        printf("Digite o salario: ");
        scanf("%f", &funcionarios[i].salario);
    }
}

/* Funcao que calcula a media salarial e mostra quem ganha acima dela */
void imprimirAcimaMedia(struct Funcionario funcionarios[], int n) {

    int i;
    float soma = 0;
    float media;

    /* Somando todos os salarios */
    for(i = 0; i < n; i++) {
        soma += funcionarios[i].salario;
    }

    media = soma / n;

    printf("\nMedia salarial da empresa: %.2f\n", media);

    printf("\nFuncionarios que recebem acima da media:\n");

    /* Verificando quais funcionarios recebem acima da media */
    for(i = 0; i < n; i++) {

        if(funcionarios[i].salario > media) {

            printf("\nNome: %s", funcionarios[i].nome);
            printf("\nSalario: %.2f\n", funcionarios[i].salario);
        }
    }
}

int main() {

    struct Funcionario funcionarios[50];
    int n;

    /* Garantindo que a quantidade informada esteja entre 1 e 50 */
    do {

        printf("Quantos funcionarios deseja cadastrar (1 a 50)? ");
        scanf("%d", &n);

    } while(n < 1 || n > 50);

    cadastrarFuncionarios(funcionarios, n);

    imprimirAcimaMedia(funcionarios, n);

    return 0;
}