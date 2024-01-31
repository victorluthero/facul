#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Pessoa {

    char nome[100];
    char CPF[12];
    int atendimento[1];
   
};

struct Pessoa pessoas[999];
int cont = 0;

void Menu(){

    printf("Bem-vindo ao sistema de atendimento:\n");
    printf("1 - Solicitar atendimento\n");
    printf("2 - Listar atendimentos registrados\n");
    printf("3 - Listar atendimento por setor\n");
    printf("4 - Sair\n");

}
int leropcoes(){

	Menu();
    int p;
    scanf("%d", &p);
    return p;

}
void setor(int *opcSet){
    system("cls");
    printf("Digite uma das opções de atendimento:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa fisica\n");
    printf("4 - Gerente Pessoa juridica\n");
    printf("Digite uma opcao: ");
    fflush(stdin);
    scanf("%d", opcSet);
}
void leratend() {

    printf("Digite uma das opcoes de atendimento:\n");
    printf("1 - Abertura de conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente pessoa fisica\n");
    printf("4 - Gerente pessoa juridica\n");
    fflush(stdin);
    scanf("%d", &pessoas[cont].atendimento[0]);

}
const char* nomeatendimento(int tipoatendimento) {
    switch (tipoatendimento) {
        case 1: return "Abertura de conta";
        case 2: return "Caixa";
        case 3: return "Gerente pessoa fisica";
        case 4: return "Gerente pessoa juridica";
        default: return "Tipo de atendimento desconhecido";
    }
}
void listatend() {
    int l;

    if (cont == 0) {
        printf("Nenhum atendimento registrado.\n");
    } else {
        for (l = 0; l < cont; l++) {
            printf("Nome: %s\nCPF: %s\nTipo de atendimento: %d - %s\n===============================\n", pessoas[l].nome, pessoas[l].CPF, pessoas[l].atendimento[0], nomeatendimento(pessoas[l].atendimento[0]));
        }
    }
}
void listaSet(struct Pessoa pessoas){
        printf("Nome: %s\n", pessoas.nome);
        printf("CPF: %s\n", pessoas.CPF);
        int tipoatendimento = pessoas.atendimento[0];
        printf("Tipo de atendimento - %d %s\n", tipoatendimento, nomeatendimento(tipoatendimento));
        printf("=============================\n");
}

void registro() {

    printf("Opcao 1 - Solicitar atendimento:\n");
    fflush(stdin);
    printf("Digite o seu nome:");
    fflush(stdin);
    gets(pessoas[cont].nome);
    printf("Digite o seu CPF:");
    fflush(stdin);
    scanf("%s", &pessoas[cont].CPF);
    system("cls");

    do {
        
        leratend();
        
        switch (pessoas[cont].atendimento[0]) {
            
            case 1: {
                
                break;

            }
            case 2: {
               
                break;

            }
            case 3: {

                break;

            }
            case 4: {

                break;

            }
           
            default: {
               
                break;

            }
        }
    } while (pessoas[cont].atendimento[0] < 1 || pessoas[cont].atendimento[0] > 4);  

    cont++;

}
void listarPorTipo(int tipodesejado) {
    for (int i = 0; i < cont; i++) {
        if (pessoas[i].atendimento[0] == tipodesejado) {
            listaSet(pessoas[i]);
        }
    }
}

int main (){

    setlocale(LC_ALL, "");
    int opcoes;

    do{

        opcoes = leropcoes();

        switch(opcoes){

                case 1 : {
                    
                    registro();
                    break;

                }
                case 2 : {
                    
                    system("cls");
                    listatend();
					break;
					
                }
                case 3 : {
                
                system("cls");
                int filtrado;
                setor(&filtrado);
                listarPorTipo(filtrado);
				break;
					
				}
				default : {
					
					printf("Opcao invalida\n");
					break;

				}
        	}

    	}while(opcoes != 4);

    return 0;
}