#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grafo;
vector <int> visited;

void dfs(int s){
    if(visited[s]==0){
        visited[s] = 1;

        for(int v : grafo[s]){
            if(visited[v]==0){
                dfs(v);
            }
        }
    }
}

int main(){

    int V, E;
    cin >> V >> E;

    vector <int> a;
    grafo.assign(V, a);
    visited.assign(V, 0);

    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int componentes = 0;
    for(int i = 0; i < V; i++){
        if(visited[i]==0){
            componentes++;
            dfs(i);

        }
    }

    cout << componentes << '\n';

}