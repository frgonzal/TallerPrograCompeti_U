#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

struct point{
    ll x,y;
    point(ll x=0, ll y=0):x(x), y(y){}


    
        return {x + p.x, y + p.y};}
    point operator-(point p){
        return {x+p.x, y+p.y};}
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
    bool IN(poin A, point B){
        return ((B-A)^(*this-A)) == 0;}
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};


int main(){
    int N,K;cin>>N>>K;
    vector<point> estrellas;
    for(int i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        estrellas.push_back({x,y});}

    if(N>=1 and K==1){      cout<<"Infinity"<<"\n";return 0;}
    else if(N==0 and K==0){ cout<<"Infinity"<<"\n";return 0;}
    else if( N<K ){         cout<<0<<"\n";return 0;}

    //no se pueder repetir rectas :(

    return 0;
}