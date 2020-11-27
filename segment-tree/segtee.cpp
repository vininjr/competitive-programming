#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vet[maxn], tree[4*maxn];

// Os parametros da função build são:
// O índice do nó atual, o l e o r do intervalo representado pelo nó. 
void build(int node, int l, int r){
    // Se o nó atual é uma folha:
    // O valor desse nó é simplesmente vet[l], ou vet[r], e então retorno a função.
    if(l==r){
        tree[node]=vet[l];
        return;
    }
    // Caso contrário, declararemos mid como o índice que divide o nó atual em duas metades.
    int mid = (l+r)/2;
    // Chamaremos a função build para as duas metades, que são:
    // O filho da esquerda: Com nó 2*node+1 e com intervalo de l até mid.
    // O filho da direita: Com nó 2*node+2 e com intervalo mid+1 até r.
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    // Após termos calculado a resposta dos dois filhos do nó atual
    // saberemos a resposta dele, que é a soma dos valores dos seus filhos.
    // Lembrando que 2*node+1 é o nó do filho da esquerda e 2*node+2 o da direita.
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

// Os parametros da função Update são:
// O nó atual, tl e tr, o intervalo que o nó atual abrange, idx e x, o índice que queremos atualizar e o seu valor.
void update(int node, int tl, int tr, int idx, int x){
    // Se o nó atual é uma folha, então ele representa o intervalo de idx até idx.
    // Então, atualizaremos o seu valor e retornaremos a função.
    if(tl==tr){
        tree[node]=x;
        vet[l]=x;
        return;
    }
    // Caso contrário, declararemos mid como o índice que divide o nó atual em duas metades.
    int mid = (tl+tr)/2;
    // Se idx se encontra no intervalo de tl até mid, atualizaremos o filho da esquerda
    // do nó atual, pos ele abrange o intervalo de tl até mid.
    // Senão, então ele se encontra de mid+1 até r, então:
    // Basta atualizarmos o filho da direita do nó atual.
    if(tl<=idx and idx<=mid) update(2*node+1,tl,mid,idx,v);
    else update(2*node+2,mid+1,tr,idx,v);
    // Após termos atualizado um dos dois filhos, atualizaremos o valor do nó atual.
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

// Os parametros da função Query são:
// O nó atual, tl e tr, o intervalo que o nó atual abrange, l e r, o intervalo que queremos calcular.
int query(int node, int tl, int tr, int l, int r){
    // Se o intervalo que o nó atual abrange estiver totalmente fora do intervalo de l até r, retornaremos 0.
    // Então, ou o início do intervalo do nó atual é maior que o fim dp intervalo que queremos calcular, ou
    // o fim do intervalo do nó atual é menor que o início do intervalo que queremos calcular.
    if(r<tl or l>tr) return 0;
    // Se o intervalo que o nó atual representa estiver totalmente dentro do intervalo de l até r, então
    // retornaremos o valor do nó atual.
    if(l<=tl and r>=tr) return tree[node];
    // Caso contrário, declararemos mid como o índice que divide o nó atual em duas metades.
    int mid = (tl+tr)>>1;
    // Retornamos como resposta a soma da resposta dos filhos do nó atual.
    return query(2*node+1, tl, mid, l, r)+query(2*node+2, mid+1, tr, l, r);
}

