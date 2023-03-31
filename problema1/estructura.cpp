#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);  
    int N; while(cin>>N){

        set<string> opciones;
        opciones.insert("stack");opciones.insert("queue");opciones.insert("priority queue");

        int operacion,valor;
        stack<int> stackp;
        queue<int> queuep;
        priority_queue<int> pqueuep;

        while (N--){
            cin>>operacion>>valor;
            auto it_stack = opciones.find("stack");
            auto it_queue = opciones.find("queue");
            auto it_pqueue = opciones.find("priority queue");

            if(operacion==1){
                if(it_stack!=opciones.end()){stackp.push(valor);}
                if(it_queue!=opciones.end()){queuep.push(valor);}
                if(it_pqueue!=opciones.end()){pqueuep.push(valor);}}
            else{
                if(it_stack!=opciones.end()){
                    if(stackp.size()==0 or stackp.top()!=valor){opciones.erase(it_stack);}
                    else{stackp.pop();}}

                if(it_queue!=opciones.end()){
                    if(queuep.size()==0 or queuep.front()!=valor){opciones.erase(it_queue);}
                    else{queuep.pop();}}

                if(it_pqueue!=opciones.end()){
                    if(pqueuep.size()==0 or pqueuep.top()!=valor){opciones.erase(it_pqueue);}
                    else{pqueuep.pop();}}
            }}

        if(opciones.size()>1){cout<<"not sure"<<endl;}
        else if(opciones.size()<1){cout<<"impossible"<<endl;}
        else{
            auto result = opciones.begin();
            cout<<(*result)<<endl;}
    }
return 0;
}