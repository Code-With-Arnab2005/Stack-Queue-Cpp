#include<iostream>
#include<stack>
using namespace std;

class Convert {
private:
    string ans;

    
    int priority(char c){
        
        switch(c){
            case '^':
                return 5;
                break;
            case '/':
                return 4;
                break;
            case '*':
                return 3;
                break;
            case '+':
                return 2;
                break;
            case '-':
                return 1;
                break;
            default:
                return 0;
                break;
        }
    }
    
public:
    //constructor
    Convert(){
        ans = "";
    }

    string convertToInfix(string &s){
        stack<string> st;
        for(int i=0; i<s.length(); i++){
            if(((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=122) || ((int)s[i]>=48 && (int)s[i]<=57)){
                st.push(string(1, s[i]));
            } else {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string newStr = '('+op2+s[i]+op1+')';
                st.push(newStr);
            }
        }
        return st.top();
    }
};

int main(){
    string s;
    cout<<"Enter an Postfix string: "<<endl;
    cin>>s;
    Convert convert;
    cout<<convert.convertToInfix(s)<<endl;
}