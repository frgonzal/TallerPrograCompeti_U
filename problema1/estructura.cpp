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

        for (int i=0;i<N;i++){
            cin>>operacion>>valor;

            if(i==0 and operacion==2){
                opciones.erase(opciones.find("stack"));
                opciones.erase(opciones.find("queue"));
                opciones.erase(opciones.find("priority queue"));
                break;}
            if (operacion==1){
                stackp.push(valor);
                queuep.push(valor);
                pqueuep.push(valor);
            }else{
                if(opciones.find("stack")!=opciones.end() and stackp.top()!=valor)
                {opciones.erase(opciones.find("stack"));}
                if(opciones.find("queue")!=opciones.end() and queuep.front()!=valor)
                {opciones.erase(opciones.find("queue"));}
                if(opciones.find("priority queue")!=opciones.end() and pqueuep.top()!=valor)
                {opciones.erase(opciones.find("priority queue"));}
                stackp.pop();queuep.pop();pqueuep.pop();
            }}

        if(opciones.size()>1){cout<<"not sure"<<endl;}
        else if(opciones.size()<1){cout<<"impossible"<<endl;}
        else{
            auto result = opciones.begin();
            cout<<(*result)<<endl;}
    }
return 0;
}




















bool stack_comprobacion(vector<vector<int>> operaciones){
    stack<int> stackprueba;
    for(int i=0;i<operaciones.size();i++){
        if(operaciones[i][0]==1){
           stackprueba.push(operaciones[i][1]);
        }else{
            if(stackprueba.top()!=operaciones[i][1]){return false;}
            stackprueba.pop();
        }
    }return true;
}
bool queue_comprobacion(vector<vector<int>> operaciones){
    queue<int> queueprueba;
    for(int i=0;i<operaciones.size();i++){
        if(operaciones[i][0]==1){
           queueprueba.push(operaciones[i][1]); 
        }else{           
            if(queueprueba.front()!=operaciones[i][1]){return false;}
            queueprueba.pop();
        }
    }return true;
}
bool priority_comprobacion(vector<vector<int>> operaciones){
    priority_queue<int> pqueueprueba;
    for(int i=0;i<operaciones.size();i++){
        if(operaciones[i][0]==1){
           pqueueprueba.push(operaciones[i][1]); 
        }else{           
            if(pqueueprueba.top()!=operaciones[i][1]){return false;}
            pqueueprueba.pop();
        }
    }return true;
}

int otrafuncion(){//lenta
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; while(cin >> N){

        vector<vector<int>> operaciones(N,vector<int>(2));
        queue<string> opciones;

        for(int i=0;i<N;i++){
            int operacion; int valor;
            cin>>operacion>>valor;
            operaciones[i][0]=operacion;operaciones[i][1]=valor;
        } 

        if (operaciones.size()>0 & operaciones[0][0]!=2){
           if(stack_comprobacion(operaciones)){
               opciones.push("stack");}

           if(queue_comprobacion(operaciones)){
            opciones.push("queue");}

           if(priority_comprobacion(operaciones)){
            opciones.push("priority queue");}

           if(opciones.size()<1){cout<<"impossible"<<endl;}
           else if(opciones.size()>1){cout<<"not sure"<<endl;}
           else{cout<<opciones.front()<<endl;}
        }else{cout<<"impossible"<<endl;}
        }
return 0;
}