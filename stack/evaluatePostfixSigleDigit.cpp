#include<bits/stdc++.h>
using namespace std;
// program to evaluate postfix single digit number 2 3 1 * + 9
int evaluatePostfix( string & str){
    stack<int>st;

    for(char ch : str){

        if(ch == ' ') continue;
        else if( isdigit(ch)){
            st.push(ch-'0');
        }
        else{
          int  var1 = st.top();
               st.pop();
          int  var2 = st.top();
               st.pop();
           
          switch(ch){
            case '+': st.push(var2 + var1);
            break;
            case '-': st.push(var2 - var1);
            break;
            case '/': st.push(var2 / var1);
            break;
            case '*': st.push(var2 * var1);
            break;
          }

        }
    }
    return st.top();
}

int main(){

    string str;
    cout<<"Enter the postfix : ";
    cin>>str;

    cout<<"Answer : "<<evaluatePostfix(str);

    return 0;
}
