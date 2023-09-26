#include<iostream>
using namespace std;

#define Max 100

class stack{
   int top;
   public:
    int arr[Max];

    stack(){
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool empty();
};

bool stack :: push(int x){
    if(top >= Max-1){
        cout<<"Overflow";
        return false;
    }
    else{
        arr[++top] = x;
        cout<<x<<" pushed into stack"<<endl;
        return true;
    }
}

int stack :: pop(){
    if(top < 0){
        cout<<"Underflow";
        return 0;
    }
    else{
        int x = arr[top--];
        return x;
    }
}

int stack :: peek(){
    if(top < 0){
        cout<<"Underflow";
        return 0;
    }
    else{
        return arr[top];
    }
}

bool stack:: empty(){
    return (top<0);
}

int main(){
    class stack obj;

    obj.push(2);
    obj.push(4);
    obj.push(6);
    obj.push(8);

    cout<<"peek element is "<<obj.peek()<<endl;

    cout<<"popped element is "<<obj.pop()<<endl;

    cout<<"peek element is "<<obj.peek()<<endl;

   // cout<<"popped element is "<<obj.pop()<<endl;
    cout<<"Is stack empty "<<obj.empty()<<endl;
   return 0;
    
}
