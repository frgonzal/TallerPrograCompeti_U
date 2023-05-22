#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;

    int maximo = 0;
    set<int> moscas;
    int i,j;i=0;j=0;
    vector<int> arr_;

    int a;
    for(int i=0;i<n;i++){cin>>a;arr_.push_back(a);}
    while(j<n){
       if (moscas.find(arr_[j])==moscas.end()){
            moscas.insert(arr_[j]);
            j++;
            maximo = max(maximo,j-i);
       }
       else{
            while(moscas.find(arr_[j])!=moscas.end())
                {moscas.erase(moscas.find(arr_[i])); i++;}

            moscas.insert(arr_[j]);
            j++;
            }
    }
    cout<<maximo<<endl;
    return 0;
}
    