#include <bits/stdc++.h>
using namespace std;

vector<int> Posiciones;
vector<vector<int>> Personas;
vector<int> visited;

int ContarPersonas(int NumeroPersonas, int PrimeraPersona){

    stack<int> Pila;
    Pila.push(PrimeraPersona);
    int Total = 0;

    while(!Pila.empty()){
        int persona1 = Pila.top();Pila.pop();
        visited[persona1] = 1;
        Total += 1;

        Posiciones[persona1]=PrimeraPersona;

        for(int persona2: Personas[persona1]){
            if(visited[persona2]==0){
                visited[persona2]=1;
                Pila.push(persona2);
            }
        }
    }

    Posiciones[PrimeraPersona]=Total;
    return Total;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;

    Personas.assign(n, vector<int>(0));
    visited.assign(n,0);
    Posiciones.assign(n,-1);

    int comunidades; cin>>comunidades;
    int participantes, int1, int2;

    while(comunidades--){
        cin>>participantes;
        if(participantes>0){
            participantes--;
            cin>>int1; int1--;
            while(participantes--){
                cin>>int2; int2--;
                Personas[int1].push_back(int2);
                Personas[int2].push_back(int1);
                int1=int2;
        }}
    }

    for(int persona=0;persona<n;persona++){
        if(Posiciones[persona]==-1){
            cout << ContarPersonas(n,persona)<<" ";
        }else{
            cout<<  Posiciones[Posiciones[persona]]<<" ";
        }
    }

    return 0;
}
