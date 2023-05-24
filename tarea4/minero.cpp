#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{
    ll x,y;
    point(ll x=0, ll y=0):x(x), y(y){}

    point operator+(point p){ return {x + p.x, y + p.y};}
    point operator-(point p){ return {x - p.x, y - p.y};}

    ll operator*(point p){return  x*p.x + y*p.y;}
    ll operator^(point p){return  x*p.y - y*p.x;}

    double dist(){return sqrt(x*x+y*y);}
    ll dist2(){return        x*x+y*y;}

    //version con distancia al centro
    bool operator<(point p){return (abs(x) < abs(p.x)) || (abs(y) < abs(p.y));}
    //bool operator>(point p){return x > p.x;}
    //bool operator==(point p){return x==p.x;}
    bool leftOF(point A, point B){
        return ((B-A)^(*this-A)) >= 0;}
    bool IN(point A, point B){
        return ((B-A)^(*this-A)) == 0;}
    void print(){
        cout<<"("<<x<<","<<y<<")";
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int casos_prueba;cin>>casos_prueba;
    while(casos_prueba--){
        int n;cin>>n;
        vector<point> diamantes;
        vector<point> mineros;
        ll x,y;
        for(int i=0;i<2*n;i++){
            cin>>x>>y;
            if(!x){
                mineros.push_back({x,y});
            }else{
                diamantes.push_back({x,y});}
        }
        sort(mineros.begin(),mineros.end());
        double suma;
        for(int i=0;i<n;i++){
            //falta forma de encontrar arreglo minimo
        }

        cout<<suma<<endl;
    }
    return 0;
}