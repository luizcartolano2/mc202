//
//
//    Created by Luiz Cartolano
//    RA: 183012
//
//
#include"lab.h"

int arv_print(arv *Arv){
    /*Funcao que imprime a árvore em pós-ordem, isto é, primeiro verificamos se o no
    requisitado existe ou nao, caso ele exista chamamos a funcao para o filho da esquerda,
    assim, percorreremos todo o lado esquerdo da arvore, depois disso, percorreremos o lado direito
    e por fim imprimiremos o no principal*/
    /*A funcao e do tipo int para podermos calcular a altura da arvore ao mesmo tempo em que
    a imprimimos, o que facilitara a funcao responsavel por imprimir a arvore em largura*/
    int u,v;

    if(Arv == NULL)
      return -1;

    u =  arv_print(Arv->left);
    v =  arv_print(Arv->right);
    printf("%c",Arv->data);
    if(u > v)
      return u+1;
      else
        return v+1;

}
arv* arv_lib(arv *Arv){
  /*Funcao que libera a árvore em pós-ordem, isto é, primeiro verificamos se o no
  requisitado existe ou nao, caso ele exista chamamos a funcao para o filho da esquerda,
  assim, percorreremos todo o lado esquerdo da arvore, depois disso, percorreremos o lado direito
  e por fim liberamos o no principal*/

  if(Arv != NULL){
    arv_lib(Arv->left);
    arv_lib(Arv->right);
    free(Arv);
  }
  return NULL;
}
arv* arv_build(char ordem[], char pre[], int ordem_in, int ordem_fim){
  /* Funcao recursiva que constroi uma arvore binaria a partir
     de em-ordem ordem[] e PreOrdem pre[].  Valores iniciais de
     ordem_in e ordem_fim sao 0 e tam - 1.*/
  int i, ordemIndice;

  /*caso a arvore nao exista(o q eu acho q n acontece nesse lab)*/
  if(ordem_in > ordem_fim)
     return NULL;

  /*Visto que o algoritmo de pre ordem visita primeiro a raiz, esse será
    o primeiro elemento q acessaremos (a partir da variavel ordemIndice, essa
    é do tipo global para q n a perdemos entre as chamadas da funcao) e
    pois na proxima vez q ela for chamada, devemos considerar o proximo elemento
    como nó raiz */
  arv* Arv = (struct arv*)malloc(sizeof(struct arv));
  Arv->data = pre[preIndice];
  Arv->left = NULL;
  Arv->right = NULL;
  preIndice++;

  /* Caso o nó não possua filhos, retorná-lo-emos*/
  if(ordem_in == ordem_fim)
    return Arv;

  /* Caso ela possua filhos, devemos achar a posicao do nó raiz atual na impressao
  em ordem, para que assim possamos descobrir quem e o "filho da esquerda" e depois
  o "filho da direita"*/
  i = ordem_in;
  while(ordem[i] != (Arv->data)){
      i++;
    };
  ordemIndice = i;

  /*Chamamos primeiro a funcao para o no esquerdo pois assim, quando
  comecarmos a construir o lado direito da arvore ja teremos percorrido
  todo o lado esquerdo na sequencia da pre-ordem*/
  Arv->left = arv_build(ordem, pre, ordem_in, ordemIndice - 1);
  Arv->right = arv_build(ordem, pre, ordemIndice + 1, ordem_fim);

  return Arv;
}
void arv_size(arv *Arv, int level){
  //primeiro verificamos se a arvore existe
  if(Arv == NULL)
    return;

  //aqui temos o caso base da nossa funcao
  if(level == 1)
    printf("%c",Arv->data);

  /*se nao estivermos no caso base, chamamos a funcao para os no filho da esquerda
  e tiramos um de "level" de modo que quando chegarmos ao caso base estaremos no
  nivel necessario. Faremos o mesmo para o lado direito*/
  else if(level > 1){
    arv_size(Arv->left,level-1);
    arv_size(Arv->right,level-1);
  }

}
