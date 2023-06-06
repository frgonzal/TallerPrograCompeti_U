#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, max_N, mayores_K, cuadrados_perfectos;

void Primos(){
    ll ma_k = 0;
    ll mi_k = 0;
    ll ks = (ll) sqrt(K);
    vector<int> Criba(max_N+1, 0);// O(nlogn)
    for(int i=2; i*i<=max_N+1; i++){
        for(int j=i*i; j<max_N+1; j+=i){
            if(!Criba[j]){
                if(j>ks)ma_k++;
                else mi_k++;
                Criba[j]=1;
            }
        }
    }
    //ks el numero que divide la Criba
    // ma_k los menores a k
    // mi_k los mayores a k
    // max_N - (mi_k + ma_k + 1) == primos totales //el 1 no se cuenta
    // ks - (mi_k + 1)  = primos menores que k
    // primos totales - primos menores que k = primos mayores que k
    cuadrados_perfectos = max_N - (mi_k + ma_k + 1);
    mayores_K = (cuadrados_perfectos) - (ks - mi_k - 1);
}    

int main(){
    int T;cin>>T;
    while(T--){
    //Numero de primos cuyos cuadrados son menores que N
    cin>>N>>K;
    //primo maximo == (ll) sqrt(N)
    max_N = (ll) sqrt(N);
    Primos();
    cout<<cuadrados_perfectos<<" ";
    cout<<mayores_K<<"\n";
    }
    return 0;
}