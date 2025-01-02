#include<bits/stdc++.h>
using namespace std;

void evaluateExpression(string exp){
    stack<int> st;
    // int result;

    for(int i=0; i<exp.length(); i++){
        char c = exp[i];

        //operands
        if( (c>='0' && c<='9')){
           st.push(c - '0');
        }
        //operator
        else if( c=='+'|| c=='-' || c=='*' || c=='/' || c=='^'){
            int b = (st.top());
            st.pop();
            int a = (st.top());
            st.pop();

            switch(c){
                case '+':
                // char sum = a+b;
                st.push(a+b);
                break;
                
                case '-':
                // char sub = a-b;
                st.push(a-b);
                break;

                case '*':
                // char product = a*b;
                st.push(a*b);
                break;

                case '/':
                if(b != 0){
                // char div = a/b;
                st.push(a/b);
                break;
                }

                case '^':
                st.push(pow(a,b));
                break;

            }
            
        }
    }
    cout<<st.top();
}  

int main(){
    string exp ;
    cout<<"Enter the expression: ";
    cin>>exp;

    evaluateExpression(exp);
    return 0;
}
//231*+9-