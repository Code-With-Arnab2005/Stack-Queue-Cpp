#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Queue
{
private:
    stack<int> s1, s2;

public:
    // push operation
    void push(int elem)
    {
        s1.push(elem);
    }

    // pop operation
    void pop()
    {
        if (s2.empty() && s1.empty())
        {
            cout << "Queue is empty. Cannot pop." << endl;
            return;
        }
        if (!s2.empty())
        {
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    // top operation
    int top()
    {
        if (s2.empty() && s1.empty())
        {
            cout << "NO ELEMENTS" << endl;
            return -1;
        }
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    // size operation
    int size()
    {
        return s1.size() + s2.size();
    }
};

int main()
{
    Queue q;
    q.push(1);
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;
    q.push(2);
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;
    q.push(3);
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;

    q.pop();
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;
    q.pop();
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;
    q.pop();
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;
    q.pop();
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;

    q.push(2);
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;
    q.push(3);
    cout << "top: " << q.top() << endl;
    cout << "size: " << q.size() << endl;

    return 0;
}