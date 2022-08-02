#include <iostream>
#include <algorithm>
#include "heap.h"
#include "cliente.h"
//metodos utilizados para inclusao dos arquivos

int main(){

    Cliente c1(20,"c1");        //declarando cliente c1
    Cliente c2(80,"c2");        //declarando cliente c2
    Cliente c3(40,"c3");        //declarando cliente c3
    Cliente c4(50,"c4");        //declarando cliente c4
    Cliente c5(10,"c5");        //declarando cliente c5
    Cliente c6(25,"c6");        //declarando cliente c6
    Cliente c7(35,"c7");        //declarando cliente c7
    Cliente c8(60,"c8");        //declarando cliente c8
    Cliente c9(45,"c9");        //declarando cliente c9

    Heap h;     //declara classe h que é um heap

    h.inserir(c1);      //insere o cliente c1 atraves do metodo inserir do heap
    h.mostraclient();   //imprime os clientes incluidos no heap atraves do metodo mostraclient do Heap
    h.inserir(c2);      //insere o cliente c2 atraves do metodo inserir do heap
    h.inserir(c3);      //insere o cliente c3 atraves do metodo inserir do heap
    h.inserir(c4);      //insere o cliente c4 atraves do metodo inserir do heap
    h.inserir(c5);      //insere o cliente c5 atraves do metodo inserir do heap
    h.inserir(c6);      //insere o cliente c6 atraves do metodo inserir do heap
    h.inserir(c7);      //insere o cliente c7 atraves do metodo inserir do heap
    h.inserir(c8);      //insere o cliente c8 atraves do metodo inserir do heap
    h.inserir(c9);      //insere o cliente c9 atraves do metodo inserir do heap
    h.mostraclient();   //imprime os clientes incluidos no heap atraves do metodo mostraclient do Heap

    cout << "\n" << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" <<  "\n" << endl;       //separaçao para melhor vizualizaçao do codigo 

    h.remover();          //remove o primeiro cliente do heap atraves do metodo remover do Heap
    h.mostraclient();     //imprime os clientes incluidos no heap atraves do metodo mostraclient do Heap
    cout << "\n" << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" <<  "\n" << endl;      //separaçao para melhor vizualizaçao do codigo 
    h.remover();          //remove o primeiro cliente do heap atraves do metodo remover do Heap
    h.remover();          //remove o primeiro cliente do heap atraves do metodo remover do Heap
    h.remover();          //remove o primeiro cliente do heap atraves do metodo remover do Heap
    h.mostraclient();     //imprime os clientes incluidos no heap atraves do metodo mostraclient do Heap

    return 0;
}