//GRUPO 3
//RA: 2611600734
//CARLOS ALEXANDRE SILVA DE CAMARGO
//RA: 2611600680
//ENZO FELIPE XAVIER
//RA: 2611600357
//RAFAEL DE CARVALHO COSTA
//Tema: CATÁLOGO DE FILMES

#include <iostream>
#include <locale>
#include <string>
#include <conio.h>

using namespace std;

struct Filme{

               int ano; //ano de lançamento
               int id;
               string nome;
			   float preco;
               string categoria; //drama, ação, suspense...
               string sinopse;
               float duracao; //tempo do filme (min)
               int faixaet; //faixa etária
               float avaliacao; //nota crítica
               bool disponivel;  //(0-Não|1-Sim)

};
    const int C=3;
    Filme vetor[C];
    int quant=0; 


//========FUNÇÃO DE INSERÇÃO============


void insercao(){
    system("cls");
    if (quant>=C){
        cout << "\n\n\t\tCatalogo cheio!\n\n";
        cout << "\nPressione qualquer tecla para continuar";
        _getch();
        return;

    }
    Filme novo;
	cout << "\t\tInsira novo filme!\n\n";

	cout << "\n";
    cout << "Nome: ";
    getline(cin >> ws, novo.nome);

    cout << "ID: ";
    cin >> novo.id;

    cout << "Ano de lançamento: ";
    cin >> novo.ano;

    cout << "Preço: ";
    cin >> novo.preco;

    cout << "Categoria: ";
    getline(cin >> ws, novo.categoria);

    cout << "Sinopse: ";
    getline(cin >> ws, novo.sinopse);

    cout << "Duração (min): ";
    cin >> novo.duracao;

    cout << "Faixa etária: ";
    cin >> novo.faixaet;

    cout << "Avaliação (0-10): ";
    cin >> novo.avaliacao;

    cout << "O filme está disponível?: ";
    cin >> novo.disponivel;

    vetor[quant] = novo;
    quant++;

    cout << "\n\n\t\tFilme inserido com sucesso!\n\n";

    cout << "\nPressione qualquer tecla para continuar";
    _getch();

}; 

//========FUNÇÃO NA POSIÇÃO K============


void insercaoPosK(){
    system("cls");

    if(quant >= c) {
        cout << "\nCatalogo cheio!\n";
         cout << "\nPressione qualquer tecla para continuar";
        _getch();
        return;
    }

    int k

    cout << "\nInforme a posicao onde deseja inserir o filme:";
    cin >> k;

    if(k < 1 || k > quant + 1) {
        cout << "\nPosicao invalida!\n";
        cout << "As posicao permitidas sao de 1 ate" << quant + 1 << ".\n";

        cout << "\nPressione qualquer tecla para continuar";
        _getch();
        return;
    }

    Filme novo;

    cout << "\nDados do novo filme\n\n";

    cout << "Nome:";
    _getline(cin >> ws, novo.nome)

    cout << "ID: ";
    cin >> novo.id;

    cout << "Ano de lancamento: ";
    cin >> novo.ano;

    cout << "Preco: ";
    cin >> novo.preco;

    cout << "Categoria: ";
    getline(cin >> ws, novo.categoria);

    cout << "Sinopse: ";
    getline(cin >> ws, novo.sinopse);

    cout << "Duracao em minutos: ";
    cin >> novo.duracao;

    cout << "Faixa etaria: ";
    cin >> novo.faixaet;

    cout << "Avaliacao de 0 a 10: ";
    cin >> novo.avaliacao;

    cout << "O filme esta disponivel? (0-Nao / 1-Sim): ";
    cin >> novo.disponivel;

    int pos = k - 1

    for (int i= quant; i > pos; i++) {
        vetor[i] = vetor[i - 1];
    }

    vetor[pos] = novo;
    quant ++;

    cout << "\nFilme inserido na posicao" << k << "com sucesso!\n";

    cout << "\nPressione qualquer tecla para continuar";
    _getch()/
}

//========FUNÇÃO DE REMOÇÃO============


void remocaoNome() {
    system("cls");
    if(quant == 0) {
        cout << "\nCatalogo esta vazio!\n"
        cout << "\nPressione qualquer tecla para continuar";
        _getch();
        return;
    }

 string proc;

 cout << "\nQual filme deseja remover?:";
    getline(cin >> ws, proc);

int posaux =-1

for (int i=0; i<quant; i++){
    if (vetor[i].nome == procurar){
        posaux = i;
        break;
    }
}
if (posaux == -1 {
    cout << "\nFilme nao encontrado\n";
})

for ( int i = posaux; i < quant -1; i++){
    vetor[i] = vetor[i+1];
}

quant--;

cout << "\nFolme removido com sucesso!\n";

cout << "\nPressione qualquer tecla para continuar";
_getch();

}



int main(){
    setlocale(LC_ALL, "Portuguese");
    int op = 99;
	while(op != 0){
		system("cls");
	    cout << "\t--------- CATÁLOGO DE FILMES --------- \n\n";
	    cout << "\t*** MENU INICIAL ***" << endl;
	    cout << "\tSelecione uma opção: " << endl;
        cout <<"\t1 - inserir novo filme no início" << endl;
        cout <<"\t3  - Inserir um nó da posição k" << endl;
        cout <<"\t4  - Selecione nó pelo ID e remova o nó posterior" << endl;
        cout <<"\t5  - Consulte o filme na posição anterior ao nó de nome escolhido" << endl;
        cout <<"\t6  - Imprimir Lista" << endl;
        cout <<"\t7  - Consulte nó com o nome escolhido e aumentar o preço em 15%" << endl; // mostrando o preço antes e o atualizado
        cout <<"\t8  - Quantidade de filmes com avaliação maior ou igual a escolhida" << endl;
        cout <<"\t9  - Imprimir filmes da categoria escolhida" << endl;
        cout <<"\t10 - Filmes disponíveis para faixa etária igual ou maior a escolhida" << endl;
        cout <<"\t11 - Ordem decrescente de filmes por ano" << endl; // filme mais novo > filme mais antigo
        cout <<"\t12 - Valor total (R$) de todos os filmes e média por categoria" << endl;
        cout <<"\t13 - Remover filme com nome igual ao escolhido" << endl;
        cout <<"\t0  - Sair";

        cout << "\n\n\tInforme uma opção: ";
	    cin >> op; 

        switch (op){
    
        case 1:
            insercao();
            break;
        
        case 2:
            incercaoPosK();
            break;
        case 3:
            
            break;
            ;
            break;
        
        case 4:
            ;
            break;
        case 5:
            ;
            break;
        
        case 6:
            ;
            break;
        case 7:
            ;
            break;
        
        case 8:
            ;
            break;
        case 9:
            ;
            break;
        
        case 10:
            ;
            break;
        case 11:
            ;
            break;
        
        case 12:
            ;
            break;

        case 13:
            remocaoNome();
            break;


        default:
            break;
        }
    }
}
