#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int casos; cin>>casos;    
    while(casos--){
        int n, viajes; cin>>n>>viajes;

        map<ll,ll> estaciones;
        vector<vector<ll>> posiciones(n);

        for(int i=1;i<=n;i++){
            ll estacion; cin>>estacion;
            if(estaciones[estacion]==0){estaciones[estacion] = i;}
            posiciones[estaciones[estacion]-1].push_back(i);
            }

        while(viajes--){
            ll estacion1, estacion2;
            cin>>estacion1>>estacion2;
            if(estaciones[estacion1] !=0 and estaciones[estacion2]!=0
               and (posiciones[estaciones[estacion1]-1][0] <
               posiciones[estaciones[estacion2]-1][posiciones[estaciones[estacion2]-1].size()-1]))
               {cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
        }
    }

return 0;
}