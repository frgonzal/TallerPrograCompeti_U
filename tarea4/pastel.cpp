#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point{
    double x,y;
    point(double x=0, double y=0):x(x), y(y){}


    point operator+(point p){
        return {x + p.x, y + p.y};}
    point operator-(point p){
        return {x-p.x, y-p.y};}
    double operator*(point p){
        return x*p.x + y*p.y;}
    double operator^(point p){
        return x*p.y - y*p.x;}
    double dist(){
        return sqrt(x*x+y*y);}
    double dist2(){
        return x*x + y*y;}
    bool leftOF(point A, point B){
        return ((B-A)^(*this-A)) > 0;}
    bool rightOF(point A, point B){
        return ((B-A)^(*this-A)) < 0;}
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};


vector<point> chocolates;
vector<point> frutillas;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N,M;cin>>N>>M;
    for(int i=0;i<N;i++){
        double x,y;cin>>x>>y;
        chocolates.push_back({x,y});}

    for(int i=0;i<M;i++){
        double x,y;cin>>x>>y;
        frutillas.push_back({x,y});}

    //encontrar rectas
    int maximo = 0;
    for(int i=0;  i<M;i++){
    for(int j=i+1;j<M;j++){

        int total_chocolates_izq = 0;
        int total_chocolates_der = 0;
        //chocolates que estan a la izq o der
        for(int k=0;k<N;k++){
            if( chocolates[k].leftOF(frutillas[i],frutillas[j]) ){
                total_chocolates_izq++;}
            if( chocolates[k].rightOF(frutillas[i],frutillas[j])){
                total_chocolates_der++;} 
            }

        maximo = max( max(total_chocolates_izq,total_chocolates_der), maximo);
        }}

    cout<< maximo <<"\n";
    return 0;
}