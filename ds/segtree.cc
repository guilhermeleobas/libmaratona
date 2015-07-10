int segtree[300010];
int vetor[100100];
    
void inicializa (int node, int l, int r){

    if (l > r) return;

    if (l == r){
        segtree[node] = vetor[r];
    }
    else {
        inicializa (2*node+1, l, (l+r)/2);
        inicializa (2*node+2, (l+r)/2+1, r);

        segtree[node] = max (segtree[2*node+1],segtree[2*node+2]);
    }

}

void update (int node, int l, int r, int x){

    if (l > r || l > x || r < x)
        return;

    if (l == x && r == x){
        segtree[node] = vetor[l];
        return;
    }

    update (2*node+1, l, (l+r)/2, x);
    update (2*node+2, (l+r)/2+1, r, x);

    // Condição: pai = max (fllho1, filho2);
    segtree[node] = max(segtree[2*node+1], segtree[2*node+2]);
}

int query (int node, int l, int r, int i, int j){

    int p1, p2;

    //size overflow;
    if (l > r || l > j || r < i)
        return 0;

    //Intervalo incluido
    if (l >= i && r <= j)
        return segtree[node];

    //
    p1 = query (2*node+1, l, (l+r)/2, i, j); 
    p2 = query (2*node+2, (l+r)/2+1, r, i, j);

    // Condição: pai = max (fllho1, filho2);
    return (max(p1, p2));
}
