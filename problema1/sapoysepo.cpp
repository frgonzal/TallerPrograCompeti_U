#include <bits/stdc++.h>
using namespace std;

bool no_repetido_izq(vector<long long> numeros){
    for (int i=1;i<numeros.size();i++){
        if (numeros[0]==numeros[i]){return false;}
    }
    return true;
}
bool no_repetido_der(vector<long long> numeros){
    int n = numeros.size();
    for (int i=n-2;i>=0;i--){
        if (numeros[n-1]==numeros[i]){return false;}
    }
    return true;
}
int sumar(vector<long long> numeros){
    int n = numeros.size();
    int suma = 0;
    for (int i=0;i<n;i++){
        suma += 1;
    }
    return suma;
}


int main(){
    int t;
    cin>>t;
    vector<long long> numeros(t,0);
    for (int i=0;i<t;i++){
        long long numero;
        cin >> numero;
        numeros[i] = numero;
    }
    while (not (no_repetido_der or no_repetido_izq)){
        if (not no_repetido_der(numeros)){numeros.pop_back();}
        else if(not no_repetido_izq(numeros)){numeros.erase(numeros.begin());}
    }
    int sum = sumar(numeros);
    cout << sum << endl;
    return 0;
}
    