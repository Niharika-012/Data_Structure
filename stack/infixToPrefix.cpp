#include<bits/stdc++.h>
using namespace std;

int precedence(char &ch){

  if(ch == '^'){
    return 3;
  }
  else if(ch == '/' || ch == '*'){
    return 2;
  }
  else if(ch == '+' || ch == '-'){
    return 1;
  }

  return -1;
}

string infixToPrefix(string & str){

  stack<char>st;
  string ans = "";

  for(int i = str.length()-1 ; i>= 0 ; i--){
      char ch = str[i];

      if((ch >= 'A' && ch <= 'Z') || (ch>='a' && ch <='z') || (ch >= '0' && ch <= '9')){
        ans += ch;
      }
      else if(ch == '('){
        while(st.top() != ')'){
          ans += st.top();
          st.pop();
        }
        st.pop();
      }
      else if(ch == ')'){
        st.push(ch);
      }
      else{
        if(st.empty()){
          st.push(ch);
        }
        else{
          while(!st.empty() && precedence(st.top()) >= precedence(ch)){
            ans += st.top();
            st.pop();
          }
          st.push(ch);
        }
      }
  }

  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin() , ans.end());
  return ans;
}

int main(){

  string str;
  cout<<"Enter infix expression: ";
  cin>>str;

  cout<<infixToPrefix(str);
  return 0;
}
