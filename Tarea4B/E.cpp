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
        return (a & b);
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
        //cout<<n<<"::"<<tree[n]<<endl;
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
            return ~0;
        }
        // caso 3: contenido parcialmente
        int mid = (i+j)/2;
        return merge(
            query(2*n+1, i,     mid, l, r),
            query(2*n+2, mid+1, j,   l, r)
        );
    } 

    int maximo(int l, int x){
        int i, j, mid, val;
        l--;
        i = l;
        j = N-1;

        while(i < j){
            mid = (i+j+1)/2;
            val = query(l, mid);

            //cout<< l<<" "<< mid<< endl;
            //cout<< val << endl;

            if(val<x) j=mid-1;
            else i=mid;
            //cout<<endl<<val<<" :: "<<(val<x)<<endl;
        }

        //cout << query(l, i)<<endl;
        if(query(l, i) < x)
            return -1;
        return i+1;
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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector <int> a(n);
        for(int i=0; i<n; i++){
            int p; cin>>p;
            a[i] = p;
        }
        segment_tree st(a);

        int q; cin>>q; 
        while(q--){
            int l, x;
            cin>>l>>x;
            cout<<st.maximo(l, x)<<endl;
        }
    }
    return 0;
}