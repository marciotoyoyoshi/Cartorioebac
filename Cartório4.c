#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biclioteca aloca��o de espa�o em mem�ria.
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar dos string

int registro(){ // Fun��o respons�vel por cadastrar os usu�rios no sistema.
	
	// Inicio da cria��o de vari�veis/string	
	char arquivo[40]; // Criar uma vari�vel arquivo do tipo "string" com 40 caracteres (char).
	char cpf[40]; // Criar uma vari�vel cpf do tipo "string" com 40 caracteres (char).
	char nome[40]; // Criar uma vari�vel nome do tipo "string" com 40 caracteres (char).
	char sobrenome[40]; // Criar uma vari�vel sobrenome do tipo "string" com 40 caracteres (char).
	char cargo[40]; // Criar uma vari�vel cargo do tipo "string" com 40 caracteres (char).	
	// Final da cria��o de vari�veis/string
	
	// Cadastro de CPF.
	
	printf("Digite o CPF a ser cadastrado: "); // Pede para inserir CPF.
	scanf("%s", cpf); // Armazena o conjunto de caracteres "string" que foi digitado na vari�vel "cpf".
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores dos string de um para outro (cpf para arquivo). (Nome do Arquivo)
	
	FILE *file; // Acesse a fun��o ja pronta pelo sistema chamado "FILE" e nela crie o arquivo "file". Pode ser tamb�m, "receber comando file" nessa ultima parte para consultar o arquivo "file".
	file = fopen(arquivo, "w"); // Nesse comando, pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo), onde ele � um arquivo "novo" ou "que quer escrever" no arquivo e ele � descrito por write (w).
	fprintf(file, cpf); // Salva ou armazena a vari�vel "cpf" dentro do arquivo "file".
	fclose(file); // Fecha o arquivo "file".
	
	file = fopen(arquivo, "a"); //Pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo) e ele quer "atualizar informa��o" do arquivo e ele � descrito por rewrite/update (a).
	fprintf(file, ","); // Cria ","(virgula) no arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	// Cadastro de Nome.
	
	printf("Digite o nome a ser cadastrado: "); // Pede para inserir nome.
	scanf("%s", nome); // Armazena o conjunto de caracteres "string" que foi digitado na vari�vel "nome".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo) e ele quer "atualizar informa��o" do arquivo e ele � descrito por rewrite/update (a).
	fprintf(file, nome);  // Salva ou armazena a vari�vel "nome" dentro do arquivo "file".
	fclose(file); // Fecha o arquivo "file".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo) e ele quer "atualizar informa��o" do arquivo e ele � descrito por rewrite/update (a).
	fprintf(file, ","); // Cria ","(virgula) no arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	// Cadastro de Sobrenome.
	
	printf("Digite o sobrenome a ser cadastrado: "); // Pede para inserir sobrenome.
	scanf("%s", sobrenome); // Armazena o conjunto de caracteres "string" que foi digitado na vari�vel "sobrenome".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo) e ele quer "atualizar informa��o" do arquivo e ele � descrito por rewrite/update (a).
	fprintf(file, sobrenome); // Salva ou armazena a vari�vel "sobrenome" dentro do arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo) e ele quer "atualizar informa��o" do arquivo e ele � descrito por rewrite/update (a).
	fprintf(file, ","); // Cria ","(virgula) no arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	// Cadastro de Cargo.
	
	printf("Digite o cargo a ser cadastrado: "); // Pede para inserir o cargo.
	scanf("%s", cargo); // Armazena o conjunto de caracteres "string" que foi digitado na vari�vel "cargo".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da vari�vel(arquivo) e ele quer "atualizar informa��o" do arquivo e ele � descrito por rewrite/update (a).
	fprintf(file, cargo); // Salva ou armazena a vari�vel "cargo" dentro do arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	system("pause");
}

int consulta(){ // Fun��o respons�vel por consultar os usu�rios no sistema.
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem.
	
	// Inicio da cria��o de vari�veis/string
	char cpf[40]; // Criar uma vari�vel cpf do tipo "string" com 40 caracteres (char).
	char conteudo[200]; // Criar uma vari�vel conteudo do tipo "string" com 200 caracteres (char).
	// Final da cria��o de vari�veis/string
	
	// Consulta de dados.
	
	printf("Digite o CPF a ser consultado: "); // Pede para inserir CPF.
	scanf("%s", cpf); // Armazena o conjunto de caracteres "string" que foi digitado na vari�vel "cpf".
	
	FILE *file; // Acesse a fun��o ja pronta pelo sistema chamado "FILE" e consulte o arquivo "file"
	file = fopen(cpf, "r"); //Pede para o "file" abrir o arquivo "cpf", e ele quer "ler" o arquivo.  Ele � descrito por read (r).
	
	if(file == NULL){ // NULL = nulo/n�o achar.
		printf("N�o foi possivel abrir o arquivo, o arquivo n�o foi localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){  // "fgets -> busca do arquivo" fgets(char (x), m�ximo de tamanho vari�vel do char (x), arquivo de restri��o (quantas vezes precisa ler o arquivo que varia pelo m�ximo de tamanho do vari�vel do char (x)). Ou seja nesse caso, ele est� salvando na vari�vel "conteudo" na string, os 200 caracteres que est�o dentro do arquivo "file".
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); // Imprime para o usu�rio a string ou conjunto de caracteres que esta dentro do "conteudo".
		printf("\n\n");
	}
	
	system ("pause");

}

int deletar(){ // Fun��o respons�vel por deletar os usu�rios no sistema.
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem.
	
	// Inicio da cria��o de vari�veis/string
	char cpf[40]; // Criar uma vari�vel cpf do tipo "string" com 40 caracteres (char).
	// Final da cria��o de vari�veis/string
	
	// Deletar os dados.
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Pede para inserir CPF.
	scanf("%s", cpf); // Armazena o conjunto de caracteres "string" que foi digitado na vari�vel "cpf".
	
	remove(cpf); // Deleta o arquivo com nome ou valor(n�mero) igual a  que tiver no "cpf".
	
	FILE *file; // Acesse a fun��o ja pronta pelo sistema chamado "FILE" e consulte o arquivo "file"
	file = fopen(cpf, "r"); //Pede para o "file" abrir o arquivo "cpf", e ele quer "ler" o arquivo.  Ele � descrito por read (r).
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("Pause");
	}
}

int main (){
	
	int opcao=0; // Definindo vari�veis.
	int x=1;
	
	for(x=1;x=1;){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
		printf("\t### Cart�rio da EBAC ###\n\n"); // Inicio do menu.
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio.
	
		system("cls"); // Respons�vel por limpar a tela.
	
		switch(opcao){ // Inicio da sele��o do menu.
			case 1:
				registro(); // Chamada da fun��o "registro".
				break;
			case 2:
				consulta(); // Chamada da fun��o "consulta".
				break;
			case 3:
				deletar(); // Chamada da fun��o "deletar".
				break;
			default:
				printf("Essa op��o n�o est� disponivel.\n");
				system("pause");
				break;
		} // Fim da sele��o do menu.
	}
}
