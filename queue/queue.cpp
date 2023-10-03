#include<bits/stdc++.h>
using namespace std;

class Myqueue{
    int *arr;
    int size;
    int front , rear;

    public:
    Myqueue(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    bool isfull();
    bool isempty();
    void enqueue(int var);
    int dequeue();
    void display();
};
bool Myqueue:: isfull(){
    if(front == 0 && rear == size){
        return true;
    }
    return false;

}

bool Myqueue:: isempty(){
    if(front == -1) return true;
    return false;
}

void Myqueue::enqueue(int var){
    if(isfull()){
        cout<<"Overflow!"<<endl;
        exit(1);
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = var;
        cout<<"Item pushed into queue!"<<endl;
    }
}

int Myqueue:: dequeue(){
    
    int var;
    if(isempty()){
        cout<<"Underflow!"<<endl;
        return -1;
    }
    else{
        var = arr[front];
        if(front >= rear){
            front =-1;
            rear = -1;
        }
        else{
            front++;
        }
        cout<<"Successful deletion!"<<endl;
        return var;
    }
}

void Myqueue::display(){
    if(isempty()){
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    else{
        for(int i = front ; i<= rear ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Myqueue Q(6);
    Q.isempty();

    Q.enqueue(90);
    Q.enqueue(78);
    Q.enqueue(56);
    Q.enqueue(45);
    Q.enqueue(23);

    Q.isfull();

    cout<<"dequeued value : "<<Q.dequeue()<<endl;

    return 0;
}
