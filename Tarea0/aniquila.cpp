#include <bits/stdc++.h>
using namespace std;

int jugar(){
    long long hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    for (long long i = 0; i <= k; i++){

        //turnos aproximados
        long long turnplayer = (hm/(dc+w*(k-i)));
        if ((dc+w*(k-i))*turnplayer < hm) turnplayer++;

        //turnos mosntruo aproximados
        long long turnmonst = ((hc+i*a)/dm);
        if (dm*turnmonst < (hc+i*a)) turnmonst++;

        //condicion
        if (turnplayer <= turnmonst){return 1;}
    }
    return 0;
}

int main(){
    long long repetir;
    cin >> repetir;
    while (repetir--){
        if (jugar()){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
    return 0;
}