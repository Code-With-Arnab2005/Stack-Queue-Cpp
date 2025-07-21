#include<iostream>
#include<vector>
using namespace std;

class Queue {
private:
    int queSize;
    int start;
    int last;
    vector<int> que;

public:
    //constructor
    Queue(int size){
        queSize=size;
        start=-1;
        last=-1;
        que.resize(size);
    }

    //push operation
    void push(int elem){
        if(last==queSize-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(start==-1){
            start=0, last=0;
        } else {
            last++;
        }
        que[last]=elem;
    }

    //pop operation
    void pop(){
        if(last==-1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        start++;
        if(start>last) start=-1, last=-1;
    }

    //top operation
    int top(){
        if(start==-1){
            cout<<"No Elements"<<endl;
            return -1;
        }
        return que[start];
    }

    //size operation
    int size(){
        return last-start+1;
    }
};

int main(){
    Queue q(5);

    q.push(1);
    cout<<q.top()<<endl;
    q.push(2);
    cout<<q.top()<<endl;
    q.push(3);
    cout<<q.top()<<endl;
    q.push(4);
    cout<<q.top()<<endl;
    q.push(5);
    cout<<q.top()<<endl;
    q.push(6);
    cout<<q.top()<<endl;

    cout<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    cout<<endl;

    q.push(10);
    cout<<q.top()<<endl;

    cout<<q.size()<<endl;

    return 0;
}