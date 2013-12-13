#include<iostream>

using namespace std;


class hasPtr
{
public:
    hasPtr(const string &s = string()):ps(new string(s)), i(0), use(new size_t(1)) {}
    hasPtr(const hasPtr &p): ps(p.ps), i(p.i), use(p.use) {++*use;}
    hasPtr &operator=(const hasPtr &);
    size_t getUse();
    ~hasPtr();
private:
    string *ps;
    int    i;
    size_t *use;
};

hasPtr::~hasPtr()
{
    if (--*use == 0) {
	delete ps;
	delete use;
    }
}

hasPtr & hasPtr::operator=(const hasPtr &rhs)
{
    ++*rhs.use;
    if (--*use) {
	delete ps;
	delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

    return *this;
}

size_t hasPtr::getUse()
{
    return *use;
}

int main(void)
{
    string s("What a nice day!");
    string &refs = s;
    hasPtr obj = hasPtr();
    hasPtr obj2 = hasPtr();
    hasPtr &obj3 = obj2;
    hasPtr refobj = hasPtr(refs);
    cout << "Use of obj:" << obj.getUse() << endl;
    cout << "Use of refobj:" << refobj.getUse() << endl;
    obj2 = obj;
    cout << "Use of obj:" << obj.getUse() << endl;
    cout << "Use of obj2:" << obj2.getUse() << endl;

    hasPtr obj4(obj3);
    cout << "Use of obj4:" << obj4.getUse() << endl;

    return 0;
}
