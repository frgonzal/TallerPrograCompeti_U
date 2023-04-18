#include <bits/stdc++.h>
using namespace std;


set<int> X;
set<int> Y;
map<int,int> X_pos;
map<int,int> Y_pos;
vector<vector<int>> Grafo;





int main(){
    int n;cin>>n;
    for (int i=0; i<n; i++){
        int x,y;cin>>x>>y;

        auto itrx = X.find(x);
        auto itry = Y.find(y);
        if (itrx!=X.end() && itry!=Y.end()){
            Grafo[i].push_back(X_pos[x]);
            Grafo[i].push_back(Y_pos[y]);
            Grafo[X_pos[x]].push_back(i);
            Grafo[Y_pos[y]].push_back(i);
        }else if(itrx!=X.end()){
            int pos = X_pos[x];
            Y.insert(y);
            Y_pos[y] = pos;
            Grafo[i].push_back(pos);
        }else if(Y.find(y)!=Y.end()){
            int pos = Y_pos[y];
            X.insert(x);
            X_pos[x] = pos;
            Grafo[i].push_back(pos);
        }else{
            X.insert(x);  Y.insert(y);
            X_pos[x] = i; Y_pos[y] = i;
        }
    }
    return 0;
}