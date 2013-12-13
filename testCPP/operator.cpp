#include<iostream>

using namespace std;


class testOverFunction
{
public:
    testOverFunction();
    testOverFunction(string, int);
    ~testOverFunction();

    testOverFunction &operator=(const testOverFunction &);
    testOverFunction &operator+(const testOverFunction &);

    string getString();
    int getLen();

private:
    string s;
    int len;
};

testOverFunction::testOverFunction()
{
} 

testOverFunction::testOverFunction(string s, int len):s(s),len(len)
{
} 

testOverFunction::~testOverFunction()
{
    cout << "Clear resource ..." << endl;
}

testOverFunction & testOverFunction:: operator=(const testOverFunction &rhs)
{
    cout << "Start assignment...." << endl;
    s = rhs.s;
    len = rhs.len;
    return *this;
}


testOverFunction & testOverFunction::operator+(const testOverFunction &rhs)
{
    s   += rhs.s;
    len += rhs.len;
    return *this;
}

string testOverFunction::getString()
{
    return s;
}

int testOverFunction::getLen()
{
    return len;
}


int main(void)
{
    string s1("Hello world");
    int len1 = s1.length();

    string s2("I love C++");
    int len2 = s2.length();

    testOverFunction obj = testOverFunction();
    testOverFunction obj1 = testOverFunction(s1, len1);
    testOverFunction obj2 = testOverFunction(s2, len2);

    cout << "[String of obj1 is]: " << obj1.getString() << endl;
    cout << "[Length of the string of obj1 is]: " << obj1.getLen() << endl;

    cout << "[String is of obj2]: " << obj2.getString() << endl;
    cout << "[Length of the string of obj2 is]: " << obj2.getLen() << endl;

    obj = obj1;

    cout << "[String of obj is]: " << obj.getString() << endl;
    cout << "[Length of the string of obj is]: " << obj.getLen() << endl;

    obj = obj1 + obj2;

    cout << "[String of obj is]: " << obj.getString() << endl;
    cout << "[Length of the string of obj is]: " << obj.getLen() << endl;

}

