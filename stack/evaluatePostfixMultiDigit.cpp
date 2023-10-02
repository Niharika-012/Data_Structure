#include<bits/stdc++.h>
using namespace std;
// program to evaluate postfix mutli digit  digit number "100 200 + 2 / 5 * 7 +"
int evaluatePostfix( string & str){
    stack<int>st;
    int i ;
    for(i = 0 ; i<str.length() ; i++){
        char ch = str[i];
        if(ch == ' ') continue;
        
        else if( isdigit(ch)){
            int num = 0;
            while(isdigit(ch)){
              num = num * 10 + (int)(ch - '0');
              i++;
              ch = str[i];
            }
            i--;
            st.push(num);
        }
        else{
          int  var1 = st.top();
               st.pop();
          int  var2 = st.top();
               st.pop();
           //cout<<var1<<" "<<var2<<endl;
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
    getline(cin,str); // reading string including space

    cout<<"Answer : "<<evaluatePostfix(str);

    return 0;
}
