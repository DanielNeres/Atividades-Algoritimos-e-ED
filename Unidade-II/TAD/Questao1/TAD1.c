#include <stdio.h>
#include <stdlib.h>
#include "TAD1.h"

struct ingresso
{
	float preco;
	char local[60];
	char atracao[60];
};

void menu()
{
	int escolhamenu, MaxIngresso, QuantidadeIngresso = 0, Menu = 0, j, contador;
	float valor;
	printf("digite a quantidade maxima de ingressos\n");
	scanf("%i", &MaxIngresso);
	Ingressos *i = (Ingressos *)malloc(sizeof(Ingressos) * MaxIngresso);
	if (i == NULL)
	{
		exit(1);
	}
	system("cls");
	do
	{
		printf("MENU\n");
		printf("1. preencher informacoes do ingresso\n");
		printf("2. imprimir informacoes do ingresso\n");
		printf("3. mudar preco dos ingressos\n");
		printf("4. imprecao do Ingresso com maior e menor preco\n");
		printf("escolha o numero de uma das opicoes acima\n");

		scanf("%i", &escolhamenu);
		switch (escolhamenu)
		{
		case 1:
			if (QuantidadeIngresso == MaxIngresso)
			{
				system("cls");
				printf("quantidade maxima de ingressos atingida\n\n");
				Menu = 1;
				break;
			}
			system("cls");
			preencher(&i[QuantidadeIngresso]);
			QuantidadeIngresso++;
			Menu = RetornarMenu();
			break;
		case 2:
			if (QuantidadeIngresso == 0)
			{
				system("cls");
				printf("nenhum ingresso cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("cls");
			for(contador = 0; contador < QuantidadeIngresso; contador++){
			imprimir(&i[contador]);
			}
			Menu = RetornarMenu();
			break;
		case 3:
			if (QuantidadeIngresso == 0)
			{
				system("cls");
				printf("nenhum ingresso cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("cls");
			printf("digite o novo preco do ingresso\n");
			scanf("%f", &valor);
			alterar_preco(i, valor);
			Menu = RetornarMenu();
			break;
		case 4:
			if (QuantidadeIngresso == 0)
			{
				system("cls");
				printf("nenhum ingresso cadastrado\n\n");
				Menu = 1;
				break;
			}
			system("cls");
			imprimir_menor_maior_preco(QuantidadeIngresso, i);
			Menu = RetornarMenu();
			break;
		default:
			exit(1);
			break;
		}

	} while (Menu == 1);
	free(i);
}

int RetornarMenu()
{
	char retornoMenu;
	printf("caso desejar retornar para o menu digite M, ou digite qualquer tecla para sair\n");
	while (getchar() != '\n');
	retornoMenu = getchar();
	if (retornoMenu == 'M' || retornoMenu == 'm')
	{
		system("cls");
		return 1;
	}
	else
	{
		system("cls");
		return 0;
	}
}

void preencher(Ingressos * i)
	{
		printf("preencha dados do ingresso\n");
		printf("digite o local\n");
		scanf(" %[^\n]", i->local);
		printf("digite a atracao\n");
		scanf(" %[^\n]", i->atracao);
		printf("digite o preco\n");
		scanf("%f", &i->preco);
	}

void imprimir(Ingressos * i)
	{
			printf("local: %s\n", i->local);
			printf("atracao: %s\n", i->atracao);
			printf("preco: R$%.2f\n\n", i->preco);
	}

void alterar_preco(Ingressos * i, float valor){
	    int posicao;
		printf("escolha o ingresso entre os numeros para mudar o preco\n");
		scanf("%d", &posicao);
		i[posicao + 1].preco = valor;

	}

void imprimir_menor_maior_preco(int n, Ingressos * i)
	{
		int j, Maiorpreco = 0, Menorpreco = 0;
		for (j = 1; j < n; j++)
		{
			if (i[j].preco < i[Menorpreco].preco)
			{
				Menorpreco = j;
			}
			if (i[j].preco > i[Maiorpreco].preco)
			{
				Maiorpreco = j;
			}
		}
		printf("%s e a atracao mais barata, com o preco de R$%.2f;\n", i[Menorpreco].atracao, i[Menorpreco].preco);
		printf("%s e a atracao mais cara, com o preco de R$%.2f.\n", i[Maiorpreco].atracao, i[Maiorpreco].preco);
	}