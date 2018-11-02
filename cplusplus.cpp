/* # campominado
projeto de Linguagem de Programação (2018.2) */


#include <iostream>
#include <cstring>
#define MAX_TAM 40

using namespace std;

void imprimeCampo(char Campo_Minado[MAX_TAM][MAX_TAM], int linha, int coluna,int opcao_INI, int opcao_JOGO);
int telaInicio(int opcao_INI,int opcao_JOGO);

int main(){
    char Campo_Minado[MAX_TAM][MAX_TAM];
    int linha, coluna, opcao_INI, opcao_JOGO;
    imprimeCampo(Campo_Minado,linha,coluna,opcao_INI, opcao_JOGO);
    return 0;
}


int telaInicio(int opcao_INI, int opcao_JOGO){
    cout<<"• Novo jogo[1] "<<endl<<"• Melhores Tempos[2] "<<endl<<"• Sair[3] "<<endl;
    cin>>opcao_INI;
    if(opcao_INI==1){
    cout<<"• Jogo Iniciante[1]"<<endl<<"• Jogo Intermediário[2]"<<endl<<"• Jogo Personalizado[3]"<<endl<<"• Voltar[4]"<<endl;
    cin>>opcao_JOGO;
    }
    return opcao_JOGO;
}


void imprimeCampo(char Campo_Minado[MAX_TAM][MAX_TAM], int linha, int coluna,int opcao_INI, int opcao_JOGO){
    int toption = telaInicio(opcao_INI,opcao_JOGO);
    if(toption == 1){
        linha = 8;
        coluna = 8;
    }
    else if(toption == 2){
        linha = 16;
        coluna = 16;
    }
    cout<<"      ";
    for(int i = 0; i < linha; i++){
        cout<<i+1<<" ";
    }
    cout<<endl;
    for(int i = 0; i < linha; i++){
        if(i < 10){
            cout<<i+1<<"     ";
        }
        else{
            cout<<i+1<<"    ";
        }
        for(int j = 0; j < coluna; j++){
            Campo_Minado[i][j] = '.';
            cout<<Campo_Minado[i][j]<<" ";
        }
        cout<<endl;
    }
}
