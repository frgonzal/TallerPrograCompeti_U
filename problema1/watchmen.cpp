#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    map<int,int> mapa1;
    map<int,int> mapa2;
    map<int,int> mapa3;


    while(t--){
        int x,y;
        cin>>x>>y;

    }    
    return 0;
}

int intento1(){//muy lento
    int t;
    cin>>t;
    int iguales = 0;
    vector<int> posx;
    vector<int> posy;
    for (int i=0; i<t; i++){
        int x,y;
        cin >> x >> y;
        posx.push_back(x);posy.push_back(y);
    }
    for(int i=0;i<t-1;i++){for(int j=i+1;j<t;j++){
        if (posx[i]==posx[j] or posy[i]==posy[j]){iguales++;}
    }}
    cout<<iguales<<endl;
    return 0;
}