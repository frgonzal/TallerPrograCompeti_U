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
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> Personas(n);
    int comunidades;cin>>comunidades;
    vector<set<int>> NoRep(n);

    for(int i=0;i<n;i++){Personas[i].push_back(i);}
    while(comunidades--){
        int integrantes;cin>>integrantes;

        int int1;cin>>int1;
        int int2;
        for(int i=0; i<integrantes-1; i++){
            cin>>int2;
            Personas[int1-1].push_back(int2-1);
            Personas[int2-1].push_back(int1-1);
            int1 = int2;
        }
    }
    for(int i=0; i<n;i++){cout<<endl;
    for(int intg2:Personas[i]){
        cout<< intg2 << " ";
    }}
    for(int i=0;i<n;i++){
        vector<int> visited(n);
        //cout << ContarPersonas(n,i,Personas)<<" ";
        }

    return 0;
}