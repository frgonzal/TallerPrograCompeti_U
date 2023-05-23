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

    float dist(){return sqrt(x*x+y*y);}
    ll dist2(){return        x*x+y*y;}

    bool operator<(point p){return x < p.x;}
    //bool operator>(point p){return x > p.x;}
    //bool operator==(point p){return x==p.x;}
    bool leftOF(point A, point B){
        return ((B-A)^(*this-A)) >= 0;}
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
vector<point> figura;
vector<bool> leftof;
int n;
point sapo;
point sepo;

ll camino(bool up){
    stack<point> pila;
    bool left;
    for(int i=0;i<n;i++){
    if(leftof[i]==up){pila.push(figura[i]);}
    for(int j=i+1;j<n;j++){
        if(leftof[i]==up){
            auto punto = pila.top();pila.pop();
            //si un punto esta a la izq de la recta que formamos 
            //entonces nos conviene ir directo a ella
            if(up){
                left = figura[i].leftOF(sapo,punto);}
            else{
                left = !figura[i].leftOF(sapo,punto);}

            if (left){
                pila.push(figura[i]);
                }else{
                pila.push(punto);
                pila.push(figura[i]);}
        }break;}
    }
    auto punto = pila.top(); pila.pop();
    //
    //if 
    //if(up){
    //    left = .leftOF(sepo,punto);}
    //else{
    //    left = !.leftOF(sepo,punto);}

    


    return 0;
}

int main(){
    cin>>n; ll x,y;
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
        leftof.push_back(figura[i].leftOF(sapo,sepo));}   
    cout<<min(camino(0),camino(1))<<endl;
    return 0;
}