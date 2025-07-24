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

    string convertToPostfix(string &s){
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=122) || ((int)s[i]>=48 && (int)s[i]<=57)){
                ans+=s[i];
            } else if(s[i]=='('){
                st.push('(');
            } else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            } else {
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

int main(){
    string s;
    cout<<"Enter an Infix string: "<<endl;
    cin>>s;
    Convert convert;
    cout<<convert.convertToPostfix(s)<<endl;
}