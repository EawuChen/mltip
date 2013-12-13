#include<iostream>


using namespace std;


template<int size>
struct  trieNode
{
    trieNode<size> *child[size];
    bool isStr;
    trieNode() :isStr(false)
    {
	for(int i = 0; i < size; i++) child[i] = NULL;
    }
};

template<int size>
class trieTree 
{
public:
    trieTree();
    ~trieTree();
    void Insert(const char *s);
    void Remove(const char *s);
    bool Search(const char *s);
    void Destroy(trieNode<size>* pRoot);
private:
    trieNode<size> *pRoot;
};

template<int size>
trieTree<size>::trieTree()
{
    pRoot = new trieNode<size>();
}

template<int size>
trieTree<size>::~trieTree()
{
    Destroy(pRoot);
}

template<int size>
void trieTree<size>::Destroy(trieNode<size>* pRoot)
{
    if (NULL == pRoot)
	return;
    for (int i = 0; i < size; i++) {
	if(pRoot->child[i])
	    Destroy(pRoot->child[i]);
    }
    delete pRoot;
    pRoot = NULL;
}

template<int size>
void trieTree<size>::Insert(const char *s)
{
    trieNode<size> *p = pRoot;

    while(*s) {
	if(!p->child[*s-'a']) {
	    p->child[*s-'a'] = new trieNode<size>();
	}
	p = p->child[*s-'a'];
	s++;
    }
    p->isStr = true;
}

template<int size>
void trieTree<size>::Remove(const char *s)
{
    trieNode<size> *p = pRoot;

    while(p && *s) {
	if (p->child[*s-'a']) {
	    p = p->child[*s-'a'];
	}
	s++;
    }

    if (p && p->isStr) 
	p->isStr = false;
}

template<int size>
bool trieTree<size>::Search(const char *s)
{
    trieNode<size> *p = pRoot;

    while(p && *s) {
	p = p->child[*s-'a'];
	s++;
    }
    
    if (p && p->isStr)
	return true;
    else
	return false;
}


template<int size>
void testSearch(trieTree<size> &t, const char *s)
{
    if (t.Search(s))
	cout << "Found \"" << s << "\" " << "in trie tree." << endl;
    else
	cout << "Not Found \"" << s << "\" " << "in trie tree." << endl;
}

int main(void)
{

    trieTree<26> t;
    t.Insert("he");
    t.Insert("hero");
    t.Insert("heroman");

    testSearch(t, "hero");

    t.Remove("hero");

    testSearch(t, "hero");
    testSearch(t, "herol");

    return 0;
}
