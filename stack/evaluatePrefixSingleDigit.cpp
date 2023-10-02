#include<bits/stdc++.h>
using namespace std;

int evaluatePrefix(string &str){

  stack<int>st;

  for(int i = str.length()-1 ; i>= 0 ; i--){
    char ch = str[i];

    if(ch == ' ') continue;
    else if(isdigit(ch)){
      st.push(ch-'0');
    }
    else{
      int var1 = st.top();
      st.pop();
      int var2 = st.top();
      st.pop();

      switch(ch){
        case '+': st.push(var1 + var2);
        break;
        case '-': st.push(var1 - var2);
        break;
        case '*': st.push(var1 * var2);
        break;
        case '/': st.push(var1 / var2);
        break;
      }
    }
  }
  return st.top();
}


int main(){

  string str;
  cout<<"Enter prefix expression: ";
  getline(cin,str);

  cout<<evaluatePrefix(str);
  return 0;
}
