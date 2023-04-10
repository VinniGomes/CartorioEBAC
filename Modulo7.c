#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memo�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel pelo cadastro do usuario
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis/string

	printf("Digite o CPF a ser cadastrado: "); //colentando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //"%a" atualiza��o
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar() //Fun��o responsavel pelas consultar de usuario cadastrados
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF  a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //NULL � algo que n�o existe "Nulo"
	{
		printf("N�o foi possivel localizar o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Fun��o responsavel por deletar usuarios selecionados
{
	char cpf[40];
	
	
	printf("Digite o CPF a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se enconta no sistema.\n");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("####Cart�rio da EBAC####\n\n"); //Inicio do Menu
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do Menu
	
		scanf("%d", &opcao); //armazenando a escolha
	
		system("cls"); //Responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consultar(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por usar o nosso sistema!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispin�vel\n");
			system("pause");
			break;
			//fim da sele��o
	 	}
		
	}
}
