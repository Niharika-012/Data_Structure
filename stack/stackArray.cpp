#include<bits/stdc++.h>

using namespace std;

class stackArray{
   int *arr;
   int size;
   int top1, top2;

   public:
    stackArray(int n){
        size = n;
        arr = new int[n];
        top1 =-1;
        top2 = size;
    }

    void push1(int val){
        if(top1 < top2 - 1){
            arr[++top1] = val;
        }
        else{
            cout<<"Stack1 Overflow"<<endl;
        }
    }
    void push2(int val){
        if(top2-1 > top1){
            arr[--top2] = val;
        }
        else{
            cout<<"Stack2 Overflow"<<endl;
        }
    }

    int pop1(){
        if(top1 >= 0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            cout<<"Stack1 Underflow"<<endl;
            exit(1);
        }
    }

    int pop2(){
        if(top2 <size){
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            cout<<"Stack2 Underflow"<<endl;
        }
    }

    int peek1(){
        return arr[top1];
    }

    int peek2(){
        return arr[top2];
    }

    bool empty1(){
        return top1 == -1;
    }

    bool empty2(){
        return top2 == size;
    }

    void display1(){

        if( top1 == -1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
          for(int i = 0 ; i<= top1 ; i++){
            cout<<arr[i]<<" ";
          }
          cout<<endl;
        }
    }

     void display2(){

        if( top2 == size){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
          for(int i = size - 1 ; i>= top2 ; i--){
            cout<<arr[i]<<" ";
          }
          cout<<endl;
        }
    }
};


int main(){
  
  stackArray obj(12);

  obj.push1(4);
  obj.push2(5);
  obj.push1(6);
  obj.push2(7);
  obj.push1(8);
  obj.push2(9);

  obj.display1();

  obj.display2();

  cout<<"popped element from stack1 "<<obj.pop1()<<endl;
  cout<<"popped element from stack2 "<<obj.pop2()<<endl;

  cout<<"peek element from stack1 "<<obj.peek1()<<endl;

  cout<<"peek element from stack2 "<<obj.peek2()<<endl;

  return 0;

}
