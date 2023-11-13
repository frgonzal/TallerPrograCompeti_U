#include <bits/stdc++.h>

int large = 1e9;

using namespace std;

struct segment_tree{

    int N;
    vector <int> tree;
    
    segment_tree(vector <int> &A){
        // constructor
        N = A.size();
        tree.resize(4*N);
        build(0, 0, N-1, A);
    }

    int merge(int a, int b){
        if (a > b)
            return b;
        return a;
    }

    void build(int n, int i, int j, vector <int> &A){
        // n: indice del nodo
        // nodo mira segmento [i,j]
        if(i == j){
            tree[n] = A[i];
            return;
        }
        int mid = (i+j)/2;
        // hijo izq: 2n+1
        // hijo der: 2n+2
        build(2*n+1, i, mid, A);
        build(2*n+2, mid+1, j, A);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }

    int query(int l, int r){
        return query(0, 0, N-1, l, r);
    }

    int query(int n, int i, int j, int l, int r){
        // nodo actual mira intervalo [i,j]
        // queremos responder consulta [l,r]
        // caso 1: contenido totalmente
        if(l <= i && j <= r){
            return tree[n];
        }
        // caso 2: [i,j] está fuera de [l,r]
        if(j < l || r < i){
            return large;
        }
        // caso 3: contenido parcialmente
        int mid = (i+j)/2;
        return merge(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
    }

    void update(int idx, int x){
        // A[idx] = x
        update(0, 0, N-1, idx, x);
    }

    void update(int n, int i, int j, int idx, int x){
        // no contiene a idx
        if(idx < i || idx > j){
            return;
        }
        if(i == j){
            tree[n] = x;
            return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, idx, x);
        update(2*n+2, mid+1, j, idx, x);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, q;
    cin>>n>>q;

    vector <int> a(n);

    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        a[i] = p;
    }

    segment_tree st(a);

    while(q--){
        int consulta;
        cin>>consulta; 

        if(consulta==1){
            int i, x;
            cin>>i>>x;
            st.update(i-1, x);
        }else{
            int i, j;
            cin>>i>>j;
            cout << st.query(i-1,j-1)<<"\n";
        }
    }
    return 0;
}