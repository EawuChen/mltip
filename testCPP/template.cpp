#include<iostream>

using namespace std;


template <typename T> 
class  A
{
public:
    A(int a, int b):x(a), y(b) { }
    ~A() { }
    void getX() { cout << "x = " << x << endl; }
    void getY() { cout << "y = " << y << endl; }
    void setX(T & x) { x = x; }
    void setY(T & y) { y = y; }
    A<T> &operator=(const A<T> &);
    A<T> &operator+(const A<T> &);
    A<T> &operator-(const A<T> &);
    A<T> &operator*(const A<T> &);

private:
    T x;
    T y;
};

template <typename T>
A<T>  A<T>::operator=(const A<T>& rhs)
{
    A<T> temp;
    temp.x = rhs.x;
    temp.y = rhs.y;
    return *this;
}


template <typename T>
A<T> & A<T>::operator+(const A<T>& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

template <typename T>
A<T> & A<T>::operator-(const A<T>& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

template <typename T>
A<T> & A<T>::operator*(const A<T>& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

int main(void)
{
    A<int> a(10,20);
    A<int> b(5, 10);
    a.getX();
    a.getY();
    b.getX();
    b.getY();
    
    A<int> c = a * b ;
    c.getX();
    c.getY();
    a.getX();
    a.getY();

    //c = a - b;
    //c.getX();
    //c.getY();

    return 0;
}


