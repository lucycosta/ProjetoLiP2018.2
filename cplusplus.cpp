/* # campominado
projeto de Linguagem de Programação (2018.2) */


#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 40

using namespace std;

int telaInicial(int inicio, int nivel);
void imprimeCampo(char campo[MAX][MAX], int tamanho, int nivel);

int telaInicial(int inicio, int nivel){
    cout<<"• Novo jogo[1] "<<endl;
    cout<<"• Melhores Tempos[2] "<<endl;
    cout<<"• Sair[3] "<<endl;
    cin>>inicio;

    cout<<"• Jogo Iniciante[1]"<<endl;
    cout<<"• Jogo Intermediário[2]"<<endl;
    cout<<"• Jogo Personalizado[3]"<<endl;
    cout<<"• Voltar[4]"<<endl;
    cin>>nivel;

    return ((inicio*10)+nivel);
}

void imprimeCampo(char campo[MAX][MAX], int tamanho, int nivel){
    cout<<"      ";
    for(int i = 0; i < tamanho; i++){
        cout<<i+1<<" ";
    }
    cout<<endl;

    for(int i = 0; i < tamanho; i++){
        if(i < 10){
            cout<<i+1<<"     ";
        }
        else{
            cout<<i+1<<"    ";
        }

        for(int j = 0; j < tamanho; j++){
            campo[i][j] = '.';
            cout<<campo[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(void){
    char campo[MAX][MAX];
    int tela, inicio, nivel, tamanho;

    tela = telaInicial(inicio, nivel);

    if((tela/10) == 1 && (tela&10) >= 3){
        if((tela%10) == 1){
            tamanho = 8;
        }

        imprimeCampo(campo, tamanho, (tela%10));
    }

    return 0;
}
