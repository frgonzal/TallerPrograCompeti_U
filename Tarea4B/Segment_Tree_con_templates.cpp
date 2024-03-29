#include <bits/stdc++.h>

using namespace std;

template <class T, T merge(T,T)>
struct segment_tree{
  int N;
  vector <T> tree;
  segment_tree(int _N){
    N = _N;
    tree.resize(4*N);
    build(0, 0, N-1);
  }

  segment_tree(vector <T> &A){
	  N = int(A.size());
	  tree.resize(4*N);
	  build(0, 0, N-1, A);
  }

  void build(int n, int i, int j){
    if(i == j){
      tree[n] = T(); // initial value
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid);
    build(2*n+2, mid+1, j);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  void build(int n, int i, int j, vector <T> &A){
    if(i == j){
      tree[n] = A[i]; // initial value
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid, A);
    build(2*n+2, mid+1, j, A);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  T query(int l, int r){
    return query(0, 0, N-1, l, r);
  }

  T query(int n, int i, int j, int l, int r){
    if(l <= i && j <= r) return tree[n];
    int mid = (i+j)/2;
    if(mid < l || r < i)
      return query(2*n+2, mid+1, j, l, r);
    if(j < l || r < mid+1)
      return query(2*n+1, i, mid, l, r);
    return merge(
        query(2*n+1, i, mid, l, r),
        query(2*n+2, mid+1, j, l, r));
  }

  void update(int t, T val){
    update(0, 0, N-1, t, val);
  }
  
  void update(int n, int i, int j, int t, T val){
    if(t < i || j < t) return;
    if(i == j){
      tree[n] = val;
      return;
    }
    int mid = (i+j)/2;
    update(2*n+1, i, mid, t, val);
    update(2*n+2, mid+1, j, t, val);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }
};

int merge(int a, int b){
  return min(a,b);
}

int main(){
  vector <int> a = {1, 2, 3, 4};

  segment_tree <int, merge> st(a);
  cout << st.query(0, 3) << '\n';
}
