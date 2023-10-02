#include<bits/stdc++.h>
using namespace std;
// program to check whether the string consist of balanced brackets or not
bool match(char&ch1 , char&ch2){
    return ((ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']') ||(ch1 == '{' && ch2 == '}'));
}
int main(){
    
    string str;
    cout<<"Enther the string : ";
    cin>>str;

    stack<char>st;

    for(char ch : str){

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(st.empty() == true){
                cout<<"Not balanced!"<<endl;
                return 0;
            }
            else if(match(st.top() , ch) == false){
                cout<<"Not balanced!"<<endl;
                return 0;
            }
            else{
                st.pop();
            }
        }
    }

    if( st.empty() == true){
        cout<<"balanced!"<<endl;
    }
    else{
        cout<<"Not balanced!"<<endl;
    }
    return 0;
}
