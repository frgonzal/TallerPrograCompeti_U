#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool izq(tuple<ll,ll,ll> tupla , pair<ll,ll> punto){
    ll a,b,c;
    auto [x,y] = punto;
    tie(a,b,c) = tupla;
    // ax+by+c == 0
    // by = -ax-c
    if(!b){//b==0
        return (-c < a*x);
    }else{
        return (-a*x - c < b*y);
    }
}

vector<tuple<ll,ll,ll>> rectas;
int main(){
    ll x,y,a,b,c;
    cin>>x>>y; pair<ll,ll> casa = {x,y};
    cin>>x>>y; pair<ll,ll> fcgm = {x,y};
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        rectas.push_back({a,b,c});}

    int contador = 0;
    for(auto recta: rectas){
        if(    ( izq(recta,casa) and !izq(recta,fcgm)) 
            || (!izq(recta,casa) and  izq(recta,fcgm)) ){
                contador++;} 
    }
    cout<<contador<<"\n";
    return 0;
}