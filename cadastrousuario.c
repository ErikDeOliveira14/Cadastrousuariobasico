#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nome[10], sobrenome[20];
int retornoSenha, retornoEmail;
char senha1[10], senha2[10];
char email1[30],email2[30];
int tentativas;

void nomeUsuario();
void emailUsuario();
void senhaUsuario();

int main(){
    printf("\t**************\n");
    printf("   ***CADASTRO DE USUARIO***\n");
    printf("\t**************\n");
    nomeUsuario();
    emailUsuario();
    senhaUsuario();

    FILE *f = fopen("Cadastro.txt", "a+"); // abre para escrita

    fprintf(f,"Seu nome e: %s \n", nome);
    fprintf(f,"Seu email e: %s\n", email1);
    fprintf(f,"Sua senha e: %s\n\n", senha1);

    if (f == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fclose(f);
    printf("Arquivo criado com sucesso!\n");

    system("pause");

    return 0;
}


void nomeUsuario(){
    printf("Digite seu nome: ");
    scanf(" %s", nome);
    getchar();
    printf("Digite seu sobrenome: ");
    fgets(sobrenome, 20,stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    strcat(nome," ");

    strcat(nome, sobrenome);
    return;
}

void emailUsuario(){
    printf("Digite seu email: ");
    scanf("%s", email1);

    printf("Digite seu email novamente: ");
    scanf("%s", email2);

    retornoEmail = strcmp(email1,email2);
}

void senhaUsuario(){
    for (tentativas = 1; tentativas <= 3; tentativas++)
    {
        printf("Digite sua senha: ");
        scanf(" %s", senha1);
        getchar();
        printf("Digite sua senha novamente: ");
        scanf(" %s", senha2);
        
        retornoSenha = strcmp(senha1,senha2);

        if (retornoSenha == 0)
    {  
        printf("Cadastro concluido\n\n");
        break; 
    } 
        else
    {
    printf("Senhas nao iguais, %d de 3 tentativas\n", tentativas);
    }

    }

    if (retornoSenha != 0)
    {
        printf("Numero maximo de tentativas excedido, tente cadastrar mais tarde\n");
    }
}