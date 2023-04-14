#include <bits/stdc++.h>
using namespace std;

int ContarPersonas(int NumeroPersonas, int PrimeraPersona, vector<vector<int>> GrafoPersonas){
    vector<int> visited(NumeroPersonas);
    stack<int> Pila;
    Pila.push(PrimeraPersona);
    int Total = 0;
    while(!Pila.empty()){
        int persona1 = Pila.top();Pila.pop();
        visited[persona1] = 1;
        Total += 1;
        for(int persona2: GrafoPersonas[persona1]){
            if(visited[persona2]==0){
                visited[persona2]=1;
                Pila.push(persona2);
            }
        }
    }
    return Total;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> Personas(n);
    int comunidades;cin>>comunidades;
    vector<set<int>> Repetidos(n);

    while(comunidades--){
        int participantes;cin>>participantes;
        if(participantes>0){
            int int1, int2; cin>>int1; int1--;
            int primero = int1;
            participantes--;
            while(participantes--){
                cin>>int2; int2--;
            if(Repetidos[int1].find(int2)==Repetidos[int1].end()){
                Personas[int1].push_back(int2);
                Repetidos[int1].insert(int2);
                int1 = int2;}}

            if(Repetidos[int2].find(primero)==Repetidos[int2].end()){
                Personas[int2].push_back(primero);
                Repetidos[int2].insert(primero);}}
    }

    for(int persona=0;persona<n;persona++){
        cout << ContarPersonas(n,persona,Personas)<<" ";
        }
    return 0;
}
