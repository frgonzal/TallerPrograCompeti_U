#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //ir sumando para cada coordenada x e y que se repita,
    //e ir restando los pares repetidos (o si no se contarian 2 veces)
    int t;
    int x,y;
    long long iguales = 0;
    map<int,int> coord_x, coord_y;
    map<pair<int,int>,int> repetidos;
    cin>>t;

    while(t--){
        cin>>x>>y;
            //si algun elemento de map es llamado sin
            //haber sido asignado antes ==> suma 0
            iguales+=coord_x[x]+coord_y[y]-repetidos[{x,y}];
            coord_x[x]++;
            coord_y[y]++;
            repetidos[{x,y}]++;

    }
    cout<<iguales<<endl;
    return 0;

    //algo mas lento segun yo
    //para cada mapa usar n(n-1)/2
    //for (auto [llave,valor]: mapa){
        //ir sumando...
    //}
}


int funcion1(){//lento
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    int iguales = 0;
    vector<int> posx;
    vector<int> posy;
    int x,y;
    cin>>x>>y;
    posx.push_back(x);posy.push_back(y);
    for (int i=1; i<t; i++){
        cin >> x >> y;
        posx.push_back(x);posy.push_back(y);
        for (int j=i-1;j>-1;j--){
            if(posx[i]==posx[j] or posy[i]==posy[j]){iguales++;}
        }}
    cout<<iguales<<endl;
    return 0;
}