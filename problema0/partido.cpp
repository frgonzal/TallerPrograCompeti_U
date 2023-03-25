#include <iostream>
using namespace std;


// A == 65 
// 0 == 48

//para encontrar los valores numericos
//char character;
//cin >> character;
//cout << character + 0 << endl;


int main(){
    int A = 0;
    int B = 0;
    char registro[400];
    cin >> registro;

    
    int i = 0;
    char jugada = registro[i];
    while (jugada == 65 || jugada == 66){
        if (jugada == 65){
            A += registro[i+1] - 48;
        }
        else{
            B += registro[i+1] -48;
        }

        i++;
        i++;
        jugada = registro[i];
    }

    if (A > B){
        cout << "A" << endl;
    }
    else {
        cout << "B" << endl;
    }
    return 0;
}

    //bool juego = true;
    //bool juego2 = false;
//
//
    //int i = 0;
    //while (juego){
//
    //    //algoritmo principal
    //    if (registro[i] == 65){
    //        A += registro[i+1] - 48;
    //    }
    //    else{
    //        B += registro[i+1] -48;
    //    }
//
    //    i++;
    //    i++;
    //    
    //    if (A == 10 && B == 10){
    //        juego = false;
    //        juego2 = true;
    //    }
    //    else if (A == 11){
    //        cout << "A";
    //        juego = false;
    //    }
    //    else if (B == 11){
    //        cout << "B";
    //        juego = false;
    //    }
    //}
//
    //while (juego2){
    //    if (registro[i] == 65){
    //        A += registro[i+1] - 48;
    //    }
    //    else{
    //        B += registro[i+1] -48;
    //    }
//
    //    i++;
    //    i++; 
//
    //    if (A - B > 1){
    //        cout << "A";
    //        juego2 = false;
    //    }
    //    if (B - A > 1){
    //        cout << "B";
    //        juego2 = false;
    //    }
    //}

