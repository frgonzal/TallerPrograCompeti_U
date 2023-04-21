#include <bits/stdc++.h>
using namespace std;

map<int,int> X_pos;
map<int,int> Y_pos;
vector<vector<int>> Grafo;
vector<int> visited;
int conexos = -1;

void DFS(int coord){
    stack<int> Pila;
    Pila.push(coord);
    
    while(!Pila.empty()){
        int coord1 = Pila.top();Pila.pop();
        visited[coord1] = 1;

        for(int coord2: Grafo[coord1]){
            if(visited[coord2]==0){
                visited[coord2]=1;
                Pila.push(coord2);}
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    Grafo.assign(n,vector<int>());
    visited.assign(n,0);
    for (int i=0; i<n; i++){
        int x,y;cin>>x>>y;
        if(X_pos[x]!=0){
            Grafo[X_pos[x]-1].push_back(i);
            Grafo[i].push_back(X_pos[x]-1);}
        if(Y_pos[y]!=0){
            Grafo[Y_pos[y]-1].push_back(i);
            Grafo[i].push_back(Y_pos[y]-1);}
        X_pos[x] = i+1; Y_pos[y] = i+1;
    }

    for(int coordenada=0;coordenada<n;coordenada++){
        if(visited[coordenada] == 0){
            conexos++;
            DFS(coordenada);
        }
    }
    cout<< conexos <<"\n";

    return 0;
}
