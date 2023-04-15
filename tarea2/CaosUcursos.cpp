#include <bits/stdc++.h>
using namespace std;

int ContarPersonas(int NumeroPersonas, int PrimeraPersona, vector<vector<int>> GrafoPersonas,vector<int> &Posicion){
    if(Posicion[PrimeraPersona]!=-1){
        return Posicion[Posicion[PrimeraPersona]];
    }
    vector<int> visited(NumeroPersonas);
    stack<int> Pila;
    Pila.push(PrimeraPersona);
    int Total = 0;
    while(!Pila.empty()){
        int persona1 = Pila.top();Pila.pop();
        visited[persona1] = 1;
        Total += 1;
        Posicion[persona1]=PrimeraPersona;
        for(int persona2: GrafoPersonas[persona1]){
            if(visited[persona2]==0){
                visited[persona2]=1;
                Pila.push(persona2);
            }
        }
    }
    Posicion[PrimeraPersona]=Total;
    return Total;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> Personas(n);
    int comunidades;cin>>comunidades;

    while(comunidades--){
        int participantes;cin>>participantes;
        if(participantes>0){
            int int1, int2; cin>>int1; int1--;
            int primero = int1;
            participantes--;
            while(participantes--){
                cin>>int2; int2--;
                if(Personas[int2].size()==1){
                   Personas[int1].push_back(Personas[int2][0]);
                   Personas[int2].clear();
                   int1 = int2;
                }else{
                    Personas[int1].push_back(int2);
                    int1 = int2;}
                }
                Personas[int2].push_back(primero);
        }
    }
    vector<int> Pos(n,-1);
    for(int persona=0;persona<n;persona++){
        cout << ContarPersonas(n,persona,Personas,Pos)<<" ";
        }
    return 0;
}
