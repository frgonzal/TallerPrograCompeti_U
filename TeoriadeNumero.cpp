#include <bits/stdc++.h>
using namespace std;
//modulo
//   a%b = a - (a//b)*b

//   0 <= a - (b//a)*b < b

// propiedades:
//          (a+b)%c == ((a%c)+(b%c))%c
//          (a*b)%c == ((a%c)*(b%c))%c
//          (a-b)%c == (( ((a%c)-(b%c))%c )+c)%c

// gcd(a,b) = {
//              gcd(b,a)   si a>b   
//              b          si a==0
//              1          si b==0
//              gcd(b%a,a) else
//            }

// gcd(a,b) == gcd(b-a,a)


//Numeros Primos
//bool esPrimo(int x){
//    for(int i=0; i*i<=x; i++){// O(sqrt(x))
//        if (x%i == 0) return false;
//    }
//    return true;
//}

bool esPrimo(int x){// O(nlogn)
    vector<int> Criba(x+1,0);// considerando el 0
    Criba[0]=1;Criba[1]=1;
    for(int i=2;i*i<=x;i++){
        for(int j=i*i;j<=x;j+=i){
            Criba[j]=1;
        }
    }
    return !Criba[x];
}
// a*x = 1 mod m

//pequeño teorema de fermat:
//si m es primo
// a^(m-1) = 1 mod m
// a^(m-2)*a = 1 mod m


// a^(n) = {   
//          (a^(n//2))^2      si n par
//          ((a^(n//2))^2)*a  si n impar
//         }
// O(logn)





int main(){
    int m; cin>>m;
    cout<<esPrimo(m)<<endl;
    return 0;
}