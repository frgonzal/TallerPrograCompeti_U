#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct point{
    ll x,y;
    point(ll x=0, ll y=0):x(x), y(y){}


    point operator+(point p){
        return {x + p.x, y + p.y};}
    point operator-(point p){
        return {x-p.x, y-p.y};}
    ll operator*(point p){
        return x*p.x + y*p.y;}
    ll operator^(point p){
        return x*p.y - y*p.x;}
    float dist(){
        return sqrt(x*x+y*y);}
    ll dist2(){
        return x*x + y*y;}
    bool leftOF(point A, point B){
        return ((B-A)^(*this-A)) >= 0;}
    bool IN(point A, point B){
        return !((B-A)^(*this-A));}
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

    tuple<ll,ll,ll> recta(point p2){
        ll a = -(p2.y-y);
        ll b = (p2.x-x);        
        ll c = (x*(p2.y-y)-y*(p2.x-x));
        if(a<0){
            a=-a;b=-b;c=-c;}
        if(a==0 and b<0){
            b=-b;c=-c;}
        ll mcd = gcd(a, gcd(b,c));
        return {a/mcd, b/mcd, c/mcd};
    }
};


vector<point> estrellas;
set<tuple<ll,ll,ll>> rectas;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,K;cin>>N>>K;
    if(K==1){cout<<"Infinity"<<"\n";return 0;}

    for(int i=0;i<N;i++){
        ll x,y;cin>>x>>y;
        estrellas.push_back({x,y});}

    for(int i=0;  i<N;i++){
    for(int j=i+1;j<N;j++){
        if(K==2){rectas.insert(estrellas[i].recta(estrellas[j]));continue;}

        int total_estrellas = 2;
        for(int k=0;k<N;k++){
            if(k==i or k==j)continue;

            if(estrellas[k].IN(estrellas[i],estrellas[j])){total_estrellas++;}

            if(total_estrellas >= K){
                rectas.insert(estrellas[i].recta(estrellas[j]));break;}
        }
    }
    }
    cout<<rectas.size()<<"\n";
    return 0;
}