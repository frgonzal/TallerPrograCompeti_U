#include <bits/stdc++.h>

int large = 1e9;

using namespace std;

struct segment_tree{

    int N;
    vector <int> tree;
    
    segment_tree(vector <int> &A){
        // constructor
        N = A.size();
        tree.resize(2*N-1);
        build(0, 0, N-1, A);
    }

    int merge(int a, int b){
        return a+b;
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

    int query(int idx){
        return query(0, 0, N-1, idx);
    }

    int query(int n, int i, int j, int idx){
        if(i >= j)
            return i;

        int left = tree[2*n+1];

        int mid = (i+j)/2;

        if (left >= idx)
            return query(2*n+1, i, mid, idx);

        return query(2*n+2, mid+1, j, idx-left);
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

    int n;
    cin>>n;

    int N=1;
    while(N<n)
        N*=2;

    vector <int> a(N, 0);
    vector <int> b(n);

    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        b[i] = p;
        a[i] = 1;
    }
    segment_tree st(a);

    for(int k=0; k<n; k++){
        int p;
        cin>>p;
        int i = st.query(p);
        cout<<b[i] << endl;
        st.update(i, 0);
    }

    return 0;
}