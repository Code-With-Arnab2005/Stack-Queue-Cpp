#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    //constructor
    Node(int x){
        val=x;
        next=nullptr;
    }
};

class Stack {
private:
    Node* head;
    int sizeOfStack;

public:
    //constructor
    Stack(){
        head = NULL;
        sizeOfStack=0;
    }

    //push operation
    void push(int elem){
        Node* newNode = new Node(elem);
        newNode->next = head;
        head = newNode;
        sizeOfStack++;
    }

    //pop operation
    void pop(){
        if(!head){
            cout<<"NO Elements to delete"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        sizeOfStack--;
        delete temp;
    }

    //top operation
    int top(){
        if(!head){
            cout<<"NO Elements"<<endl;
            return -1;
        }
        return head->val;
    }

    //size operation
    int size(){
        return sizeOfStack;
    }
};

int main(){

    Stack st;
    
    st.push(1);
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.push(2);
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.push(3);
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;

    st.pop();
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.pop();
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.pop();
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.pop();
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;

    st.push(2);
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.push(3);
    cout<<"top: "<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;


    return 0;
}