#include <iostream>
using namespace std;

class Stack
{
    int *a;
    int size;
    int top;

public:
    Stack(int n)
    {
        size = n;
        top = -1;
        a = new int[size];
    }

    void push(int v)
    {
        if (top == size - 1)
        {
            cout << "overflow";
            return;
        }
        top++;
        a[top] = v;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "underflow";
            return;
        }
        top--;
    }
    int Top()
    {
        return a[top];
    }

    bool empty()
    {
        return top < 0;
    }
};

int main()
{
    int n;
    cin >> n;
    Stack st(n);
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        st.push(v);
    }
    cout << st.Top() << endl;
    while (!st.empty())
    {
        cout << st.Top() << " -> ";
        st.pop();
    }
    return 0;
}