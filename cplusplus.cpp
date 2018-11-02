/* # campominado
projeto de Linguagem de Programação (2018.2) */


#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 40

using namespace std;

int telaInicial(int inicio, int nivel);
void imprimeCampo(char campo[MAX][MAX], int tamanho, int nivel);
void preencher(char campo[MAX][MAX], int tamanho, int nivel);
void comandos(char campoReal[MAX][MAX], char campo[MAX][MAX],int tamanho, int nivel, int minas);
void resultado(char campoReal[MAX][MAX], campo[MAX][MAX], int comando,  int minas, int tamanho, int nivel, int linha_esc, int coluna_esc);

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

void preencher(char campo[MAX][MAX], int tamanho, int nivel){
    char campoReal[MAX][MAX];
    int minas;
    if(nivel == 1){
        minas = 10;
        for(int i = 0; i = tamanho; i++){
            for(int j = 0; j = tamanho; j++){
                if(minas != 0){
                    campoReal[i][j] = rand()%'y'+'x';
                    minas--;
                }
                else{
                    campoReal[i][j] = 'y';
                }
            }
        }
        minas = 10;
    }
    comandos(campoReal, campo, tamanho, nivel, minas);
}

void comandos(char campoReal[MAX][MAX], char campo[MAX][MAX],int tamanho, int nivel, int minas){
    char comando;
    int linha_esc, coluna_esc;
    
    cout<<"Minas a marcar: "<<minas<<" "<<endl;
    cout<<"D --> Descobrir quadrado "<<endl;
    cout<<"M --> Marcar mina "<<endl;
    cout<<"T --> Talvez mina "<<endl;
    cout<<"L --> Limpar Campo "<<endl;
    cout<<"S --> Sair "<<endl;

    cin>>comando>>linha_esc>>coluna_esc;
    resultado(campoReal, campo, comando,  minas, tamanho, nivel, linha_esc, coluna_esc);
}

void resultado(char campoReal[MAX][MAX], campo[MAX][MAX], int comando,  int minas, int tamanho, int nivel, int linha_esc, int coluna_esc){
    if(comando == 'D'){
        if(campoReal[linha_esc-1][coluna_esc-1] == 'x'){
            cout<<"Você Perdeu";
        }
        else{
        comandos(campoReal, campo, tamanho, nivel, minas);
        }
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
        preencher(campo, tamanho, (tela%10));
    }

    return 0;
}
