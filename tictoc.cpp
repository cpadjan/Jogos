//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
#include <iostream>
#include <string> // trabalhar com strings
#include <locale.h> // confgura idioma igual ao do sistema
//#include <new> // gerencia memoria
//#include <fstream>> // acessa, ler e cria arquivos
#include <windows.h>
#include <algorithm> // for using transform
#include <cctype> // for using toupper


using namespace std;

void limpaTela(){
    //Limpa a tela
    system("CLS");
}

void maximizarJanelaConsole() {
    //Maximiza a tela
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    }

void titulo(string mensagem){

// Titulo do jogo e lugar onde as instruções que o jogar vai precisar durante o jogo
cout << R"(
 _____                                         _____
( ___ )                                       ( ___ )
 |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
 |   |  _____ _                _____           |   |
 |   | |_   _(_) ___          |_   _|__   ___  |   |
 |   |   | | | |/ __|  _____    | |/ _ \ / __| |   |
 |   |   | | | | (__  |_____|   | | (_) | (__  |   |
 |   |   |_| |_|\___|           |_|\___/ \___| |   |
 |   |                                         |   |
 |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
(_____)                                       (_____)
)" << '\n';
    cout << "\n";
    cout << mensagem ;
}

void montarTabuleiro (string tabuleiro[12][12]){

    // cria um tabuleiro utilizando uma matriz 12 x 12 para deixar a matriz do jogo 3x3 mais centralizada
    int linha, coluna;

    for(linha = 0; linha < 12; linha++){
        for(coluna = 0; coluna < 12; coluna++){
            tabuleiro[linha][coluna] = "   ";
        }
    }

    tabuleiro[4][5] = " _ "; // 7
    tabuleiro[4][6] = " _ "; // 8
    tabuleiro[4][7] = " _ "; // 9
    tabuleiro[5][5] = " _ "; // 4
    tabuleiro[5][6] = " _ "; // 5
    tabuleiro[5][7] = " _ "; // 6
    tabuleiro[6][5] = " _ "; // 1
    tabuleiro[6][6] = " _ "; // 2
    tabuleiro[6][7] = " _ "; // 3

    tabuleiro[9][5] = " 7 ";
    tabuleiro[9][6] = " 8 ";
    tabuleiro[9][7] = " 9 ";
    tabuleiro[10][5] = " 4 ";
    tabuleiro[10][6] = " 5 ";
    tabuleiro[10][7] = " 6 ";
    tabuleiro[11][5] = " 1 ";
    tabuleiro[11][6] = " 2 ";
    tabuleiro[11][7] = " 3 ";
}

void exibeTabuleiro (string tabuleiro[12][12]){

    // exibe o tabuleiro na tela
    int linha, coluna;

    for(linha = 0; linha < 12; linha++){
        for(coluna = 0; coluna < 12; coluna++){
            cout << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }


}

void marcaTabuleiro (string tabuleiro[12][12], int nrEscolhido, int jogadorRodada){

    // coloca o X ou 0 dependendo de qual jogar fez a jogada
    // x - letra x maiuscula
    // 0 - número zero

    string mensagem = "Utilize os números para escolher onde jogar.";

    switch (nrEscolhido){
        case 1:
            if (jogadorRodada == 1){
                tabuleiro[6][5] = " X ";
                tabuleiro[11][5] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[6][5] = " 0 ";
                tabuleiro[11][5] = "   ";
            }
            break;
        case 2:
            if (jogadorRodada == 1){
                tabuleiro[6][6] = " X ";
                tabuleiro[11][6] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[6][6] = " 0 ";
                tabuleiro[11][6] = "   ";
            }
            break;
        case 3:
            if (jogadorRodada == 1){
                tabuleiro[6][7] = " X ";
                tabuleiro[11][7] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[6][7] = " 0 ";
                tabuleiro[11][7] = "   ";
            }
            break;
        case 4:
            if (jogadorRodada == 1){
                tabuleiro[5][5] = " X ";
                tabuleiro[10][5] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[5][5] = " 0 ";
                tabuleiro[10][5] = "   ";
            }
            break;
        case 5:
            if (jogadorRodada == 1){
                tabuleiro[5][6] = " X ";
                tabuleiro[10][6] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[5][6] = " 0 ";
                tabuleiro[10][6] = "   ";
            }
            break;
        case 6:
            if (jogadorRodada == 1){
                tabuleiro[5][7] = " X ";
                tabuleiro[10][7] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[5][7] = " 0 ";
                tabuleiro[10][7] = "   ";
            }
            break;
        case 7:
            if (jogadorRodada == 1){
                tabuleiro[4][5] = " X ";
                tabuleiro[9][5] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[4][5] = " 0 ";
                tabuleiro[9][5] = "   ";
            }
            break;
        case 8:
            if (jogadorRodada == 1){
                tabuleiro[4][6] = " X ";
                tabuleiro[9][6] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[4][6] = " 0 ";
                tabuleiro[9][6] = "   ";
            }
            break;
        case 9:
            if (jogadorRodada == 1){
                tabuleiro[4][7] = " X ";
                tabuleiro[9][7] = "   ";
            }
            if (jogadorRodada == 2){
                tabuleiro[4][7] = " 0 ";
                tabuleiro[9][7] = "   ";
            }
            break;
    }

    limpaTela();
    titulo(mensagem);
    exibeTabuleiro(tabuleiro);

}

int verificaPosicao (string tabuleiro[12][12], int nrEscolhido){

        // verifica se a posição que o jogar escolheu pode ou nao receber a marcação
        switch (nrEscolhido){
        case 1:
            if (tabuleiro[6][5] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 2:
            if (tabuleiro[6][6] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 3:
            if (tabuleiro[6][7] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 4:
            if (tabuleiro[5][5] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 5:
            if (tabuleiro[5][6] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 6:
            if (tabuleiro[5][7] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 7:
            if (tabuleiro[4][5] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 8:
            if (tabuleiro[4][6] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
        case 9:
            if (tabuleiro[4][7] == " _ "){
                    return 1;
            }
            else{
                return 0;
                }
            break;
    }


}

int verificaVencedor (string tabuleiro[12][12]){

    // verificar se o jogar venceu a partida

    int linha=0, coluna=0;

    // Verifica as linhas

    for (linha=4; linha < 7; linha++ ){
        if (tabuleiro[linha][5] == " X " && tabuleiro[linha][5] == tabuleiro[linha][6] && tabuleiro[linha][6] == tabuleiro[linha][7]) {
            return 1;
        }else if (tabuleiro[linha][5] == " 0 " && tabuleiro[linha][5] == tabuleiro[linha][6] && tabuleiro[linha][6] == tabuleiro[linha][7]) {
            return 2;
        }
    }

    // Verifica as colunas
    for (coluna=5; coluna < 8; coluna++ ){
        if (tabuleiro[4][coluna] == " X " && tabuleiro[4][coluna] == tabuleiro[5][coluna] && tabuleiro[5][coluna] == tabuleiro[6][coluna]) {
            return 1;
        }else if (tabuleiro[4][coluna] == " 0 " && tabuleiro[4][coluna] == tabuleiro[5][coluna] && tabuleiro[5][coluna] == tabuleiro[6][coluna]) {
            return 2;
        }
    }

    // Verifica a primeira trasnversal

    if (tabuleiro[4][5] == " X " && tabuleiro[4][5] == tabuleiro[5][6] && tabuleiro[5][6] == tabuleiro[6][7]){
        return 1;
    }else if(tabuleiro[4][5] == " 0 " && tabuleiro[4][5] == tabuleiro[5][6] && tabuleiro[5][6] == tabuleiro[6][7]){
        return 2;
    }


    // Verifica a segunda trasnversal

    if (tabuleiro[4][7] == " X " && tabuleiro[4][7] == tabuleiro[5][6] && tabuleiro[5][6] == tabuleiro[6][5]){
        return 1;
    }else if(tabuleiro[4][7] == " 0 " && tabuleiro[4][7] == tabuleiro[5][6] && tabuleiro[5][6] == tabuleiro[6][5]){
        return 2;
    }




}

//declara a função que será utilizada
void menu_inicial();

void jogo(string jogadorUm, string jogadorDois){

    // mecanica do jogo

    string mensagem = "Utilize os números para escolher onde jogar.";
    string tabuleiro[12][12];
    int nrEscolhido, jogadorRodada, tentativa = 0, jogadas = 0;
    char jogoNovo;



    limpaTela();
    titulo(mensagem);

    montarTabuleiro(tabuleiro);
    exibeTabuleiro(tabuleiro);

    // faz com que o jogo so acabe quando 1 jogador vencer
    while (jogadas == 0){

        // jogador 1
        while (tentativa == 0){

            cout <<"\n\n" << jogadorUm << ", escolha um número para marcar o ' X ': ";
            cin.sync();
            cin >> nrEscolhido;
            jogadorRodada = 1;

            if (verificaPosicao(tabuleiro, nrEscolhido) == 1){
                marcaTabuleiro(tabuleiro, nrEscolhido, jogadorRodada);
                tentativa = 1;

            }else{
                mensagem = "Número ja escolhido tente novamente";
                tentativa = 0;
            }

        limpaTela();
        titulo(mensagem);
        exibeTabuleiro(tabuleiro);

        }


        if (verificaVencedor(tabuleiro) == 1){
            mensagem = ("Jogador " + jogadorUm + " venceu!" );
            limpaTela();
            titulo(mensagem);
            exibeTabuleiro(tabuleiro);
            jogadas = 1;
            tentativa = 0;
            cout <<"\n\n Deseja jogar novamente ? (S/N): ";
            cin.sync();
            cin >> jogoNovo ;
            if (jogoNovo == 'S' || jogoNovo == 's'){
                jogo(jogadorUm, jogadorDois);
                }

                else {
                    limpaTela();
                    mensagem = "Bem vindo ao jogo! ";
                    titulo(mensagem);
                    menu_inicial();
                }
        }


        tentativa = 0; // zera o marcador de tentativas, possibilita que o jogador dois começe suas tentativas

        //jogador 2
        while (tentativa == 0){


            cout <<"\n\n" << jogadorDois << ", escolha um número para marcar o ' 0 ': ";
            cin.sync();
            cin >> nrEscolhido;
            jogadorRodada = 2;

            if (verificaPosicao(tabuleiro, nrEscolhido) == 1){
                marcaTabuleiro(tabuleiro, nrEscolhido, jogadorRodada);
                tentativa = 1;
            }else{
                mensagem = "Número ja escolhido tente novamente";
                tentativa = 0;
            }

        limpaTela();
        titulo(mensagem);
        exibeTabuleiro(tabuleiro);
        }

        if (verificaVencedor(tabuleiro) == 2){
            mensagem = ("Jogador " + jogadorDois + " venceu!" );
            limpaTela();
            titulo(mensagem);
            exibeTabuleiro(tabuleiro);
                        jogadas = 1;
            tentativa = 0;
            cout <<"\n\n Deseja jogar novamente ? (S/N): ";
            cin.sync();
            cin >> jogoNovo ;
            if (jogoNovo == 'S' || jogoNovo == 's'){
                jogo(jogadorUm, jogadorDois);
                }

                else {
                    limpaTela();
                    mensagem = "Bem vindo ao jogo! ";
                    titulo(mensagem);
                    menu_inicial();
                }


        }


        tentativa = 0;


    }



}


void sobre (){

    int opcao ;
    string mensagem = "Sobre o Jogo";

    limpaTela();

    titulo(mensagem);

    cout << "\n\nFonte da arte: https://www.asciiart.eu/text-to-ascii-art";
    cout << "\n\nVersão 1.0";
    cout << "\n\n\n\n Digite 1 - volta ao menu ou 2 - sai do programa: ";
    cin >> opcao ;

    if (opcao == 1){
        limpaTela();
        titulo(mensagem="Bem Vindo ao jogo");
        menu_inicial();
    }else if (opcao == 2){
    exit(0);
    }else(
          sobre()
          );



}


void menu_inicial(){

    int opcao = 0;
    string jogadorUm, jogadorDois;
    string mensagem = "Bem vindo ao jogo! ";

    while (opcao < 1 || opcao > 3){

        cout << "\nEscolha uma opção: ";
        cout << "\n1 - Novo Jogo";
        cout << "\n2 - Sobre o Jogo";
        cout << "\n3 - Sair";

        cout << "\nOpcão: ";
        cin >> opcao;

        switch (opcao){
            case 1:
                mensagem = "\nOpção 1 - Novo Jovo";
                limpaTela();
                titulo(mensagem);

                cout << "\nDigite o nome do player 1 (X): ";
                cin.sync();
                getline(cin, jogadorUm);
                transform(jogadorUm.begin(), jogadorUm.end(), jogadorUm.begin(),::toupper);

                cout << "\nDigite o nome do player 2 (0): ";
                cin.sync();
                getline(cin, jogadorDois);
                transform(jogadorDois.begin(), jogadorDois.end(), jogadorDois.begin(),::toupper);

                jogo(jogadorUm, jogadorDois);

                break;
            case 2:
                limpaTela();
                titulo(mensagem);
                cout << "Opção 2 - Sobre";
                sobre();
                break;
            case 3:
                limpaTela();
                cout << "Ate mais !\n\n";
                // pausa o sistema
                system("pause");
                exit(0);
                break;
            }

    }

}


int main(){

    /*Para usar acentos e formato em ptb-BR
    */
    setlocale(LC_ALL, "");

    ///Variaveis
    int opcaoEscolhida ;
    string jogadorUm, jogadorDois, mensagem = "";

    maximizarJanelaConsole();

    titulo(mensagem);

    menu_inicial();


    // pausa o sistema
    system("pause");



    return 0;
}

