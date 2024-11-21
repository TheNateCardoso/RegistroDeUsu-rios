#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca que cuida das strings

int registro() //cria��o da fun��o registro
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	//criando as vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim d cria��o de vari�veis
	
	printf("Insira o CPF que deseja registrar: "); // o que mostra pro usu�rio
	scanf("%s", cpf); //armazenar as strings inseridas pelo usu�rio
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria arquivo
	file=fopen(arquivo, "w");  //abre o arquivo
	fprintf(file, cpf); //salvo o valor da vari�vel
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

int consulta() //cria��o da fun��o consulta
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	//cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis
	
	printf("Insira o CPF que deseja consultar:");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r"); //vamos ler o arquivo
	
	if(file==NULL) //"se o arquivo inserido for igual a nulo"
	{
		printf("CPF n�o cadastrado.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nTemos as seguintes informa��es: ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
}

int delecao() //cria��o da fun��o dele��o
{
	char cpf[40];
	
	printf("Insira o CPF que quer deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //cria arquivo
	file=fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("CPF n�o encontrado. \n");
		system("pause");
	}
}

int main() //sempre a primeira fun��o a aparecer mesmo que n�o seja a primeira escrita aqui
{
	int opcao=0; //definindo vari�veis
	int loop=1; //criei o loop pra voltar sempre pra c�
	
	for(loop=1;loop=1;) // abri o loop
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo idioma
		
		printf("\t---> Banco de Alunos EBAC\n\n"); //in�cio do menu
		printf("\tO qu� vamos fazer?\n\n");
		printf("\t\t1- Registrar aluno\n");
		printf("\t\t2- Consultar aluno\n");
		printf("\t\t3- Deletar aluno\n\n");
		printf("\t\t4- Sair\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando escolha do usu�rio
		
		system("cls"); // aqui vai limpar a tela, pra n�o ficar feio
		
		switch(opcao) //abri a fun��o de escolha
		{
			case 1: //atribu� o numero 1
			registro(); //chamei a fun��o registro
			break; //fechei a rela��o
			
			case 2: //atribu� o numero 2
			consulta(); //chamei a fun��o consulta
			break; //fechei a rela��o
			
			case 3: //atribu� o numero 3
			delecao(); //chamei a fun��o dele��o
			break; //fechei a rela��o
			
			case 4:
			printf("Obrigado!");
			return 0;
			
			default: //todo o resto
			printf("Op��o inv�lida.\n");
			system("pause"); 
			break; //fechei a rela��o
		} //fechei a fun��o de escolha
	} //fechei o loop
}
