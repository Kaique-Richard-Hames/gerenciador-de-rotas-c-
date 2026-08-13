#include <iostream>
#include <cstdlib>  //atoi e atof
#include <cstring>
#include <cctype>
#include <iomanip>
#include <stdlib.h> // comandos system
#define MAX 20
using namespace std;
void mostrarMenu();
int lerNumIntervalo(int, int, string);
void lerVetStrings(int, string[]);
bool stringIsAlpha(string&);
void mostraVetString(int, string[]);
int numIsDigito(string);
bool validaFloat(string);
float stringToFloat(string);
void lerDistanciaCidades(int, string[], float[][MAX]);
void mostraMatrizDistCidades(int,string[], float[][MAX]);
void lerDistEntreCidades(int n, string cidades[], float distancia[][MAX]);
void mostraDistanciaCidades(int, string[], float[][MAX]);
void criaTrajetoCidades(int, string[], float[][MAX]);
char lerSOuN(char);

int main(){
    int n;
    string nomeCidades[MAX];
    float distanciaCidades[MAX][MAX];
    n = lerNumIntervalo(4, MAX, "Quantas cidades serao utilizadas: ");
    lerVetStrings(n, nomeCidades);
    lerDistanciaCidades(n, nomeCidades, distanciaCidades);
    int escolha;
    do{
        mostrarMenu();
        escolha = lerNumIntervalo(1, 9, "Escolha uma das opcoes. ");
        switch(escolha){
        case 1:
            n = lerNumIntervalo(4, MAX, "Quantas cidades serao utilizadas: ");
            break;
        case 2:
            lerVetStrings(n, nomeCidades);
            break;
        case 3:
            lerDistanciaCidades(n, nomeCidades, distanciaCidades);
            break;
        case 4:
            mostraVetString(n, nomeCidades);
            break;
        case 5:
            mostraMatrizDistCidades(n, nomeCidades, distanciaCidades);
            break;
        case 6:
            mostraDistanciaCidades(n,nomeCidades,distanciaCidades);
            break;
        case 7:
            criaTrajetoCidades(n,nomeCidades,distanciaCidades);
            break;
        case 8:
            system("cls"); //para limpar a tela
            break;
        case 9:
            cout << "Encerrando programa." << endl;
            break;
        default:
            cout << "Opacao invalida, tente novamente." << endl;
            cout << "";
        }
    }while(escolha !=9 and not isdigit(escolha));
    return 0;
}

void mostrarMenu(){
    cout << "================ Menu de opcoes ================" << endl;
    cout << "1. Para inserir a quantidade de cidades." << endl;
    cout << "2. Para inserir os nomes das cidade. " << endl;
    cout << "3. Para inserir as distancias entre as cidades." << endl;
    cout << "4. Para mostrar os nomes das cidades." << endl;
    cout << "5. Para mostrar as distancias entre as cidades." << endl;
    cout << "6. Para mostrar a distancia entre duas cidades." << endl;
    cout << "7. Para criar um trajeto entre as cidades." << endl;
    cout << "8. Para limpar a tela." << endl;
    cout << "9. Para encerrar o programa." << endl;
    cout << "================================================" << endl;
}
int lerNumIntervalo(int linf, int lsup, string s){
    string info;
    int x;
    do{
        cout << s << endl << "Minimo: " << linf << ". Maximo: " << lsup << endl;
        getline(cin,info);
        x = numIsDigito(info); // chama outra função para validar o número como string primeiro, e depois transformar em int
        if(x < linf or x > lsup)
            cout <<"Numero invalido, digite novamente."<<endl;
    }while(x < linf or x > lsup);
    return x;
}
int numIsDigito(string info){
    int x;
    bool validada;
    do{
         if(info=="") // se for string vazia
            validada=false;
         else
            if(not isdigit(info[0]) and info[0]!='-') //se nao for digito e nem sinal
                validada=false;
            else
                for(int i=1; i<info.length(); i++) // varre o resto das posicoes
                    if(not isdigit(info[i])){ // se nao for digito
                        validada=false;
                        break;
                }
                x=atoi(info.c_str()); // converte a string para int
         }while(validada = false);

         return x;
}
bool stringIsAlpha(string &nome){
    unsigned int i;
    string info;
    info = nome;
     if(info==""){  // se for string vazia
        cout << "Entrada invalida, digite novamente"<< endl;
        return false;
     }
     for(i=0; i<info.length(); i++) //varrer todas as letras
        if(not isalpha(info[i]) and info[i]!=' '){
           cout << "Entrada invalida, digite novamente"<< endl;
           return false;       //erro se nao for letra do alfabeto nem espaço
        }
     nome = info;   //copia entrada para a variavel nome
return true;
}
void lerVetStrings(int n, string vs[]){
    for(int i = 0; i < n; i++){
        do{
            cout << "Digite o nome da " << i+1 << " cidade" << endl;
            getline(cin, vs[i]);
        }while(not stringIsAlpha(vs[i]));
    }
}
void mostraVetString(int n, string cidades[]){
    cout << endl << "Nomes das cidades:" << endl;
    cout << "[ ";
    for(int i=0; i<n;i++){
        if(i != n-1){
            cout << cidades[i] << ", "; // mostrar na tela os nomes até o penúlitmo caso
        }else{
            cout << cidades[i]; // mostra na tela o último caso
        }
    }
    cout << " ]" << endl;
    cout << endl;
}
bool validaFloat(string info){
    bool ponto = true;
    bool digito = true;
    for (int i =0; i < info.size(); i++){
        int ponto=0;
        if(info=="") // se for string vazia
            return false;
        else
            if(not isdigit(info[0]) and info[0]!='-') //se nao for digito/sinal
                return false;
        else
            for(i=1; i<info.length(); i++) // varre demais posicoes
                if(not isdigit(info[i])){ // se nao for digito

                    if(isdigit(info[i-1]) and info[i]=='.' and ponto==0)// verifica se eh ponto com um digito antes
                        ponto++; // permite um ponto apenas
                else{
                    return false;
                    }
                }
    }
    return true;
}
float stringToFloat(string info){
    float n;
    do{
        getline(cin,info);
        n = atof(info.c_str());
        if(not validaFloat(info)or n < -1)
            cout << "Numero invalido, digite novamente." << endl;
    }while(not validaFloat(info)or n < -1);
    return n;
}
void lerDistanciaCidades(int n, string cidades[], float distancia[][MAX]){
    string info;
    float x;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(i != j){
                cout << "Digite a distancia(em Km) entre: "<< cidades[i] << " e " << cidades[j] << " --- (Para cidades que nao sejam vizinhas digite 0)" << endl;
                x = stringToFloat(info);// chama outra função para validar o número como string primeiro, e depois transformar em float
                distancia[i][j] = x;
                distancia[j][i] = x;
            }
        }
        distancia[0][0] = -1;
        distancia[i][i] = -1;
    }
}
void mostraMatrizDistCidades(int n,string cidade[], float distancia[][MAX]){
    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << setw(12) << cidade[i];
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << cidade[i] << setw(5) << " |";
        for(int j=0; j<n; j++){
            if(i == j)
                cout << setw(3) << "[ N/A ]";
            else
                cout << setw(3) << " [ " << distancia[i][j] << " ] ";
        }
        cout << " |" << endl;
    }
}
void lerDistanciaEntreCidades(int n, string cidades[], float distancia[][MAX], int &partida, int &proxCidade, int cont){
    int aux = 0;
    cout << endl;
    for(int i=0; i<n; i++){
        cout << i+1 << "° Cidade: " << cidades[i] << endl;
    }
    cout << endl;
    do{
        if(cont == 0){
        partida = lerNumIntervalo(1,n,"Escolha a cidade de Partida: ");
        proxCidade = lerNumIntervalo(1,n,"Escolha a proxima cidade: ");
    }else{
        aux = proxCidade;
        proxCidade = lerNumIntervalo(1,n,"Escolha a proxima cidade: ");
        partida = aux;
    }
    if(partida == proxCidade){
        cout << "A mesma cidade foi escolhida duas vezes! Favor selecionar novamente." << endl;
        proxCidade = partida;
    }
    }while(partida == proxCidade);
}
void mostraDistanciaCidades(int n, string cidades[], float distancia[][MAX]){
    int partida, proxCidade, cont=0;

        lerDistanciaEntreCidades(n,cidades, distancia, partida, proxCidade, cont);
        if(distancia[partida-1][proxCidade-1] == 0){
          cout << "Estas cidades nao sao vizinhas!" << endl;
        }else{
             cout << "A distancia entre " << cidades[partida-1] << " e " << cidades[proxCidade-1] << " eh: " << distancia[partida-1][proxCidade-1] << "Km" << endl;
        }
}
void criaTrajetoCidades(int n, string cidades[], float distancia[][MAX]){
    char resp;
    int partida, proxCidade, cont=0;
    float soma = 0.0;
    do{
        lerDistanciaEntreCidades(n,cidades, distancia, partida, proxCidade, cont);
        if(distancia[partida-1][proxCidade-1] == 0){
          cout << "Trajeto Invalido, " << cidades[partida-1] << " e " << cidades[proxCidade-1] << " NAO se conectam!" << endl;
          break;
        }else{
            cout << "A distancia entre " << cidades[partida-1] << " e " << cidades[proxCidade-1] << " eh: " << distancia[partida-1][proxCidade-1] << "Km" << endl;
            soma += distancia[partida-1][proxCidade-1];
        }
    cout << endl;
            cout << "Deseja adicionar mais uma cidade no trajeto? (S/N) " << endl;
            resp = lerSOuN(resp);
            if(toupper(resp) == 'S')
                cont++;
    }while(toupper(resp) == 'S');
        if(distancia[partida-1][proxCidade-1] != 0)
            cout << endl << "Distancia total do trajeto: " << soma << "Km" << endl;  //fixed set precision
}
char lerSOuN(char resp){
    do{
        resp = cin.get();
        cin.ignore();
        if(toupper(resp) != 'S' and toupper(resp) != 'N')
            cout << "Resposta invalida, tente novamente. " << endl;
    }while(toupper(resp) != 'S' and toupper(resp) != 'N');
    return resp;
}
