#include <bits/stdc++.h>
using namespace std;

int ContarPersonas(int Num, int PrimeraPersona, vector<vector<int>> GrafoPersonas){
    vector<int> visited(Num);
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
    int n;cin>>n;
    vector<vector<int>> Personas(n);
    vector<set<int>> Repetidos(n);
    int comunidades;cin>>comunidades;

    while(comunidades--){
        int participantes;cin>>participantes;
        if(participantes>0){
            int int1; cin>>int1; int1--;
            participantes--;

            while(participantes--){
                int int2;cin>>int2; int2--;
                if (Repetidos[int1].find(int2)==Repetidos[int1].end()){

                    Personas[int1].push_back(int2);
                    Repetidos[int1].insert(int2);

                    Personas[int2].push_back(int1);
                    Repetidos[int2].insert(int1);
                    
                    int1 = int2;}
        }}
    }

    for(int i=0;i<n;i++){
        vector<int> visited(n);
        cout << ContarPersonas(n,i,Personas)<<" ";
        }

    return 0;
}

