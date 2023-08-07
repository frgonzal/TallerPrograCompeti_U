#include <bits/stdc++.h>
using namespace std;

int main(){
    string codigo;
    cin>>codigo;
    int maximo = 96;
    
    for(int letra: codigo){
        if(maximo+1 < letra){
            cout<<"NO"<<"\n";
            return 0;
        }
        else{
            maximo = max(maximo, letra);
        }
    }

    cout<<"YES"<<"\n";
    return 0;
}