#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, k_, max_N, mayores_K, cuadrados_perfectos;

void Primos(){

    //potencialmente todos pueden ser primos (menos 1)
    cuadrados_perfectos =  max_N - 1;

    //todos los numeros cuyos cuadrados son menores que K (menos 1)
    ll p_menores_k = k_;
    p_menores_k--;

    vector<int> Criba(max_N+1, 0);
    for(int i=2; i*i<=max_N; i++){
        for(int j=i*i; j<=max_N; j+=i){//avanzar en los multiplos
            if(!Criba[j]){
                //cout<< j <<","<< i <<" ";
                cuadrados_perfectos--;//si leo un nuevo numero que no es primo
                if(j <= k_) p_menores_k--;
                //si leo un numero cuyo cuadrado es menor o igual a k
                //entonces es una opcion menos
                Criba[j]=1;
            }
        }
    }
    mayores_K = cuadrados_perfectos - p_menores_k;
    //cout<<"\n";
}    

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
    //Numero de primos cuyos cuadrados son menores que N
    cin>>N>>K;
    //primo maximo == (ll) sqrt(N)
    max_N = (ll) sqrt(N);
    k_ = (ll) sqrt(K);
    //cout<<max_N<<"\n";
    Primos();
    cout<<cuadrados_perfectos<<" ";
    cout<<mayores_K<<"\n";
    }
    return 0;
}