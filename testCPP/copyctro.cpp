#include<iostream>

using namespace std;


class A 
{
public:
    A():i(0) { }
    A(int ii):i(ii) { cout << "Init with value." << endl; }
    A(A &);
    ~A() { }
    A & operator=(const A &);
    bool operator!=(const A &);
private:
    int i;
};

A::A(A &rhs)
{
    cout << "Call copy constructor." << endl;
    i = rhs.i;
}

bool  A::operator!=(const A &rhs)
{
    return i==rhs.i;
}

A & A::operator=(const A &rhs)
{
    cout << "Call assignment constructor." << endl;
    if (*this != rhs) {
	i = rhs.i;
    }
    return *this;
}



class B:public A 
{
public:
    B(int i, int j):A(i), j(j) { }
    B():A(), j(0) { }
    B(int j):A(), j(j) { }
    ~B() { }

private:
    int j;
};






int main(void)
{
    A a(10);
    A b(a);
    A c;
    c = a;
    A d = a ;

    B bb(2, 4);
    B &cc = bb;
    d = bb;
    return 0;
}
