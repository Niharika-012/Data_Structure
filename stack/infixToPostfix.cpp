#include<bits/stdc++.h>
using namespace std;

int precedence(char&ch){

    if(ch == '^'){
        return 3;
    }
    else if( ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int main(){
    
    string str;
    cout<<"Enter the infix : ";
    cin>>str;

    stack<char>st;

    string ans="";

    for(char ch : str){
        if((ch >='a' && ch <='z') || (ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <='9')){
            ans += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(st.empty() == true){
                st.push(ch);
            }
            else{
                while(!st.empty() && precedence(ch) <= precedence(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);// push the higher precedence operator if ch has 
            }
        }
    }
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}
