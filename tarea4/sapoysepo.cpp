#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point{
    ll x,y;
    point(ll x=0, ll y=0):x(x), y(y){}


    point operator+(point p){
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
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};


int main(){
    int n;cin>>n; ll x,y;
    vector<pair<point,bool>> figura(n);

    for(int i=0;i<n;i++){
        cin>>x>>y;
        figura[i] = {{x,y},0};
    }

    cin>>x>>y;
    point sapo(x,y);
    cin>>x>>y;
    point sepo(x,y);

    for(int i=0;i<n;i++){
        cout<< figura[i].first.leftOF(sepo,sapo) <<endl;
        //figura[i] = {figura[i].first, figura[i].first.leftOF(sapo,sepo)};
    }
    for(int i=0;i<n;i++){
        //cout<<figura[i].second<<endl;
    }

    return 0;
}