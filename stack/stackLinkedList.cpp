#include<bits/stdc++.h>
using namespace std;

class Node{ // class for creating node
    public:
    int data ;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class stackLinkedList{
    Node * top;
    public:
     stackLinkedList(){
        top = NULL;
     }

     void push(int val){

    Node * temp = new Node(val); // creating a new Node

    if(!temp){ // check if heap is full 
        cout<<"Overflow"<<endl;
        return;
    }

    //temp->data =

    temp->next = top;

    top = temp;

   }

     void pop(){

    if(top == NULL){
        cout<<"Underflow"<<endl;
        return ;
    }
    else{
        Node * temp = top;

         top = top ->next;

         free(temp);
    }
}
    int peek(){
    if(!empty()){
        return top->data;
    }
    return 0;
}
     bool empty(){
    return top == NULL;
}
    void display(){
    Node * temp;

    if( top == NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    else{
        temp = top;

        while(temp != NULL){
            cout<<temp->data<<" ->  ";

            temp = temp->next;

        }
    }
}

};

int main(){
    stackLinkedList obj;

    obj.push(78);
    obj.push(67);
    obj.push(34);
    obj.push(89);
    obj.push(23);

    obj.display();
    cout<<endl;

    obj.pop();

    cout<<"peek element is "<<obj.peek()<<endl;

    obj.pop();

    obj.display();
    
    cout<<endl;

    cout<<"Is stack empty "<<obj.empty()<<endl;

    return 0;
}
