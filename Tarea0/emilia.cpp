#include <iostream>
using namespace std;


int main(){
    int largo, alto;
    cin >> largo >> alto;
    int lista[largo];
    int resultado = 0;
    int n;
    for (int i = 0; i < largo; i++){
        cin >> n;
        lista[i] = n;
    }

    for (int i = 0; i < largo; i++){
        if (lista[i] > alto){
            lista[i] = 2;
        }
        else{
            lista[i] = 1;
        }
    }

    for (int i = 0; i < largo; i++){
        resultado += lista[i];
    }
    
    cout << resultado << endl;

    return 0;
}