#include<bits/stdc++.h>
using namespace std;

char associativity(char c){
    if(c == '^')  return 'R';
    return 'L';
}

int prec(char c){
    if(c=='^') return 3;
    else if(c=='/' || c=='*') return 2;
    else if(c=='-' || c=='+') return 1;
    else return -1;
}

void infixToPostfix(string s){
    stack<char> st;
    string result;
    

    for(int i=0; i<s.length(); i++){
        char c = s[i];
        //for operand
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
           result += c;
        }
        //for '(' 
        else if(c == '('){
           st.push(c);
        }
        //for ')' 
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();  // '(' will be popped out
        }
        //for operators
        else{
            while(!st.empty() && prec(c)<=prec(st.top()) && associativity(c) == 'L' && st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
     while(!st.empty()){
       result += st.top();
       st.pop();
    }
    cout<<"\nThe postfix expression is "<<result<<endl;
}

int main(){
    // string exp = "k+l-m*n+(o^p)*w/u/v*t+q";
    string exp = "(A-B)*(C^D)/(E+F*G)";
    cout<<"The infix expression is "<<exp;

    infixToPostfix(exp);
    return 0;
}