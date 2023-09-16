#include <iostream>
#include <string>
using namespace std;

int bell(string torre, int len){
    if (len == 1){return 1;}
    for (int i = 0; i < len-1; i++){
        if (torre[i] == torre[i+1]){
            return 0;
        }
    }
    return 1;
}

void jugar(string torreA, int lenA, string torreB, int lenB){
    int bellA = bell(torreA, lenA);
    int bellB = bell(torreB, lenB);
    if (bellA && bellB){
        cout << "YES" << endl;
    }
    else if(bellA){
        while (lenB > 1 && torreA[lenA-1] != torreB[lenB-1]){
            torreA += torreB[lenB-1];
            torreB.erase(lenB-1);
            lenA++;
            lenB--;
        }
        bellA = bell(torreA, lenA);
        bellB = bell(torreB, lenB);
        if (bellA && bellB){cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}
    }
    else if(bellB && lenA > 1 && torreA[lenA-1] != torreB[lenB-1]){
        while (lenA > 1 && torreA[lenA-1] != torreB[lenB-1]){
            torreB += torreA[lenA-1];
            torreA.erase(lenA-1);
            lenB++;
            lenA--;
        }
        bellA = bell(torreA, lenA);
        bellB = bell(torreB, lenB);
        if (bellA && bellB){cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}
    }
    else {
        cout << "NO" << endl;
    }
}

int main(){
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++){
        int lenA, lenB;
        cin >> lenA >> lenB;
        string torreA, torreB;
        cin >> torreA >> torreB;
        jugar(torreA, lenA, torreB, lenB);
    }
    return 0;
}