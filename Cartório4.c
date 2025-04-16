#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biclioteca alocação de espaço em memória.
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar dos string

int registro(){ // Função responsável por cadastrar os usuários no sistema.
	
	// Inicio da criação de variáveis/string	
	char arquivo[40]; // Criar uma variável arquivo do tipo "string" com 40 caracteres (char).
	char cpf[40]; // Criar uma variável cpf do tipo "string" com 40 caracteres (char).
	char nome[40]; // Criar uma variável nome do tipo "string" com 40 caracteres (char).
	char sobrenome[40]; // Criar uma variável sobrenome do tipo "string" com 40 caracteres (char).
	char cargo[40]; // Criar uma variável cargo do tipo "string" com 40 caracteres (char).	
	// Final da criação de variáveis/string
	
	// Cadastro de CPF.
	
	printf("Digite o CPF a ser cadastrado: "); // Pede para inserir CPF.
	scanf("%s", cpf); // Armazena o conjunto de caracteres "string" que foi digitado na variável "cpf".
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores dos string de um para outro (cpf para arquivo). (Nome do Arquivo)
	
	FILE *file; // Acesse a função ja pronta pelo sistema chamado "FILE" e nela crie o arquivo "file". Pode ser também, "receber comando file" nessa ultima parte para consultar o arquivo "file".
	file = fopen(arquivo, "w"); // Nesse comando, pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo), onde ele é um arquivo "novo" ou "que quer escrever" no arquivo e ele é descrito por write (w).
	fprintf(file, cpf); // Salva ou armazena a variável "cpf" dentro do arquivo "file".
	fclose(file); // Fecha o arquivo "file".
	
	file = fopen(arquivo, "a"); //Pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo) e ele quer "atualizar informação" do arquivo e ele é descrito por rewrite/update (a).
	fprintf(file, ","); // Cria ","(virgula) no arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	// Cadastro de Nome.
	
	printf("Digite o nome a ser cadastrado: "); // Pede para inserir nome.
	scanf("%s", nome); // Armazena o conjunto de caracteres "string" que foi digitado na variável "nome".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo) e ele quer "atualizar informação" do arquivo e ele é descrito por rewrite/update (a).
	fprintf(file, nome);  // Salva ou armazena a variável "nome" dentro do arquivo "file".
	fclose(file); // Fecha o arquivo "file".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo) e ele quer "atualizar informação" do arquivo e ele é descrito por rewrite/update (a).
	fprintf(file, ","); // Cria ","(virgula) no arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	// Cadastro de Sobrenome.
	
	printf("Digite o sobrenome a ser cadastrado: "); // Pede para inserir sobrenome.
	scanf("%s", sobrenome); // Armazena o conjunto de caracteres "string" que foi digitado na variável "sobrenome".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo) e ele quer "atualizar informação" do arquivo e ele é descrito por rewrite/update (a).
	fprintf(file, sobrenome); // Salva ou armazena a variável "sobrenome" dentro do arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo) e ele quer "atualizar informação" do arquivo e ele é descrito por rewrite/update (a).
	fprintf(file, ","); // Cria ","(virgula) no arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	// Cadastro de Cargo.
	
	printf("Digite o cargo a ser cadastrado: "); // Pede para inserir o cargo.
	scanf("%s", cargo); // Armazena o conjunto de caracteres "string" que foi digitado na variável "cargo".
	
	file = fopen(arquivo, "a"); // Pede para o "file" abrir o arquivo, com character que tiver dentro da variável(arquivo) e ele quer "atualizar informação" do arquivo e ele é descrito por rewrite/update (a).
	fprintf(file, cargo); // Salva ou armazena a variável "cargo" dentro do arquivo "file".
	fclose(file); //Fecha o arquivo "file".
	
	system("pause");
}

int consulta(){ // Função responsável por consultar os usuários no sistema.
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem.
	
	// Inicio da criação de variáveis/string
	char cpf[40]; // Criar uma variável cpf do tipo "string" com 40 caracteres (char).
	char conteudo[200]; // Criar uma variável conteudo do tipo "string" com 200 caracteres (char).
	// Final da criação de variáveis/string
	
	// Consulta de dados.
	
	printf("Digite o CPF a ser consultado: "); // Pede para inserir CPF.
	scanf("%s", cpf); // Armazena o conjunto de caracteres "string" que foi digitado na variável "cpf".
	
	FILE *file; // Acesse a função ja pronta pelo sistema chamado "FILE" e consulte o arquivo "file"
	file = fopen(cpf, "r"); //Pede para o "file" abrir o arquivo "cpf", e ele quer "ler" o arquivo.  Ele é descrito por read (r).
	
	if(file == NULL){ // NULL = nulo/não achar.
		printf("Não foi possivel abrir o arquivo, o arquivo não foi localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){  // "fgets -> busca do arquivo" fgets(char (x), máximo de tamanho variável do char (x), arquivo de restrição (quantas vezes precisa ler o arquivo que varia pelo máximo de tamanho do variável do char (x)). Ou seja nesse caso, ele está salvando na variável "conteudo" na string, os 200 caracteres que estão dentro do arquivo "file".
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); // Imprime para o usuário a string ou conjunto de caracteres que esta dentro do "conteudo".
		printf("\n\n");
	}
	
	system ("pause");

}

int deletar(){ // Função responsável por deletar os usuários no sistema.
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem.
	
	// Inicio da criação de variáveis/string
	char cpf[40]; // Criar uma variável cpf do tipo "string" com 40 caracteres (char).
	// Final da criação de variáveis/string
	
	// Deletar os dados.
	
	printf("Digite o CPF do usuário a ser deletado: "); // Pede para inserir CPF.
	scanf("%s", cpf); // Armazena o conjunto de caracteres "string" que foi digitado na variável "cpf".
	
	remove(cpf); // Deleta o arquivo com nome ou valor(número) igual a  que tiver no "cpf".
	
	FILE *file; // Acesse a função ja pronta pelo sistema chamado "FILE" e consulte o arquivo "file"
	file = fopen(cpf, "r"); //Pede para o "file" abrir o arquivo "cpf", e ele quer "ler" o arquivo.  Ele é descrito por read (r).
	
	if(file == NULL){
		printf("O usuário não se encontra no sistema.\n");
		system("Pause");
	}
}

int main (){
	
	int opcao=0; // Definindo variáveis.
	int x=1;
	
	for(x=1;x=1;){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
		printf("\t### Cartório da EBAC ###\n\n"); // Inicio do menu.
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário.
	
		system("cls"); // Responsável por limpar a tela.
	
		switch(opcao){ // Inicio da seleção do menu.
			case 1:
				registro(); // Chamada da função "registro".
				break;
			case 2:
				consulta(); // Chamada da função "consulta".
				break;
			case 3:
				deletar(); // Chamada da função "deletar".
				break;
			default:
				printf("Essa opção não está disponivel.\n");
				system("pause");
				break;
		} // Fim da seleção do menu.
	}
}
