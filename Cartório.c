#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //função responsável por cadastrar os usuarios no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo, e w significa escreve
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //adicona a virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //função que adicona o nome do usuario 
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //adicona o nome do usuario no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //adicona a virgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //função que adicona o sobrenome do usuario 
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //adicona o sobrenome do usuario no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //adicona a virgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //função que adicona o cargo do usuario 
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //adicona o cargo do usuario no arquivo
	fclose(file);
	
	system("pause");
	
}

int consulta() //função responsável por consultar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //abre o arquivo 
	file = fopen(cpf, "r"); //ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); //codigo de erro
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário!\n"); //apresentando as informações do usuario
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");
	}
	
	system("pause"); 

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuario
	scanf("%s",cpf); //%s refere-se a string
	remove(cpf);
	
	FILE *file; //abre o arquivo
	file = fopen(cpf,"r"); //ler o arquivo
	fclose(file); //fecha o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n"); //mensagem apos o deletar
		system("pause"); //%s refere-se a string
	}
	
}

int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela	

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");	//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: 
			printf("Essa opção não está disponível!\n"""); //codigo de erro
			system("pause");
			break;
						
		} //fim da seleção
	
	}
		
}
