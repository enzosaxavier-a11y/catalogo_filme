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
#include <iomanip>
#include <limits>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Filme {
    int ano;
    int id;
    string nome;
    float preco;
    string categoria;
    string sinopse;
    float duracao;
    int faixaet;
    float avaliacao;
    bool disponivel;
};

const int C = 15;
Filme vetor[C] = {
    {2001, 101, "O Senhor dos Aneis", 29.90f, "Fantasia",
     "Um grupo inicia uma jornada para destruir um poderoso anel.",
     178.0f, 12, 8.8f, true},

    {2004, 102, "Harry Potter e o Prisioneiro de Azkaban", 24.90f, "Fantasia",
     "Harry descobre novos segredos sobre seu passado em Hogwarts.",
     142.0f, 10, 7.9f, true},

    {2014, 103, "Interestelar", 34.90f, "Ficcao cientifica",
     "Astronautas viajam pelo espaco em busca de um novo lar para a humanidade.",
     169.0f, 10, 8.7f, false},

    {2019, 104, "Vingadores Ultimato", 32.90f, "Acao",
     "Os herois se unem para tentar reverter as perdas causadas por Thanos.",
     181.0f, 12, 8.4f, true},

    {1997, 105, "Titanic", 19.90f, "Drama",
     "Um casal vive um romance durante a viagem do navio Titanic.",
     194.0f, 12, 7.9f, true},

    {1972, 106, "O Poderoso Chefao", 27.90f, "Drama",
     "A historia de uma poderosa familia envolvida com o crime organizado.",
     175.0f, 14, 9.2f, false},

    {1995, 107, "Toy Story", 18.90f, "Animacao",
     "Brinquedos ganham vida quando seus donos nao estao por perto.",
     81.0f, 0, 8.3f, true},

    {2017, 108, "Corra", 21.90f, "Terror",
     "Um jovem visita a familia da namorada e descobre segredos assustadores.",
     104.0f, 14, 7.8f, true},

    {2015, 109, "Mad Max Estrada da Furia", 26.90f, "Acao",
     "Sobreviventes atravessam um deserto enquanto fogem de um tirano.",
     120.0f, 16, 8.1f, false},

    {2002, 110, "Cidade de Deus", 23.90f, "Drama",
     "Jovens enfrentam a violencia e o crime em uma comunidade do Rio de Janeiro.",
     130.0f, 16, 8.6f, true}
};

int quant = 10;

//========FUNCAO DE INSERCAO NO INICIO============

void insercao() {
    system("cls");

    if (quant >= C) {
        cout << "\n\n\t\tCatalogo cheio!\n\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    Filme novo;

    cout << "\t\tInsira novo filme!\n\n";

    cout << "Nome: ";
    getline(cin >> ws, novo.nome);

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

    cout << "Duracao (min): ";
    cin >> novo.duracao;

    cout << "Faixa etaria: ";
    cin >> novo.faixaet;

    cout << "Avaliacao (0-10): ";
    cin >> novo.avaliacao;

    cout << "O filme esta disponivel? (0-Nao / 1-Sim): ";
    cin >> novo.disponivel;

    char conf;
    cout << "\nDeseja mesmo inserir esse filme? (S/N): ";
    cin >> conf;

    if (conf != 'S' && conf != 's') {
        cout << "\nInsercao cancelada!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    for (int i = quant; i > 0; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[0] = novo;
    quant++;

    cout << "\nFilme inserido no inicio com sucesso!\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE INSERCAO NA POSICAO K============

void insercaoPosK() {
    system("cls");

    if (quant >= C) {
        cout << "\nCatalogo cheio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int k;

    cout << "\nInforme a posicao onde deseja inserir o filme: ";
    cin >> k;

    if (k < 1 || k > quant + 1) {
        cout << "\nPosicao invalida!\n";
        cout << "As posicoes permitidas sao de 1 ate " << quant + 1 << ".\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    Filme novo;

    cout << "\nDados do novo filme\n\n";

    cout << "Nome: ";
    getline(cin >> ws, novo.nome);

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

    char conf;
    cout << "\nDeseja mesmo inserir esse filme na posicao " << k
         << "? (S/N): ";
    cin >> conf;

    if (conf != 'S' && conf != 's') {
        cout << "\nInsercao cancelada!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int pos = k - 1;

    for (int i = quant; i > pos; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[pos] = novo;
    quant++;

    cout << "\nFilme inserido na posicao " << k << " com sucesso!\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE ALTERAR O POSTERIOR A K============

void alterarPosteriorK() {
    system("cls");

    if (quant < 2) {
        cout << "\nNao existem filmes suficientes!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int k;

    cout << "\nInforme a posicao k: ";
    cin >> k;

    if (k < 1 || k >= quant) {
        cout << "\nPosicao invalida ou sem filme posterior!\n";
        cout << "Informe uma posicao entre 1 e " << quant - 1 << ".\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int posPosterior = k;

    cout << "\nO filme posterior que sera alterado e: "
         << vetor[posPosterior].nome << "\n";
    cout << "\nInforme os novos dados do filme\n\n";

    Filme alterado;

    cout << "Nome: ";
    getline(cin >> ws, alterado.nome);

    cout << "ID: ";
    cin >> alterado.id;

    cout << "Ano de lancamento: ";
    cin >> alterado.ano;

    cout << "Preco: ";
    cin >> alterado.preco;

    cout << "Categoria: ";
    getline(cin >> ws, alterado.categoria);

    cout << "Sinopse: ";
    getline(cin >> ws, alterado.sinopse);

    cout << "Duracao em minutos: ";
    cin >> alterado.duracao;

    cout << "Faixa etaria: ";
    cin >> alterado.faixaet;

    cout << "Avaliacao de 0 a 10: ";
    cin >> alterado.avaliacao;

    cout << "O filme esta disponivel? (0-Nao / 1-Sim): ";
    cin >> alterado.disponivel;

    char conf;
    cout << "\nDeseja mesmo alterar esse filme? (S/N): ";
    cin >> conf;

    if (conf != 'S' && conf != 's') {
        cout << "\nAlteracao cancelada!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    vetor[posPosterior] = alterado;

    cout << "\nFilme da posicao " << k + 1 << " alterado com sucesso!\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE REMOVER O POSTERIOR AO ID X============

void removerPosteriorId() {
    system("cls");

    if (quant < 2) {
        cout << "\nNao existem filmes suficientes para remover um posterior!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int idProcurado;

    cout << "\nInforme o ID do filme: ";
    cin >> idProcurado;

    int posId = -1;

    for (int i = 0; i < quant; i++) {
        if (vetor[i].id == idProcurado) {
            posId = i;
            break;
        }
    }

    if (posId == -1) {
        cout << "\nFilme com esse ID nao encontrado!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    if (posId == quant - 1) {
        cout << "\nO filme encontrado e o ultimo e nao possui posterior!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int posRemover = posId + 1;
    string nomeRemovido = vetor[posRemover].nome;

    char conf;
    cout << "\nDeseja mesmo remover o filme \"" << nomeRemovido
         << "\"? (S/N): ";
    cin >> conf;

    if (conf != 'S' && conf != 's') {
        cout << "\nRemocao cancelada!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    for (int i = posRemover; i < quant - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    quant--;

    cout << "\nO filme posterior \"" << nomeRemovido
         << "\" foi removido com sucesso!\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE CONSULTAR O ANTERIOR AO NOME Y============

void consultarAnteriorNome() {
    system("cls");

    if (quant < 2) {
        cout << "\nNao existem filmes suficientes para consultar um anterior!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    string nomeProcurado;

    cout << "\nInforme o nome do filme: ";
    getline(cin >> ws, nomeProcurado);

    int posNome = -1;

    for (int i = 0; i < quant; i++) {
        if (vetor[i].nome == nomeProcurado) {
            posNome = i;
            break;
        }
    }

    if (posNome == -1) {
        cout << "\nFilme nao encontrado!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    if (posNome == 0) {
        cout << "\nO filme encontrado e o primeiro e nao possui anterior!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int posAnterior = posNome - 1;

    cout << "\nFilme anterior a \"" << vetor[posNome].nome << "\":\n\n";
    cout << "Posicao: " << posAnterior + 1 << "\n";
    cout << "Nome: " << vetor[posAnterior].nome << "\n";
    cout << "ID: " << vetor[posAnterior].id << "\n";
    cout << "Ano de lancamento: " << vetor[posAnterior].ano << "\n";
    cout << "Preco: R$ " << vetor[posAnterior].preco << "\n";
    cout << "Categoria: " << vetor[posAnterior].categoria << "\n";
    cout << "Sinopse: " << vetor[posAnterior].sinopse << "\n";
    cout << "Duracao: " << vetor[posAnterior].duracao << " minutos\n";
    cout << "Faixa etaria: " << vetor[posAnterior].faixaet << "\n";
    cout << "Avaliacao: " << vetor[posAnterior].avaliacao << "\n";
    cout << "Disponivel: "
         << (vetor[posAnterior].disponivel ? "Sim" : "Nao") << "\n";

    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE IMPRIMIR A LISTA============

void imprimirLista() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    cout << "\n========== LISTA DE FILMES ==========\n";

    for (int i = 0; i < quant; i++) {
        cout << "\n-------------------------------------\n";
        cout << "Posicao: " << i + 1 << "\n";
        cout << "Nome: " << vetor[i].nome << "\n";
        cout << "ID: " << vetor[i].id << "\n";
        cout << "Ano de lancamento: " << vetor[i].ano << "\n";
        cout << "Preco: R$ " << vetor[i].preco << "\n";
        cout << "Categoria: " << vetor[i].categoria << "\n";
        cout << "Sinopse: " << vetor[i].sinopse << "\n";
        cout << "Duracao: " << vetor[i].duracao << " minutos\n";
        cout << "Faixa etaria: " << vetor[i].faixaet << "\n";
        cout << "Avaliacao: " << vetor[i].avaliacao << "\n";
        cout << "Disponivel: " << (vetor[i].disponivel ? "Sim" : "Nao") << "\n";
    }

    cout << "\n-------------------------------------\n";
    cout << "Quantidade de filmes: " << quant << "\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE AUMENTAR O PRECO EM 15 POR CENTO============

void aumentarPrecoNome() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    string nomeProcurado;

    cout << "\nInforme o nome do filme: ";
    getline(cin >> ws, nomeProcurado);

    int posNome = -1;

    for (int i = 0; i < quant; i++) {
        if (vetor[i].nome == nomeProcurado) {
            posNome = i;
            break;
        }
    }

    if (posNome == -1) {
        cout << "\nFilme nao encontrado!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    char conf;
    cout << "\nDeseja mesmo aumentar o preco do filme \""
         << vetor[posNome].nome << "\" em 15%? (S/N): ";
    cin >> conf;

    if (conf != 'S' && conf != 's') {
        cout << "\nAlteracao de preco cancelada!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    float precoAnterior = vetor[posNome].preco;
    vetor[posNome].preco = vetor[posNome].preco * 1.15f;

    cout << fixed << setprecision(2);
    cout << "\nFilme: " << vetor[posNome].nome << "\n";
    cout << "Preco anterior: R$ " << precoAnterior << "\n";
    cout << "Preco atualizado: R$ " << vetor[posNome].preco << "\n";

    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE CONTAR FILMES POR AVALIACAO============

void contarPorAvaliacao() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    float avaliacaoEscolhida;
    int contador = 0;

    cout << "\nInforme a avaliacao X: ";
    cin >> avaliacaoEscolhida;

    for (int i = 0; i < quant; i++) {
        if (vetor[i].avaliacao >= avaliacaoEscolhida) {
            contador++;
        }
    }

    cout << "\nQuantidade de filmes com avaliacao maior ou igual a "
         << avaliacaoEscolhida << ": " << contador << "\n";

    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE IMPRIMIR FILMES DA CATEGORIA X============

void imprimirPorCategoria() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    string categoriaProcurada;
    int encontrados = 0;

    cout << "\nInforme a categoria X: ";
    getline(cin >> ws, categoriaProcurada);

    cout << "\nFilmes da categoria \"" << categoriaProcurada << "\":\n";

    for (int i = 0; i < quant; i++) {
        if (vetor[i].categoria == categoriaProcurada) {
            cout << "\n-------------------------------------\n";
            cout << "Posicao: " << i + 1 << "\n";
            cout << "Nome: " << vetor[i].nome << "\n";
            cout << "ID: " << vetor[i].id << "\n";
            cout << "Ano de lancamento: " << vetor[i].ano << "\n";
            cout << "Preco: R$ " << vetor[i].preco << "\n";
            cout << "Categoria: " << vetor[i].categoria << "\n";
            cout << "Sinopse: " << vetor[i].sinopse << "\n";
            cout << "Duracao: " << vetor[i].duracao << " minutos\n";
            cout << "Faixa etaria: " << vetor[i].faixaet << "\n";
            cout << "Avaliacao: " << vetor[i].avaliacao << "\n";
            cout << "Disponivel: " << (vetor[i].disponivel ? "Sim" : "Nao") << "\n";
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "\nNenhum filme encontrado nessa categoria!\n";
    } else {
        cout << "\nQuantidade encontrada: " << encontrados << "\n";
    }

    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE EXIBIR DISPONIVEIS POR FAIXA ETARIA============

void imprimirDisponiveisPorFaixa() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    int faixaEscolhida;
    int encontrados = 0;

    cout << "\nInforme a faixa etaria X: ";
    cin >> faixaEscolhida;

    cout << "\nFilmes disponiveis com faixa etaria maior ou igual a "
         << faixaEscolhida << ":\n";

    for (int i = 0; i < quant; i++) {
        if (vetor[i].disponivel && vetor[i].faixaet >= faixaEscolhida) {
            cout << "\n-------------------------------------\n";
            cout << "Posicao: " << i + 1 << "\n";
            cout << "Nome: " << vetor[i].nome << "\n";
            cout << "ID: " << vetor[i].id << "\n";
            cout << "Ano de lancamento: " << vetor[i].ano << "\n";
            cout << "Preco: R$ " << vetor[i].preco << "\n";
            cout << "Categoria: " << vetor[i].categoria << "\n";
            cout << "Sinopse: " << vetor[i].sinopse << "\n";
            cout << "Duracao: " << vetor[i].duracao << " minutos\n";
            cout << "Faixa etaria: " << vetor[i].faixaet << "\n";
            cout << "Avaliacao: " << vetor[i].avaliacao << "\n";
            cout << "Disponivel: Sim\n";
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "\nNenhum filme disponivel encontrado para essa faixa!\n";
    } else {
        cout << "\nQuantidade encontrada: " << encontrados << "\n";
    }

    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE ORDENAR FILMES POR ANO DECRESCENTE============

void ordenarPorAnoDecrescente() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    for (int i = 0; i < quant - 1; i++) {
        for (int j = 0; j < quant - 1 - i; j++) {
            if (vetor[j].ano < vetor[j + 1].ano) {
                Filme auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
            }
        }
    }

    cout << "\nFilmes ordenados do mais novo para o mais antigo:\n";

    for (int i = 0; i < quant; i++) {
        cout << "\n" << i + 1 << " - " << vetor[i].nome
             << " (" << vetor[i].ano << ")";
    }

    cout << "\n\nOrdenacao concluida com sucesso!\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE CALCULAR VALOR TOTAL E MEDIA POR CATEGORIA============

void calcularValores() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    float valorTotal = 0;

    for (int i = 0; i < quant; i++) {
        valorTotal += vetor[i].preco;
    }

    cout << fixed << setprecision(2);
    cout << "\nValor total de todos os filmes: R$ " << valorTotal << "\n";
    cout << "\nMedias de preco por categoria:\n";

    for (int i = 0; i < quant; i++) {
        bool categoriaJaExibida = false;

        for (int j = 0; j < i; j++) {
            if (vetor[j].categoria == vetor[i].categoria) {
                categoriaJaExibida = true;
                break;
            }
        }

        if (!categoriaJaExibida) {
            float somaCategoria = 0;
            int quantidadeCategoria = 0;

            for (int j = 0; j < quant; j++) {
                if (vetor[j].categoria == vetor[i].categoria) {
                    somaCategoria += vetor[j].preco;
                    quantidadeCategoria++;
                }
            }

            float mediaCategoria = somaCategoria / quantidadeCategoria;

            cout << "\nCategoria: " << vetor[i].categoria << "\n";
            cout << "Quantidade de filmes: " << quantidadeCategoria << "\n";
            cout << "Media de preco: R$ " << mediaCategoria << "\n";
        }
    }

    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========FUNCAO DE REMOVER FILME PELO NOME============

void remocaoNome() {
    system("cls");

    if (quant == 0) {
        cout << "\nCatalogo esta vazio!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    string nomeProcurado;

    cout << "\nQual filme deseja remover? ";
    getline(cin >> ws, nomeProcurado);

    int posicao = -1;

    for (int i = 0; i < quant; i++) {
        if (vetor[i].nome == nomeProcurado) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        cout << "\nFilme nao encontrado!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    string nomeRemovido = vetor[posicao].nome;

    char conf;
    cout << "\nDeseja mesmo remover o filme \"" << nomeRemovido
         << "\"? (S/N): ";
    cin >> conf;

    if (conf != 'S' && conf != 's') {
        cout << "\nRemocao cancelada!\n";
        cout << "\nPressione qualquer tecla para continuar";
        getch();
        return;
    }

    for (int i = posicao; i < quant - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    quant--;

    cout << "\nFilme \"" << nomeRemovido << "\" removido com sucesso!\n";
    cout << "\nPressione qualquer tecla para continuar";
    getch();
}

//========MENU PRINCIPAL============

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int op = 99;

    while (op != 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        system("cls");
        cout << "\t--------- CATÁLOGO DE FILMES --------- \n\n";
        cout << "\t*** MENU INICIAL ***\n";
        cout << "\tSelecione uma opção:\n";
        cout << "\t1  - Inserir novo filme no inicio\n";
        cout << "\t2  - Inserir um filme na posicao k\n";
        cout << "\t3  - Alterar o filme posterior a posicao k\n";
        cout << "\t4  - Procurar filme pelo ID e remover o posterior\n";
        cout << "\t5  - Consultar o filme anterior ao nome escolhido\n";
        cout << "\t6  - Imprimir lista\n";
        cout << "\t7  - Aumentar em 15% o preco do filme escolhido\n";
        cout << "\t8  - Quantidade de filmes por avaliacao\n";
        cout << "\t9  - Imprimir filmes da categoria escolhida\n";
        cout << "\t10 - Filmes disponiveis por faixa etaria\n";
        cout << "\t11 - Ordem decrescente de filmes por ano\n";
        cout << "\t12 - Valor total e media por categoria\n";
        cout << "\t13 - Remover filme pelo nome\n";
        cout << "\t0  - Sair\n";

        cout << "\n\tInforme uma opcao: ";

        if (!(cin >> op)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nOpcao invalida! Digite somente numeros.";
            cout << "\nPressione qualquer tecla para continuar";
            getch();
            op = 99;
            continue;
        }

        switch (op) {
            case 1:
                insercao();
                break;
            case 2:
                insercaoPosK();
                break;
            case 3:
                alterarPosteriorK();
                break;
            case 4:
                removerPosteriorId();
                break;
            case 5:
                consultarAnteriorNome();
                break;
            case 6:
                imprimirLista();
                break;
            case 7:
                aumentarPrecoNome();
                break;
            case 8:
                contarPorAvaliacao();
                break;
            case 9:
                imprimirPorCategoria();
                break;
            case 10:
                imprimirDisponiveisPorFaixa();
                break;
            case 11:
                ordenarPorAnoDecrescente();
                break;
            case 12:
                calcularValores();
                break;
            case 13:
                remocaoNome();
                break;
            case 0:
                cout << "\nPrograma encerrado.\n";
                break;
            default:
                cout << "\nOpcao invalida!\n";
                cout << "\nPressione qualquer tecla para continuar";
                getch();
        }
    }

    return 0;
}
