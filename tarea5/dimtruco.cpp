#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, mayores_K, cuadrados_perfectos;
ll max_n = 0;
vector<ll> n_casos;
vector<ll> k_casos;
vector<ll> criba;

void Criba(){
    ll primos_ = 0;
    for(ll p=2; p<=max_n; p++){
        if(!criba[p]){
            primos_++;
            criba[p] = primos_;//cantidad de primos <= a p
            for(ll j=p*p; j<=max_n; j+=p){
                criba[j] = -1;
        }}
    }
}

void Primos(ll n, ll k){
    cuadrados_perfectos = 0;

    for(ll i=n; i>=2; i--){
        if(criba[i]!=-1){
            cuadrados_perfectos = criba[i];
            break;
        }
    }

    mayores_K = cuadrados_perfectos;
    for(ll i=k; i>=2; i--){
        if(criba[i]!=-1){
            mayores_K = cuadrados_perfectos - criba[i];
            break;
        }
    }
}    

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    for(int m=0;m<T;m++){
        cin>>N>>K;
        N = (ll) sqrt(N);
        max_n = max(max_n, N);
        n_casos.push_back(N);
        k_casos.push_back((ll) sqrt(K));
    }

    criba.assign(max_n+1,0);
    Criba();
    
    for(int m=0;m<T;m++){
        Primos(n_casos[m], k_casos[m]);
        cout<<cuadrados_perfectos<<" ";
        cout<<mayores_K<<"\n";
    }
    return 0;
}