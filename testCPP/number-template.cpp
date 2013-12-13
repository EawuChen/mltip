#include<iostream>

using namespace std;


template<typename T> 
class  Opearation 
{
public:
    Opearation():leftOperand(0), rightOperand(0) { }
    Opearation(T l, T r):leftOperand(l), rightOperand(r) { }
    Opearation(const Opearation<T> &rhs):leftOperand(rhs.leftOperand), rightOperand(rhs.rightOperand) { }

    ~Opearation() { }

    bool operator==(const Opearation<T> &);
    bool operator!=(const Opearation<T> &);
    Opearation<T> & operator=(const Opearation<T> &);
    Opearation<T> & operator+=(Opearation<T> &);
    Opearation<T>  operator+(const Opearation<T> &) const;
    Opearation<T> & operator-=(Opearation<T> &);
    Opearation<T>  operator-(const Opearation<T> &) const;
    Opearation<T> & operator*=(Opearation<T> &);
    Opearation<T>  operator*(const Opearation<T> &) const;
    Opearation<T> & operator--();
    Opearation<T>  operator--(int);
    Opearation<T> & operator++();
    Opearation<T>  operator++(int);
    Opearation<T>  operator()(const Opearation<T> &fst, const Opearation<T> &snd);

    T getLeftOperand() { return leftOperand; }
    T getRightOperand() { return rightOperand; }
    template<typename Type> friend ostream & operator<<(ostream &os, const Opearation<Type> &op);
    template<typename Type> friend istream & operator>>(istream &os,  Opearation<Type> &op);

    void printOpearands(char * objName) { cout << objName << "(" << leftOperand << "," << rightOperand << ")" << endl; }

private:
    T leftOperand;
    T rightOperand;
};

template<typename T>
bool Opearation<T>::operator==(const Opearation<T> &rhs)
{
    return (leftOperand == rhs.leftOperand) && (rightOperand == rhs.rightOperand);
}

template<typename T>
bool Opearation<T>::operator!=(const Opearation<T> &rhs)
{
    return !(*this == rhs);
}

template<typename T>
Opearation<T> & Opearation<T>::operator=(const Opearation<T> &rhs)
{
    if (*this != rhs) {
	leftOperand = rhs.leftOperand;
	rightOperand = rhs.rightOperand;
    }
    return *this;
}

template<typename T>
Opearation<T> & Opearation<T>::operator+=(Opearation<T> &rhs)
{
    leftOperand += rhs.leftOperand;
    rightOperand += rhs.rightOperand;
    return *this;
}

template<typename T>
Opearation<T> & Opearation<T>::operator-=(Opearation<T> &rhs)
{
    leftOperand -= rhs.leftOperand;
    rightOperand -= rhs.rightOperand;
    return *this;
}

template<typename T>
Opearation<T> & Opearation<T>::operator*=(Opearation<T> &rhs)
{
    leftOperand *= rhs.leftOperand;
    rightOperand *= rhs.rightOperand;
    return *this;
}

template<typename T>
Opearation<T> Opearation<T>::operator+(const Opearation<T> &rhs) const
{
    Opearation<T> result;
    result.leftOperand = leftOperand + rhs.leftOperand;
    result.rightOperand = rightOperand + rhs.rightOperand;
    return result;
}

template<typename T>
Opearation<T> Opearation<T>::operator-(const Opearation<T> &rhs) const
{
    Opearation<T> result;
    result.leftOperand = leftOperand - rhs.leftOperand;
    result.rightOperand = rightOperand - rhs.rightOperand;
    return result;
}

template<typename T>
Opearation<T> Opearation<T>::operator*(const Opearation<T> &rhs) const
{
    Opearation<T> result;
    result.leftOperand = leftOperand * rhs.leftOperand;
    result.rightOperand = rightOperand * rhs.rightOperand;
    return result;
}

template<typename T>
Opearation<T> & Opearation<T>::operator--() 
{
    --leftOperand;
    --rightOperand;
    return *this;
}

template<typename T>
Opearation<T>  Opearation<T>::operator--(int x) //postfix -- 
{
    Opearation<T> ret = *this;
    --*this;
    return ret;
}

template<typename T>
Opearation<T> & Opearation<T>::operator++() 
{
    ++leftOperand;
    ++rightOperand;
    return *this;
}

template<typename T>
Opearation<T>  Opearation<T>::operator++(int x) //postfix ++
{
    Opearation<T> ret = *this;
    ++*this;
    return ret;
}

template<typename Type>
ostream & operator<<(ostream &os, const Opearation<Type> &op)
{
    os << "leftOperand:" << op.leftOperand << " " << "rightOperand:" << op.rightOperand;
    return os;
}

template<typename Type>
istream & operator>>(istream &is, Opearation<Type> &op)
{
     is >> op.leftOperand >>  op.rightOperand;
     if (!is)
	 op = Opearation<Type>();
    return is;
}

template<typename T>
Opearation<T>  Opearation<T>::operator()(const Opearation<T> &fst, const Opearation<T> &snd)
{
    Opearation<T> ret;
    ret.leftOperand = fst.leftOperand + snd.leftOperand;
    ret.rightOperand = fst.rightOperand + snd.rightOperand;
    return ret;
}

int main(void)
{
    /*
    Opearation<int> obj1(10, 20);
    Opearation<int> obj2(8, 13);
    Opearation<int> obj3;

    cout << "******** + - and * ********" << endl;
    obj1.printOpearands((char *)"obj1");
    obj2.printOpearands((char *)"obj2");
    obj3 = obj1 + obj2;
    obj3.printOpearands((char *)"obj3");
    obj3 = obj1 - obj2;
    obj3.printOpearands((char *)"obj3");
    obj3 = obj1 * obj2;
    obj3.printOpearands((char *)"obj3");
    cout << "******** + - and * ********" << endl << endl;

    cout << "******** += -=  and *= ********" << endl;
    obj2 += obj1;
    obj2.printOpearands((char *)"obj2");
    obj2 -= obj1;
    obj2.printOpearands((char *)"obj2");
    obj2 *= obj1;
    obj2.printOpearands((char *)"obj2");
    cout << "******** += -=  and *= ********" << endl << endl;;

    cout << "******** --  and ++ ********" << endl;
    (obj2).printOpearands((char *)"obj2");
    (obj2--).printOpearands((char *)"obj2");
    (obj2).printOpearands((char *)"obj2");
    (--obj2).printOpearands((char *)"obj2");
    (obj2).printOpearands((char *)"obj2");
    (obj2++).printOpearands((char *)"obj2");
    (obj2).printOpearands((char *)"obj2");
    (++obj2).printOpearands((char *)"obj2");
    (obj2).printOpearands((char *)"obj2");
    cout << "******** --  and ++ ********" << endl;
    
    cout << obj2 << endl;
    cout << obj2-- << endl;
    */

    Opearation<int> op1, op2;
    cin >> op1;
    cin >> op2;
    Opearation<int> op3;
    op3 = op3(op1, op2);
    cout << op3 << endl;


    return 0;
}
