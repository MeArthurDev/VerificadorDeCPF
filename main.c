#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

void menu();

void verificaCPF(){
    system("cls");

    char cpf[50];
    int soma = 0;
    int decimoDigito = 0,decimoPrimeiroDigito = 0;

        fflush(stdin);
        printf("Digite o CPF(Apenas números): ");
        gets(cpf);

    //Cálculo do décimo digito do CPF
    int j = 10;
    for(int i=0;i<9;i++){
        if(cpf[i]<'0' || cpf[i]>'9'){
            printf("O cpf não pode conter caracteres!(Pressione qualquer botão)");
            verificaCPF();
        }
        soma += j*(cpf[i]-'0');
        j--;
    }

    int resto = soma % 11;
    if(resto>=2) decimoDigito = 11 - resto;

    //Cálculo do décimo primeiro digito digito do CPF
    soma = 0;
    j = 11;
    for(int i=0;i<10;i++){
        soma += j*(cpf[i]-'0');
        j--;
    }
    resto = soma % 11;
    
    if(resto>=2)decimoPrimeiroDigito = 11 - resto;

    if(decimoDigito == (cpf[9]-'0') && decimoPrimeiroDigito == (cpf[10]-'0')) printf("O cpf é válido! ;)");
    else printf("O cpf não é valido! :(");

    getch();
}

void menu(){
    system("cls");
    int op;
    fflush(stdin);
    printf("Digite 1 para validar um CPF ou 2 para sair: ");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        verificaCPF();
        menu();
        break;
    case 2:
        break;
    default:
        printf("Opção inválida!(Pressione qualquer botão)");
        getch();
        menu();
        break;
    }
}

void main(){
    setlocale(LC_ALL,"Portuguese");
    menu();
}