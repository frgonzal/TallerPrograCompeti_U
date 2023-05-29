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
                }else{//si esta adentro de la linea que forman el punto y sepo
                      //entonces se puede llegar directo
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
    //leer puntos
    for(int i=0;i<n;i++){
        cin>>x>>y;
        figura.push_back({x,y});}

    //leer sapo y sexo
    cin>>x>>y; sapo = {x,y};
    cin>>x>>y; sepo = {x,y};

    //si sapo y sepo estan ambos a la izq de alguna arista entonces se puede llegar directo
    point punto1 = figura[0];
    for(int i=1;i<n;i++){
        if(sapo.leftOF(figura[i],punto1) and sepo.leftOF(figura[i],punto1)){
            cout<<(sapo-sepo).dist()<<endl; return 0;}
        punto1 = figura[i];}
        if(sapo.leftOF(punto1,figura[0]) and sepo.leftOF(punto1,figura[0])){
            cout<<(sapo-sepo).dist()<<endl; return 0;}
    //si pasamos esto aseguramos que no existe camino directo


    //ordenar puntos segun posicion ejex
    sort(figura.begin(), figura.end());
    //for(int i=0;i<n;i++){figura[i].print();}
    //comprobar si estan arriba o abajo
    for(int i=0;i<n;i++){
        if(figura[i].leftOF(sapo,sepo) and !figura[i].IN(sapo,sepo)){
            izq.push_back(figura[i]);
        }else if(!figura[i].leftOF(sapo,sepo)){
            der.push_back(figura[i]);}} 
    double minimo = min(camino(true,izq), camino(false, der));
    cout<<fixed<< setprecision(15) <<minimo<< "\n";
    return 0;
}