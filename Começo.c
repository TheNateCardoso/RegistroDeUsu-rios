#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca que cuida das strings

int registro() //criação da função registro
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	//criando as variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim d criação de variáveis
	
	printf("Insira o CPF que deseja registrar: "); // o que mostra pro usuário
	scanf("%s", cpf); //armazenar as strings inseridas pelo usuário
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria arquivo
	file=fopen(arquivo, "w");  //abre o arquivo
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecho o arquivo
	
	file=fopen(arquivo, "a"); // coloca o "a" pra atualizar o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Insira o nome que deseja registrar: ");
	scanf("%s", nome);
	file=fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Insira o sobrenome que deseja registrar: ");
	scanf("%s", sobrenome);
	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Insira o cargo que deseja registrar: ");
	scanf("%s", cargo);
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //tem que ter pra ele poder ler a mensagem
}

int consulta() //criação da função consulta
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	//criação de variáveis
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis
	
	printf("Insira o CPF que deseja consultar:");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r"); //vamos ler o arquivo
	
	if(file==NULL) //"se o arquivo inserido for igual a nulo"
	{
		printf("CPF não cadastrado.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nTemos as seguintes informações: ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
}

int delecao() //criação da função deleção
{
	char cpf[40];
	
	printf("Insira o CPF que quer deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //cria arquivo
	file=fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("CPF não encontrado. \n");
		system("pause");
	}
}

int main() //sempre a primeira função a aparecer mesmo que não seja a primeira escrita aqui
{
	int opcao=0; //definindo variáveis
	int loop=1; //criei o loop pra voltar sempre pra cá
	
	for(loop=1;loop=1;) // abri o loop
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo idioma
		
		printf("\t---> Banco de Alunos EBAC\n\n"); //início do menu
		printf("\tO quê vamos fazer?\n\n");
		printf("\t\t1- Registrar aluno\n");
		printf("\t\t2- Consultar aluno\n");
		printf("\t\t3- Deletar aluno\n\n");
		printf("\t\t4- Sair\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando escolha do usuário
		
		system("cls"); // aqui vai limpar a tela, pra não ficar feio
		
		switch(opcao) //abri a função de escolha
		{
			case 1: //atribuí o numero 1
			registro(); //chamei a função registro
			break; //fechei a relação
			
			case 2: //atribuí o numero 2
			consulta(); //chamei a função consulta
			break; //fechei a relação
			
			case 3: //atribuí o numero 3
			delecao(); //chamei a função deleção
			break; //fechei a relação
			
			case 4:
			printf("Obrigado!");
			return 0;
			
			default: //todo o resto
			printf("Opção inválida.\n");
			system("pause"); 
			break; //fechei a relação
		} //fechei a função de escolha
	} //fechei o loop
}
