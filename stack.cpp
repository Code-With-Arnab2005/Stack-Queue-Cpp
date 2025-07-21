#include<iostream>
#include<vector>

using namespace std;

class Stack {

private:
    int stackSize;
    int topInd;
    vector<int> st;
    
public:
    //constructor
    Stack(int s){
        stackSize=s;
        topInd=-1;
        st.resize(stackSize);
    }

    //push operation
    void push(int x){
        if(topInd==stackSize-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        topInd++;
        st[topInd]=x;
    }

    //pop operation
    void pop(){
        if(topInd==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        topInd--;
    }

    //top operation
    int top(){
        if(topInd==-1){
            cout<<"There is no element in stack"<<endl;
            return -1;
        }
        return st[topInd];
    }

    //size operation
    int size(){
        return topInd+1;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    cout<<st.top()<<endl;
    st.push(2);
    cout<<st.top()<<endl;
    st.push(3);
    cout<<st.top()<<endl;
    st.push(4);
    cout<<st.top()<<endl;
    st.push(4);
    cout<<st.top()<<endl;
    st.push(4);
    cout<<st.top()<<endl;
    st.push(4);
    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

    st.push(5);
    cout<<st.top()<<endl;

    cout<<"size: "<<st.size()<<endl;

    return 0;
}