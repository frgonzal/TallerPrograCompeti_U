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

    //pruebas pa ver si la wea funciona
    point punto1(1,0);
    point punto2(1,3);//punto 1 y 2 forman recta vertical con x = 1
    point punto3 = {0,2};//otra forma de asignar valor al punto
    point punto4(4,0);

    cout<<punto3.leftOF(punto1,punto2)<<endl<<punto4.leftOF(punto1,punto2)<<endl;
    


    return 0;
}