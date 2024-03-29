#include <stdio.h>
#include "TAD2.h"

struct funcionario
{
    char Funcional[3];
    char Nome[60];
    char Departamento;
    float Salario;
};

void copia_dados(FILE *fl, int n, Funcionario **pessoal)
{
    fprintf(fl, "Funcional\tNome\tDepartamento\tSalario\n");

    int i;
    for (i = 0; i < n; i++)
    {

        printf("Digite os dados do Funcionario %d\n\n", i + 1);

        printf("Digite o funcional do Funcionario: \t");
        scanf(" %[^\n]", pessoal[i]->Funcional);
        fprintf(fl, "%[^\n]", pessoal[i]->Funcional);

        printf("Digite o nome do Funcionario: \t");
        scanf(" %[^\n]", pessoal[i]->Nome);
        fprintf(fl, "\t%[^\n]", pessoal[i]->Nome);

        printf("Digite o Departamento do Funcionario: \t");
        scanf(" %c", &pessoal[i]->Departamento);
        pessoal[i]->Departamento = toupper(pessoal[i]->Departamento);
        fprintf(fl, "\t%c", pessoal[i]->Departamento);

        printf("Digite o salario do Funcionario: \t");
        scanf(" %f", &pessoal[i]->Salario);
        fprintf(fl, "\t%.2f\n", pessoal[i]->Salario);
    }
    fclose(fl);
}

void imprime_folha_pagamento(int n, Funcionario **pessoal, char depto)
{

    int i;
    float totalfolha;
    printf("Departamento %c\n", depto);
    printf("Funcional\tNome\tDepartamento\tSalario\n");
    for (i = 0; i < n; i++)
    {
        if (depto == pessoal[i]->Departamento)
        {
            printf("%s \t %s \t %c \t %.2f\n", pessoal[i]->Funcional, pessoal[i]->Nome, pessoal[i]->Departamento, pessoal[i]->Salario);
        }
    }
    for (i = 0; i < n; i++){
        totalfolha += pessoal[i]->Salario;
    }
    printf("Total folha de pagamento = %.2f\n\n", totalfolha);
}