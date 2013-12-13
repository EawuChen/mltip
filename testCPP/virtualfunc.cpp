#include<iostream>


using namespace std;


class A
{
public:
    A():i(0),s("") { }
    A(int ii, string ss):i(ii),s(ss) { }
    virtual void total(int j) = 0;
    ~A() { }
protected:
    string s;
private:
    int i;
};


class B:public A
{
public:
    B():A(), j(0) { }
    B(int j):A(), j(j) { }
    B(int i, string s, int j):A(i,s), j(j) { }
    void total(int j);
    void total();
    friend void testFunc(B &);
    ~B() { }
private:
    int j;
};


void testFunc(B &b)
{
    cout << "S:" <<  b.s << endl;
}

void B::total()
{
    cout << "string:" << s << endl;
}
void B::total(int j)
{
    cout << "j:" << j << endl;
}

int main(void)
{
    B b(10, "Hello", 20);
    b.total(10);
    b.total();
    testFunc(b);
    cout << "K:" << b.k << endl;

    return 0;
}
