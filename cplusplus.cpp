#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#define MAX 40
#define NAME

struct tempos{
    int times = 0;
    char nomes[NAME] = {};
};


using namespace std;

char conversor(int n);
int telaInicial(int inicio, int nivel);
void imprimeCampo(char campo[MAX][MAX], int linha, int coluna, int tempo, tempos t);
void preencher(char campo[MAX][MAX], int linha, int coluna, int nivel, int tempo, tempos t, int minas);
void comandos(char campoReal[MAX][MAX], char campo[MAX][MAX],int linha, int coluna, int nivel, int minas,int tempo, tempos t);
void resultado(char campoReal[MAX][MAX], char campo[MAX][MAX], int comando,  int minas, int linha, int coluna, int nivel, int linha_esc, int coluna_esc,int tempo, tempos t);
void varredura(char campoReal[MAX][MAX], char campo[MAX][MAX], int linha, int coluna, int linha_esc, int coluna_esc);

char conversor(int n){
    int aux;
    aux = n+48;
    if(aux == 48){
        aux = '_';
    }
    return((char)aux);
}

int telaInicial(int inicio, int nivel){
    cout<<"Novo jogo[1] "<<endl;
    cout<<"Melhores Tempos[2] "<<endl;
    cout<<"Sair[3] "<<endl;
    cin>>inicio;

    cout<<"Jogo Iniciante[1]"<<endl;
    cout<<"Jogo Intermediario[2]"<<endl;
    cout<<"Jogo Personalizado[3]"<<endl;
    cout<<"Voltar[4]"<<endl;
    cin>>nivel;

    return ((inicio*10)+nivel);
}

void imprimeCampo(char campo[MAX][MAX], int linha, int coluna, int tempo){
    cout<<"      ";
    for(int i = 0; i < coluna; i++){
        cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<endl;

    for(int i = 0; i < linha; i++){
    	if(i <= 8)
        	cout<<i+1<<"     ";
        else
        	cout<<i+1<<"    ";

        for(int j = 0; j < coluna; j++){
            campo[i][j] = '.';
            cout<<campo[i][j]<<" ";
            if(j >= 8)
            	cout<<" ";
        }
        cout<<endl;
    }
}

void preencher(char campo[MAX][MAX], int linha, int coluna, int nivel, int tempo, tempos t, int minas){
    char campoReal[MAX][MAX];
    int cont;

    srand(time(NULL));
    cout<<endl;

    if(nivel == 1){
        minas = 10;
    }
    else if(nivel == 2){
        minas = 20;
    }
    
    for(int i = 0; i < minas; i++){
        int a = rand()%linha, b = rand()%coluna;
        if(campoReal[a][b] != 'x'){
            campoReal[a][b] = 'x';
        }
        else{
            while(campoReal[a][b] == 'x'){
                a = rand()%linha;
                b = rand()%coluna;
            }
            campoReal[a][b] = 'x';
        }
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(campoReal[i][j] != 'x'){
                cont = 0;

                if(i == 0 && j == 0){
                    if(campoReal[i][j+1] == 'x')
                        cont++;
                    if(campoReal[i+1][j] == 'x')
                        cont++;
                    if(campoReal[i+1][j+1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(i == 0 && j == (coluna-1)){
                    if(campoReal[i][j-1] == 'x')
                        cont++;
                    if(campoReal[i+1][j-1] == 'x')
                        cont++;
                    if(campoReal[i+1][j] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(i == (linha-1) && j == 0){
                    if(campoReal[i-1][j] == 'x')
                        cont++;
                    if(campoReal[i-1][j+1] == 'x')
                        cont++;
                    if(campoReal[i][j+1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(i == (linha-1) && j == (coluna-1)){
                    if(campoReal[i-1][j] == 'x')
                        cont++;
                    if(campoReal[i-1][j-1] == 'x')
                        cont++;
                    if(campoReal[i][j-1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(i == 0 && j > 0 && j < (coluna-1)){
                    if(campoReal[i][j-1] == 'x')
                        cont++;
                    if(campoReal[i][j+1] == 'x')
                        cont++;
                    if(campoReal[i+1][j-1] == 'x')
                        cont++;
                    if(campoReal[i+1][j] == 'x')
                        cont++;
                    if(campoReal[i+1][j+1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(i == (linha-1) && j > 0 && j < (coluna-1)){
                    if(campoReal[i][j-1] == 'x')
                        cont++;
                    if(campoReal[i-1][j-1] == 'x')
                        cont++;
                    if(campoReal[i-1][j] == 'x')
                        cont++;
                    if(campoReal[i-1][j+1] == 'x')
                        cont++;
                    if(campoReal[i][j+1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(j == 0 && i > 0 && i < (linha-1)){
                    if(campoReal[i-1][j] == 'x')
                        cont++;
                    if(campoReal[i-1][j+1] == 'x')
                        cont++;
                    if(campoReal[i][j+1] == 'x')
                        cont++;
                    if(campoReal[i+1][j] == 'x')
                        cont++;
                    if(campoReal[i+1][j+1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else if(j == (coluna-1) && i > 0 && i < (linha-1)){
                    if(campoReal[i-1][j] == 'x')
                        cont++;
                    if(campoReal[i-1][j-1] == 'x')
                        cont++;
                    if(campoReal[i][j-1] == 'x')
                        cont++;
                    if(campoReal[i+1][j] == 'x')
                        cont++;
                    if(campoReal[i+1][j-1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
                else{
                    if(campoReal[i-1][j-1] == 'x')
                        cont++;
                    if(campoReal[i-1][j] == 'x')
                        cont++;
                    if(campoReal[i-1][j+1] == 'x')
                        cont++;
                    if(campoReal[i][j-1] == 'x')
                        cont++;
                    if(campoReal[i][j+1] == 'x')
                        cont++;
                    if(campoReal[i+1][j-1] == 'x')
                        cont++;
                    if(campoReal[i+1][j] == 'x')
                        cont++;
                    if(campoReal[i+1][j+1] == 'x')
                        cont++;

                    campoReal[i][j] = conversor(cont);
                    cont = 0;
                }
            }
        }
        campo[i][coluna] = '\0';
    }

    comandos(campoReal, campo, linha, coluna, nivel, minas, tempo, t);
}

void comandos(char campoReal[MAX][MAX], char campo[MAX][MAX],int linha, int coluna, int nivel, int minas, int tempo, tempos t){
    char comando;
    int linha_esc, coluna_esc;

    cout<<"Minas a marcar: "<<minas<<" "<<endl;
    cout<<"D --> Descobrir quadrado "<<endl;
    cout<<"M --> Marcar mina "<<endl;
    cout<<"T --> Talvez mina "<<endl;
    cout<<"L --> Limpar Campo "<<endl;
    cout<<"S --> Sair "<<endl;

    cin>>comando>>linha_esc>>coluna_esc;
    resultado(campoReal, campo, comando,  minas, linha, coluna, nivel, linha_esc, coluna_esc, tempo, t);
}

void resultado(char campoReal[MAX][MAX], char campo[MAX][MAX], int comando,  int minas, int linha, int coluna, int nivel, int linha_esc, int coluna_esc, int tempo, tempos t){
    int cont_minas = 0, Melhor = time(NULL)-tempo;
    if(comando == 'D' || comando =='M' || comando == '?'){
        if(campoReal[linha_esc-1][coluna_esc-1] == 'x' && comando == 'D'){
            cout<<"Voce Perdeu";
        }
        else{
            if(comando == 'M'){
                campo[linha_esc-1][coluna_esc-1] = 'M';
            }
            else if(comando == '?'){
                campo[linha_esc-1][coluna_esc-1] = '?';
            }
            
			cout<<"      ";
            for(int i = 0; i < coluna; i++){
                cout<<i+1<<" ";
            }

            cout<<"     Tempo atual: "<<time(NULL)-tempo<<" segundo(s)";
               cout<<endl;
               cout<<endl;

            for(int i = 0; i < linha; i++){
            	if(i <= 8)
                	cout<<i+1<<"     ";
                else
                	cout<<i+1<<"    ";

                for(int j = 0; j < coluna; j++){
                    if(campo[i][j]=='M'){
                        cont_minas++;
                        minas=10-cont_minas;
                    }
                    if(i == (linha_esc-1) && j == (coluna_esc-1) && campo[i][j] != 'M' && campo[i][j] != '?'){
                        campo[i][j] = campoReal[linha_esc-1][coluna_esc-1];
                        if(campo[i][j] == '_'){
                            varredura(campoReal, campo, linha, coluna, linha_esc, coluna_esc);
                        }
                           cout<<campo[i][j]<<" ";
                           if(j >= 8)
								cout<<" ";
                    }
                    else{
                        cout<<campo[i][j]<<" ";
                        if(j >= 8)
                        	cout<<" ";
                    }
                }
                cout<<endl;
            }
        comandos(campoReal, campo, linha, coluna, nivel, minas, tempo, t);
        }
    }
}

void varredura(char campoReal[MAX][MAX], char campo[MAX][MAX], int linha, int coluna, int linha_esc, int coluna_esc){
    int i = (linha_esc-1), j = (coluna_esc-1);
    if(i == 0 && j == 0){
        campo[i][j+1] = campoReal[i][j+1];

        campo[i+1][j] = campoReal[i+1][j];

        campo[i+1][j+1] = campoReal[i+1][j+1];
    }
    else if(i == 0 && j == (coluna-1)){
        campo[i][j-1] = campoReal[i][j-1];

        campo[i+1][j-1] = campoReal[i+1][j-1];

        campo[i+1][j] = campoReal[i+1][j];
    }
    else if(i == (linha-1) && j == 0){
        campo[i-1][j] = campoReal[i-1][j];

        campo[i-1][j+1] = campoReal[i-1][j+1];

        campo[i][j+1] = campoReal[i][j+1];
    }
    else if(i == (linha-1) && j == (coluna-1)){
        campo[i-1][j] = campoReal[i-1][j];

        campo[i-1][j-1] = campoReal[i-1][j-1];

        campo[i][j-1] = campoReal[i][j-1];
    }
    else if(i == 0 && j > 0 && j < (coluna-1)){
        campo[i][j-1] = campoReal[i][j-1];

        campo[i][j+1] = campoReal[i][j+1];

        campo[i-1][j+1] = campoReal[i-1][j+1];

        campo[i+1][j] = campoReal[i+1][j];

        campo[i+1][j+1] = campoReal[i+1][j+1];
    }
    else if(i == (linha-1) && j > 0 && j < (coluna-1)){
        campo[i][j-1] = campoReal[i][j-1];

        campo[i-1][j-1] = campoReal[i-1][j-1];

        campo[i-1][j] = campoReal[i-1][j];

        campo[i-1][j+1] = campoReal[i-1][j+1];

        campo[i][j+1] = campoReal[i][j+1];
    }
    else if(j == 0 && i > 0 && i < (linha-1)){
        campo[i-1][j] = campoReal[i-1][j];

        campo[i-1][j+1] = campoReal[i-1][j+1];

        campo[i][j+1] = campoReal[i][j+1];

        campo[i+1][j] = campoReal[i+1][j];

        campo[i+1][j+1] = campoReal[i+1][j+1];
    }
    else if(j == (coluna-1) && i > 0 && i < (linha-1)){
        campo[i-1][j] = campoReal[i-1][j];

        campo[i-1][j-1] = campoReal[i-1][j-1];

        campo[i][j-1] = campoReal[i][j-1];

        campo[i+1][j] = campoReal[i+1][j];

        campo[i+1][j-1] = campoReal[i+1][j-1];
    }
    else{
        campo[i-1][j-1] = campoReal[i-1][j-1];

        campo[i-1][j] = campoReal[i-1][j];

        campo[i-1][j+1] = campoReal[i-1][j+1];

        campo[i][j-1] = campoReal[i][j-1];

        campo[i][j+1] = campoReal[i][j+1];

        campo[i+1][j-1] = campoReal[i+1][j-1];

        campo[i+1][j] = campoReal[i+1][j];

        campo[i+1][j+1] = campoReal[i+1][j+1];
    }
}

int main(void){
    tempos t;
    char campo[MAX][MAX];
    int tela, inicio, nivel, linha, coluna, minas = 0;
    int tempo = time(NULL);

    tela = telaInicial(inicio, nivel);

    if((tela/10) == 1 && (tela%10) <= 3){
        if((tela%10) == 1){
            linha = 8;
            coluna = 8;
        }
        if((tela%10) == 2){
            linha = 16;
            coluna = 16;
        }
        if((tela%10) == 3){
        	cout<<"quantas linhas terao o campo? ";
        	cin>>linha;
        	cout<<"quantas colunas terao o campo? ";
        	cin>>coluna;
    		cout<<"quantas minas terao? ";
    		cin>>minas;
		}

        imprimeCampo(campo, linha, coluna, tempo);
        preencher(campo, linha, coluna, (tela%10), tempo, t, minas);
    }
    else if(tela/10==4){


    }

    return 0;
}



/*
    QUANDO IMPLEMENTADA A VITÃ“RIA COLOCAR ESSE ALGORITMO:

            for(int i = 0; i<3;i++){
                if(t<t.tempos[i]){
                    cout<<"Entre com seu nome: ";
                    cin.getline(nome,NAME);
                    t[i].nomes = nome;
                    t[i].times = Melhor;
                    break;
                }
            }
*/
