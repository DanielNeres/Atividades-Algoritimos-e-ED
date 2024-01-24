#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float preco;
	char local[30];
	char atracao[30];
} Ingresso;

void menu();
int RetornarMenu();
void preenche(Ingresso *i, int QuantidadeIngresso);
void imprime(Ingresso *i, int QuantidadeIngresso);
void altera_preco(Ingresso *i, float valor, int QuantidadeIngresso);
void imprime_menor_maior_preco(int n, Ingresso * i)

int main()
{
	menu();
	return 0;
}

void menu()
{
	int escolhamenu, MaxIngresso, QuantidadeIngresso = 0, Menu = 0, j;
	float valor;
	printf("digite a quantidade de ingressos maxima\n");
	scanf("%i", &MaxIngresso);
	Ingresso *i = (Ingresso *)malloc(sizeof(Ingresso) * MaxIngresso);
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
			preenche(i, QuantidadeIngresso);
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
			imprime(i, QuantidadeIngresso);
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
			printf("escolha o ingresso entre os numeros ");
			for (j = 1; j <= QuantidadeIngresso; j++)
			{
				printf("%d ", j);
			}
			printf("para mudar o preco\n");
			scanf("%f", &valor);
			printf("digite o novo preco do ingresso\n");
			scanf("%f", &valor);
			altera_preco(i, valor, j);
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
			imprime_menor_maior_preco(i, QuantidadeIngresso);
			Menu = RetornarMenu();
			break;
		default:
			exit(1);
			break;
		}

	} while (Menu == 1);
}

int RetornarMenu()
{
	char retornoMenu;
	printf("caso desejar retornar para o menu digite M, ou digite qualquer tecla para sair\n");
	while (getchar() != '\n')
		;
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

	void preenche(Ingresso * i, int QuantidadeIngresso)
	{
		printf("preencha dados do ingresso %d\n", QuantidadeIngresso + 1);
		printf("digite o local\n");
		scanf(" %[^\n]", i[QuantidadeIngresso].local);
		printf("digite a atracao\n");
		scanf(" %[^\n]", i[QuantidadeIngresso].atracao);
		printf("digite o preco\n");
		scanf("%f", &i[QuantidadeIngresso].preco);
	}

	void imprime(Ingresso * i, int QuantidadeIngresso)
	{
		int j;
		for (j = 0; j < QuantidadeIngresso; j++)
		{
			printf("dados do ingresso %d\n", i + 1);
			printf("local: %s\n", i[j].local);
			printf("atracao: %s\n", i[j].atracao);
			printf("preco: R$%f\n\n", i[j].preco);
		}
	}

	void altera_preco(Ingresso * i, float valor, int j)
	{
		i[j].preco = valor;
	}

	void imprime_menor_maior_preco(int n, Ingresso * i)
	{
		int i, Maiorpreco = 0, Menorpreco = 0;
		for (i = 1; i < n; i++)
		{
			if (i[i].preco < i[Menorpreco].preco)
			{
				Menorpreco = i;
			}
			if (i[i].preco > i[Maiorpreco].preco)
			{
				Maiorpreco = i;
			}
		}
		printf("%s e a atracao mais barata, com o preco de R$%f;\n", i[Menorpreco].atracao, i[Menorpreco].preco);
		printf("%s e a atracao mais cara, com o preco de R$%f.\n", i[Maiorpreco].atracao, i[Maiorpreco].preco);
	}