#include<iostream>

using namespace std;


class A
{
public:
    A(string ss):s(ss) { }
    A():s("") { }
    ~A() { }
    void printFunc();
protected:
    string s;
};

void A::printFunc()
{
    cout << "string:" << s << endl;
}

class B:private A
{
public:
    B():A(),i(0) { }
    B(int i):A(), i(i) { }
    B(string s, int i):A(s), i(i) { }
    ~B() { };
    using A::printFunc;
    void BprintFunc();
private:
    int i;
    using A::s;
};

void B::BprintFunc()
{
    cout << "String in B:" <<  s << endl;
}

int main(void)
{
    B b ("Hello world", 10);
    b.printFunc();
    b.BprintFunc();
    A a("A obj");
    cout << "S in A:" << a.s << endl;
    //cout << "S:" << b.s << endl;
    return 0;
}
