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

    bool operator<(point p){return x < p.x;}
    //bool operator>(point p){return x > p.x;}
    //bool operator==(point p){return x==p.x;}
    bool leftOF(point A, point B){
        return ((B-A)^(*this-A)) >= 0;}
    bool IN(point A, point B){
        return ((B-A)^(*this-A)) == 0;}
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
vector<point> figura;
vector<point> izq;
vector<point> der;
vector<bool> leftof;

int n;
point sapo;
point sepo;

bool entre(point a, point c, point b){
    return (( a<c && c<b ) || ( b<c && c<a ));
}

double camino(bool left, vector<point> &puntos){
    stack<point> pila;
    bool leftof;
    if(puntos.size()>0){
        pila.push(puntos[0]);
    for(int i=1;i<puntos.size();i++){ 
        auto punto = pila.top();pila.pop();
        if(puntos[i].leftOF(sapo,punto) == left){
            pila.push(puntos[i]);
        }else{
            pila.push(punto);
            for(int j=i;j<puntos.size();j++){
                auto punto = pila.top();pila.pop();
                if( puntos[j].leftOF(punto,sepo) == left){
                    pila.push(punto);
                    pila.push(puntos[j]);
                }else{
                    pila.push(punto);
                    break;
                }
            }
            break;
        }}}

    if(pila.empty()){return (sapo-sepo).dist();}

    double dist = 0;    
    auto punto1 = pila.top();pila.pop();

    dist += (sepo - punto1).dist();

    //punto1.print();
    while(!pila.empty()){
        auto punto2 = pila.top();pila.pop();
        //punto2.print();
        dist += (punto1-punto2).dist();
        punto1 = punto2;
    }
    dist += (sapo-punto1).dist();
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n; ll x,y;
    int suma = 0;
    //leer puntos
    for(int i=0;i<n;i++){
        cin>>x>>y;
        figura.push_back({x,y});}

    //leer sapo y sepo
    cin>>x>>y; sapo = {x,y};
    cin>>x>>y; sepo = {x,y};

    //ordenar puntos segun posicion ejex
    sort(figura.begin(), figura.end());
    //comprobar si estan arriba o abajo
    for(int i=0;i<n;i++){
        if(figura[i].leftOF(sapo,sepo)){
            izq.push_back(figura[i]);
            suma++;
        }else{der.push_back(figura[i]);}} 
    if(suma==0||suma==n||(!entre(sapo,figura[0],sepo))||(!entre(sapo,figura[figura.size()-1],sepo))){cout<<(sapo-sepo).dist()<<endl;return 0;}

    cout<< min(camino(true,izq),camino(false,der)) << endl;
    return 0;
}