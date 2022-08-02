#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define MAX_ALUNOS 20
#include "cliente.h"
//metodos utilizados para inclusao dos arquivos

using namespace std;

class Heap{     //cria a classe Heap
public: 

    void descer(int i){     //recebe 1 como parametro inicialmente 
        int j;
        j =2 * i;       //j=2 inicialmente
        if( j <= n ){       //checa se j e menor ou igual n, se nao ocorrer nao e necessario alteraçao
            if( j < n ){    //se j for menor que n é necessario checar se a chave do vetor na posiçao j+1 é maior que a chave na posicao
                            //j, pois se ocorrer é necessario incrementar o j para checar outras posicoes do Heap
                if(T[j + 1].chave > T[j].chave){
                    j++;
                }
            }
            if(T[i].chave < T[j].chave){        //checa se a chave na posicao i é menor que a chave na posicao j para realizar a troca 
                                                //das chaves no Heap
                swap (T[i],T[j]);
                descer(j);                   //chama a funcao descer novamente para checar se e necessario fazer mais movimentacoes no Heap
                                             //usando o j como parametro(semelhante a uma recursao)
            }
        }
    }

    void subir (int i){     //recebe o contador como parametro
        int j;              //declara a variavel j, que ira receber i/2
        j=i/2;
        if (j >= 1){        //checa se j  é maior ou igual a 1
            if (T[i].chave > T[j].chave) {  //checa se a chave da posicao i é maior que a da posiçao j
                swap (T[i],T[j]);           //se ocorrer significa que é necessario trocar a posicao no vetor do Cliente i com o j
                subir(j);               //chama a funcao subir novamente para checar se e necessario fazer mais movimentacoes no Heap
                                        //usando o j como parametro(semelhante a uma recursao)
            }
        }   
    }
    
    void inserir (const Cliente & client){      //funcao para inserir o cliente no Heap, recebe o cliente a ser inserido como parametro
        T[n+1]= client;     //vetor Cliente recebe o cliente a ser incluido
        n++;                //incremento no contador
        subir(n);       //chama a funçao subir
    }

    void remover(){        //funcao que ira remover o cliente com maior prioridade
        T[1]=T[n];         //o ultimo elemento do Heap passa a ser o primeiro 
        n--;               //é diminuido o tamanho do vetor, e consequentemente o ultimo elemento que estaria se repetindo é eliminado
        descer(1);         //chamada a funcao descer, que funciona semelhantemente a funçao subir
    }

    void mostraclient(){        //funcao para imprimir as chaves, nomes e posicao dos clientes no terminal
            for(int k=1; k <= n ; k++){
            cout << "chave: "  << T[k].chave << "\n" << "nome: " << T[k].nome  <<" \n" << "posicao: " << k << "\n" <<endl;
            cout << "-------------------------" << endl;
            }
        }
    
    Cliente seleciona(){        //funcao para retornar copia do cliente com maior prioridade
        return T[1];
    }

    Cliente T[MAX_ALUNOS +1];  //declara um vetor do tipo Cliente de tamanho 21
    int n=0;    //declaraçao davariavel que ira ser usada para mecher nas posiçoes do vetor(contador)

};
#endif


/*exemplificaçoes: 

*iserçoes(is):

is:80         subir80      is:40           is:50          subir50         is:10             is:25               is:35
    20         80           80              80              80              80              80                   80
   /    ->    /     ->     /  \     ->     /  \     ->     /  \     ->     /   \    ->     /   \      ->        /   \
 80         20           20   40         20   40         50    40         50   40        50     40            50     40
                                         /               /               /  \           /  \    /            /  \    / \
                                        50             20               20   10       20   10  25          20   10  25  35

            80                  80                 80                       80                      
->        /    \       ->      /  \     ->        /   \         ->         /   \             
        50      40           50    40           60     40                60     40
       /   \    / \          / \   / \          / \    / \              /  \    / \
     20    10  25  35      60  10 25  35      50  10  25  35          50   10  25  35
     /                     /                  /                       / \
    60                   20                 20                      20  45

*primeira remoçao: 

             45                  60               60
            /   \       ->     /    \     ->     /   \     
           60    40          45      40         50    40
          /  \   / \        /  \    /  \       /  \   /  \
        50   10 25  35    50    10 25   35    45  10 25  35
        /                 /                  / 
      20                20                  20
*/