#include <stack>
#include <iostream>

using namespace std;

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    int* ptr = &stk.top();
    stk.pop();
    cout << ptr << endl;
    cout << *ptr << endl;
    return 0;
}