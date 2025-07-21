#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    //constructor
    Node(int vl){
        val = vl;
        next = NULL;
    }
};

class Queue {
private:
    Node* start;
    Node* last;
    int queSize;

public:
    //constructor
    Queue(){
        start = NULL;
        last = NULL;
        queSize = 0;
    }

    //push operation
    void push(int elem){
        Node* newNode = new Node(elem);
        if(start==NULL && last==NULL){
            start=newNode;
            last=newNode;
        } else {
            last->next=newNode;
            last=last->next;
        }
        queSize++;
    }

    //pop operation
    void pop(){
        if(start==NULL){
            cout<<"NO ELEMENTS TO DELETE"<<endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        if(start==NULL) last=NULL;
        queSize--;
    }

    //top operatoin
    int top(){
        if(!start){
            cout<<"NO ELEMENTS"<<endl;
            return -1;
        }
        return start->val;
    }

    //size operation
    int size(){
        return queSize;
    }
};

int main(){
    Queue q;
    q.push(1);
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    q.push(2);
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    q.push(3);
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;

    q.pop();
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    q.pop();
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    q.pop();
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    q.pop();
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;

    q.push(2);
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    q.push(3);
    cout<<"top: "<<q.top()<<endl;
    cout<<"size: "<<q.size()<<endl;
    return 0;
}