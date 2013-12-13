#include<iostream>
#include<stack>

using namespace std;


int main(void)
{
    stack<int *> st;

    int *ivar1 = new int;
    *ivar1 = 1;

    cout << *ivar1 << endl;
    st.push(ivar1);

    delete st.top();
    cout << *ivar1 << endl;

    return 0;
}
