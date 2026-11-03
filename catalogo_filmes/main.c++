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

const int C = 5;

Filme vetor[C];
int quant = 0;

//========FUNCOES AUXILIARES E VALIDACOES============

void pausar() {
    cout << "\nPressione qualquer tecla para continuar";
    cout.flush();
    _getch();
}

string lerTexto(string mensagem) {
    string texto;
    cout << mensagem;
    getline(cin >> ws, texto);
    return texto;
}

int lerInteiro(string mensagem) {
    int valor;
    cout << mensagem;
    cin >> valor;
    return valor;
}

float lerReal(string mensagem) {
    float valor;
    cout << mensagem;
    cin >> valor;
    return valor;
}

bool textosIguais(string texto1, string texto2) {
    return texto1 == texto2;
}

Filme lerFilme() {
    Filme filme;

    filme.nome = lerTexto("Nome (maximo 50 caracteres): ");
    filme.id = lerInteiro("ID (1 a 999): ");
    filme.ano = lerInteiro("Ano de lancamento (1888 a 2026): ");
    filme.preco = lerReal("Preco (0 a 9999.99, use ponto): R$ ");
    filme.categoria = lerTexto("Categoria (maximo 30 caracteres): ");
    filme.sinopse = lerTexto("Sinopse (maximo 100 caracteres): ");
    filme.duracao = lerReal("Duracao em minutos (1 a 600): ");
    filme.faixaet = lerInteiro("Faixa etaria (0 a 18): ");
    filme.avaliacao = lerReal("Avaliacao (0 a 10): ");

    int disponivel = lerInteiro("Disponivel (0-Nao / 1-Sim): ");
    filme.disponivel = disponivel == 1;

    return filme;
}

int buscarPorNome(string nome) {
    for (int i = 0; i < quant; i++) {
        if (textosIguais(vetor[i].nome, nome)) {
            return i;
        }
    }
    return -1;
}

int buscarPorId(int id) {
    for (int i = 0; i < quant; i++) {
        if (vetor[i].id == id) {
            return i;
        }
    }
    return -1;
}

void imprimirFilme(Filme filme, int posicao) {
    cout << fixed << setprecision(2);
    cout << "\n-------------------------------------\n";
    cout << "Posicao: " << posicao + 1 << "\n";
    cout << "Nome: " << filme.nome << "\n";
    cout << "ID: " << filme.id << "\n";
    cout << "Ano de lancamento: " << filme.ano << "\n";
    cout << "Preco: R$ " << filme.preco << "\n";
    cout << "Categoria: " << filme.categoria << "\n";
    cout << "Sinopse: " << filme.sinopse << "\n";
    cout << "Duracao: " << filme.duracao << " minutos\n";
    cout << "Faixa etaria: " << filme.faixaet << "\n";
    cout << "Avaliacao: " << filme.avaliacao << "\n";
    cout << "Disponivel: " << (filme.disponivel ? "Sim" : "Nao") << "\n";
}

//========TASK 2: INSERIR NO INICIO============

void insercao() {
    system("cls");

    if (quant >= C) {
        cout << "\nCatalogo cheio! O limite e de " << C << " filmes.\n";
        pausar();
        return;
    }

    cout << "\nInsira o novo filme\n\n";
    Filme novo = lerFilme();

    for (int i = quant; i > 0; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[0] = novo;
    quant++;

    cout << "\nFilme inserido no inicio com sucesso!\n";
    pausar();
}

//========TASK 3: INSERIR NA POSICAO K============

void insercaoPosK() {
    system("cls");

    if (quant >= C) {
        cout << "\nCatalogo cheio! O limite e de " << C << " filmes.\n";
        pausar();
        return;
    }

    int k = lerInteiro("\nInforme a posicao onde deseja inserir o filme: ");

    if (k < 1 || k > quant + 1) {
        cout << "\nPosicao invalida! Use uma posicao de 1 ate "
             << quant + 1 << ".\n";
        pausar();
        return;
    }

    cout << "\nDados do novo filme\n\n";
    Filme novo = lerFilme();
    int posicao = k - 1;

    for (int i = quant; i > posicao; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[posicao] = novo;
    quant++;

    cout << "\nFilme inserido na posicao " << k << " com sucesso!\n";
    pausar();
}

//========TASK 4: ALTERAR O POSTERIOR A K============

void alterarPosteriorK() {
    system("cls");

    if (quant < 2) {
        cout << "\nNao existem filmes suficientes para alterar um posterior!\n";
        pausar();
        return;
    }

    int k = lerInteiro("\nInforme a posicao k: ");

    if (k < 1 || k >= quant) {
        cout << "\nPosicao invalida ou sem filme posterior!\n";
        pausar();
        return;
    }
    int posicaoPosterior = k;

    cout << "\nFilme que sera alterado: "
         << vetor[posicaoPosterior].nome << "\n";
    cout << "\nInforme os novos dados\n\n";

    vetor[posicaoPosterior] = lerFilme();

    cout << "\nFilme da posicao " << k + 1 << " alterado com sucesso!\n";
    pausar();
}

//========TASK 5: REMOVER O POSTERIOR AO ID X============

void removerPosteriorId() {
    system("cls");

    if (quant < 2) {
        cout << "\nNao existem filmes suficientes para remover um posterior!\n";
        pausar();
        return;
    }

    int idProcurado = lerInteiro("\nInforme o ID do filme (1 a 999): ");
    int posicaoId = buscarPorId(idProcurado);

    if (posicaoId == -1) {
        cout << "\nFilme com esse ID nao encontrado!\n";
        pausar();
        return;
    }

    if (posicaoId == quant - 1) {
        cout << "\nO filme encontrado e o ultimo e nao possui posterior!\n";
        pausar();
        return;
    }

    int posicaoRemover = posicaoId + 1;
    string nomeRemovido = vetor[posicaoRemover].nome;

    for (int i = posicaoRemover; i < quant - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    quant--;

    cout << "\nO filme posterior \"" << nomeRemovido
         << "\" foi removido com sucesso!\n";
    pausar();
}

//========TASK 6: CONSULTAR O ANTERIOR AO NOME Y============

void consultarAnteriorNome() {
    system("cls");

    if (quant < 2) {
        cout << "\nNao existem filmes suficientes para consultar um anterior!\n";
        pausar();
        return;
    }

    string nomeProcurado = lerTexto("\nInforme o nome do filme: ");
    int posicaoNome = buscarPorNome(nomeProcurado);

    if (posicaoNome == -1) {
        cout << "\nFilme nao encontrado!\n";
        pausar();
        return;
    }

    if (posicaoNome == 0) {
        cout << "\nO filme encontrado e o primeiro e nao possui anterior!\n";
        pausar();
        return;
    }

    int posicaoAnterior = posicaoNome - 1;

    cout << "\nFilme anterior a \"" << vetor[posicaoNome].nome << "\":\n";
    imprimirFilme(vetor[posicaoAnterior], posicaoAnterior);
    pausar();
}

//========TASK 7: IMPRIMIR A LISTA============

void imprimirLista() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
        return;
    }

    cout << "\n========== LISTA DE FILMES ==========\n";

    for (int i = 0; i < quant; i++) {
        imprimirFilme(vetor[i], i);
    }

    cout << "\n-------------------------------------\n";
    cout << "Quantidade de filmes: " << quant << "\n";
    pausar();
}

//========TASK 8: AUMENTAR O PRECO EM 15 POR CENTO============

void aumentarPrecoNome() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
        return;
    }

    string nomeProcurado = lerTexto("\nInforme o nome do filme: ");
    int posicaoNome = buscarPorNome(nomeProcurado);

    if (posicaoNome == -1) {
        cout << "\nFilme nao encontrado!\n";
        pausar();
        return;
    }

    float precoAnterior = vetor[posicaoNome].preco;
    vetor[posicaoNome].preco *= 1.15f;

    cout << fixed << setprecision(2);
    cout << "\nFilme: " << vetor[posicaoNome].nome << "\n";
    cout << "Preco anterior: R$ " << precoAnterior << "\n";
    cout << "Preco atualizado: R$ " << vetor[posicaoNome].preco << "\n";
    pausar();
}

//========TASK 9: CONTAR FILMES POR AVALIACAO============

void contarPorAvaliacao() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
        return;
    }

    float avaliacaoEscolhida = lerReal("\nInforme a avaliacao X (0 a 10): ");
    int contador = 0;

    for (int i = 0; i < quant; i++) {
        if (vetor[i].avaliacao >= avaliacaoEscolhida) {
            contador++;
        }
    }

    cout << "\nQuantidade de filmes com avaliacao maior ou igual a "
         << avaliacaoEscolhida << ": " << contador << "\n";
    pausar();
}

//========TASK 10: IMPRIMIR FILMES DA CATEGORIA X============

void imprimirPorCategoria() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
        return;
    }

    string categoriaProcurada = lerTexto("\nInforme a categoria X: ");
    int encontrados = 0;

    cout << "\nFilmes da categoria \"" << categoriaProcurada << "\":\n";

    for (int i = 0; i < quant; i++) {
        if (textosIguais(vetor[i].categoria, categoriaProcurada)) {
            imprimirFilme(vetor[i], i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "\nNenhum filme encontrado nessa categoria!\n";
    } else {
        cout << "\nQuantidade encontrada: " << encontrados << "\n";
    }

    pausar();
}

//========TASK 11: DISPONIVEIS POR FAIXA ETARIA============

void imprimirDisponiveisPorFaixa() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
        return;
    }

    int faixaEscolhida = lerInteiro("\nInforme a faixa etaria X (0 a 18): ");
    int encontrados = 0;

    cout << "\nFilmes disponiveis com faixa etaria maior ou igual a "
         << faixaEscolhida << ":\n";

    for (int i = 0; i < quant; i++) {
        if (vetor[i].disponivel && vetor[i].faixaet >= faixaEscolhida) {
            imprimirFilme(vetor[i], i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "\nNenhum filme disponivel encontrado para essa faixa!\n";
    } else {
        cout << "\nQuantidade encontrada: " << encontrados << "\n";
    }

    pausar();
}

//========TASK 12: ORDENAR POR ANO DECRESCENTE============

void ordenarPorAnoDecrescente() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
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
    pausar();
}

//========TASK 13: VALOR TOTAL E MEDIA POR CATEGORIA============

void calcularValores() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
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
            if (textosIguais(vetor[j].categoria, vetor[i].categoria)) {
                categoriaJaExibida = true;
                break;
            }
        }

        if (!categoriaJaExibida) {
            float somaCategoria = 0;
            int quantidadeCategoria = 0;

            for (int j = 0; j < quant; j++) {
                if (textosIguais(vetor[j].categoria, vetor[i].categoria)) {
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

    pausar();
}

//========TASK 14: REMOVER FILME PELO NOME============

void remocaoNome() {
    system("cls");

    if (quant == 0) {
        cout << "\nO catalogo esta vazio!\n";
        pausar();
        return;
    }

    string nomeProcurado = lerTexto("\nQual filme deseja remover? ");
    int posicao = buscarPorNome(nomeProcurado);

    if (posicao == -1) {
        cout << "\nFilme nao encontrado!\n";
        pausar();
        return;
    }

    string nomeRemovido = vetor[posicao].nome;

    for (int i = posicao; i < quant - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    quant--;

    cout << "\nFilme \"" << nomeRemovido << "\" removido com sucesso!\n";
    pausar();
}

//========MENU PRINCIPAL============

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int opcao;

    do {
        system("cls");
        cout << "\t--------- CATÁLOGO DE FILMES --------- \n\n";
        cout << "\t*** MENU INICIAL ***\n";
        cout << "\tSelecione uma opção:\n";
        cout << "\t1  - Inserir novo filme no início\n";
        cout << "\t2  - Inserir um filme na posição k\n";
        cout << "\t3  - Alterar o filme posterior à posição k\n";
        cout << "\t4  - Procurar filme pelo ID e remover o posterior\n";
        cout << "\t5  - Consultar o filme anterior ao nome escolhido\n";
        cout << "\t6  - Imprimir lista\n";
        cout << "\t7  - Aumentar em 15% o preço do filme escolhido\n";
        cout << "\t8  - Quantidade de filmes por avaliação\n";
        cout << "\t9  - Imprimir filmes da categoria escolhida\n";
        cout << "\t10 - Filmes disponíveis por faixa etária\n";
        cout << "\t11 - Ordem decrescente de filmes por ano\n";
        cout << "\t12 - Valor total e média por categoria\n";
        cout << "\t13 - Remover filme pelo nome\n";
        cout << "\t0  - Sair\n";

        opcao = lerInteiro("\n\tInforme uma opção (0 a 13): ");

        switch (opcao) {
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
                cout << "\nOpcao invalida! Use um numero de 0 a 13.\n";
                pausar();
                break;
        }
    } while (opcao != 0);

    return 0;
}
