#include <bits/stdc++.h>
using namespace std;


//usar no recursiva, se exceede lim memoria
int ContarPersonas(int PrimeraPersona, vector<vector<int>> GrafoPersonas, vector<int> &visited){
    visited[PrimeraPersona] = 1;
    int Total=1;
    for(int persona: GrafoPersonas[PrimeraPersona]){
        if (visited[persona]==0){
            Total+=ContarPersonas(persona,GrafoPersonas,visited);
        }
    }
    return Total;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> Personas(n);
    int comunidades;cin>>comunidades;

    for(int i=0;i<n;i++){Personas[i].push_back(i);}
    while(comunidades--){
        int integrantes;cin>>integrantes;
        vector<int> Lista_integrantes(integrantes);
        for(int i=0;i<integrantes;i++){
            int integrante;cin>>integrante;
            Lista_integrantes[i]=integrante-1;
        }
        for(int integrante1: Lista_integrantes){
        for(int integrante2: Lista_integrantes){
            if (integrante1!=integrante2){
                Personas[integrante1].push_back(integrante2);}}}
    }
    for(int i=0;i<n;i++){
        vector<int> visited(n);
        cout << ContarPersonas(i,Personas,visited)<<" ";}

    return 0;
}