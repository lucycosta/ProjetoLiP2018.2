#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#define MAX 40

using namespace std;

char conversor(int n);
int telaInicial(int inicio, int nivel);
void imprimeCampo(char campo[MAX][MAX], int tamanho);
void preencher(char campo[MAX][MAX], int tamanho, int nivel);
void comandos(char campoReal[MAX][MAX], char campo[MAX][MAX],int tamanho, int nivel, int minas);
void resultado(char campoReal[MAX][MAX], char campo[MAX][MAX], int comando,  int minas, int tamanho, int nivel, int linha_esc, int coluna_esc);
void varredura(char campoReal[MAX][MAX], char campo[MAX][MAX], int tamanho, int linha_esc, int coluna_esc);

char conversor(int n){
	int aux;
	aux = n+48;
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

void imprimeCampo(char campo[MAX][MAX], int tamanho){
    cout<<"      ";
    for(int i = 0; i < tamanho; i++){
        cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<endl;

    for(int i = 0; i < tamanho; i++){
        cout<<i+1<<"     ";

        for(int j = 0; j < tamanho; j++){
            campo[i][j] = '.';
            cout<<campo[i][j]<<" ";
        }
        cout<<endl;
    }
}

void preencher(char campo[MAX][MAX], int tamanho, int nivel){
    char campoReal[MAX][MAX];
    int minas, cont;

    srand(time(NULL));
    cout<<endl;

    if(nivel == 1){
        minas = 10;
    }
    for(int i = 0; i < minas; i++){
    	int a = rand()%tamanho, b = rand()%tamanho;
		if(campoReal[a][b] != 'x'){
			campoReal[a][b] = 'x';
		}
		else{
			while(campoReal[a][b] == 'x'){
				a = rand()%tamanho;
				b = rand()%tamanho;
			}
			campoReal[a][b] = 'x';
		}
	}

	for(int i = 0; i < tamanho; i++){
		for(int j = 0; j < tamanho; j++){
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
				else if(i == 0 && j == (tamanho-1)){
					if(campoReal[i][j-1] == 'x')
						cont++;
					if(campoReal[i+1][j-1] == 'x')
						cont++;
					if(campoReal[i+1][j] == 'x')
						cont++;

					campoReal[i][j] = conversor(cont);
					cont = 0;
				}
				else if(i == (tamanho-1) && j == 0){
					if(campoReal[i-1][j] == 'x')
						cont++;
					if(campoReal[i-1][j+1] == 'x')
						cont++;
					if(campoReal[i][j+1] == 'x')
						cont++;

					campoReal[i][j] = conversor(cont);
					cont = 0;
				}
				else if(i == (tamanho-1) && j == (tamanho-1)){
					if(campoReal[i-1][j] == 'x')
						cont++;
					if(campoReal[i-1][j-1] == 'x')
						cont++;
					if(campoReal[i][j-1] == 'x')
						cont++;

					campoReal[i][j] = conversor(cont);
					cont = 0;
				}
				else if(i == 0 && j > 0 && j < (tamanho-1)){
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
				else if(i == (tamanho-1) && j > 0 && j < (tamanho-1)){
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
				else if(j == 0 && i > 0 && i < (tamanho-1)){
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
				else if(j == (tamanho-1) && i > 0 && i < (tamanho-1)){
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
		campo[i][tamanho] = '\0';
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

void resultado(char campoReal[MAX][MAX], char campo[MAX][MAX], int comando,  int minas, int tamanho, int nivel, int linha_esc, int coluna_esc){
    int cont_minas = 0;
    int time = 0;
    if(comando == 'D' || comando =='M'){
        if(campoReal[linha_esc-1][coluna_esc-1] == 'x' && comando == 'D'){
            cout<<"Voce Perdeu";
        }
        else{
             if(comando == 'M'){
                campo[linha_esc-1][coluna_esc-1] = 'M';
             }
   			 cout<<"      ";
   			 for(int i = 0; i < tamanho; i++){
        		cout<<i+1<<" ";
    		}
    		time = clock()/1000;
    		cout<<"     Tempo atual: "<<time<<" segundo(s)";
   			cout<<endl;
   			cout<<endl;

   			 for(int i = 0; i < tamanho; i++){
            	cout<<i+1<<"     ";

        		for(int j = 0; j < tamanho; j++){
                    if(campo[i][j]=='M'){
                        cont_minas++;
                        minas=10-cont_minas;
                    }
        			if(i == (linha_esc-1) && j == (coluna_esc-1) && campo[i][j] != 'M'){
						campo[i][j] = campoReal[linha_esc-1][coluna_esc-1];
						if(campo[i][j] == '0'){
							varredura(campoReal, campo, tamanho, linha_esc, coluna_esc);
						}
           				cout<<campo[i][j]<<" ";
					}
					else{
						cout<<campo[i][j]<<" ";
					}
       		 	}
        		cout<<endl;
    		}
        comandos(campoReal, campo, tamanho, nivel, minas);
        }
    }
}

void varredura(char campoReal[MAX][MAX], char campo[MAX][MAX], int tamanho, int linha_esc, int coluna_esc){
	int i = (linha_esc-1), j = (coluna_esc-1);
	
	if(i == 0 && j == 0){
		campo[i][j+1] = campoReal[i][j+1];
			
		campo[i+1][j] = campoReal[i+1][j];

		campo[i+1][j+1] = campoReal[i+1][j+1];
	}
	else if(i == 0 && j == (tamanho-1)){
		campo[i][j-1] = campoReal[i][j-1];	

		campo[i+1][j-1] = campoReal[i+1][j-1];
			
		campo[i+1][j] = campoReal[i+1][j];
	}
	else if(i == (tamanho-1) && j == 0){
		campo[i-1][j] = campoReal[i-1][j];
			
		campo[i-1][j+1] = campoReal[i-1][j+1];
			
		campo[i][j+1] = campoReal[i][j+1];			
	}
	else if(i == (tamanho-1) && j == (tamanho-1)){
		campo[i-1][j] = campoReal[i-1][j];
			
		campo[i-1][j-1] = campoReal[i-1][j-1];
			
		campo[i][j-1] = campoReal[i][j-1];
	}
	else if(i == 0 && j > 0 && j < (tamanho-1)){
		campo[i][j-1] = campoReal[i][j-1];
			
		campo[i][j+1] = campoReal[i][j+1];
					
		campo[i-1][j+1] = campoReal[i-1][j+1];
		
		campo[i+1][j] = campoReal[i+1][j];	

		campo[i+1][j+1] = campoReal[i+1][j+1];
	}
	else if(i == (tamanho-1) && j > 0 && j < (tamanho-1)){
		campo[i][j-1] = campoReal[i][j-1];
		
		campo[i-1][j-1] = campoReal[i-1][j-1];
			
		campo[i-1][j] = campoReal[i-1][j];

		campo[i-1][j+1] = campoReal[i-1][j+1];

		campo[i][j+1] = campoReal[i][j+1];
	}
	else if(j == 0 && i > 0 && i < (tamanho-1)){
		campo[i-1][j] = campoReal[i-1][j];

		campo[i-1][j+1] = campoReal[i-1][j+1];

		campo[i][j+1] = campoReal[i][j+1];

		campo[i+1][j] = campoReal[i+1][j];

		campo[i+1][j+1] = campoReal[i+1][j+1];
	}
	else if(j == (tamanho-1) && i > 0 && i < (tamanho-1)){
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
    char campo[MAX][MAX];
    int tela, inicio, nivel, tamanho;

    tela = telaInicial(inicio, nivel);

    if((tela/10) == 1 && (tela%10) <= 3){
        if((tela%10) == 1){
            tamanho = 8;
        }

        imprimeCampo(campo, tamanho);
        preencher(campo, tamanho, (tela%10));
    }

    return 0;
}
