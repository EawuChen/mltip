#include<iostream>
#include<string>
#include <string.h>

using namespace std;


template<int size>
struct trieNode 
{
    bool isStr;
    trieNode *children[size];
    trieNode() :isStr(false) { memset(children, 0, sizeof(trieNode) * size); }
};


template<int size>
class trieTree 
{
public:
    trieTree();
    ~trieTree();
    void Insert(string s);
    void Insert(const char *s);
//    void Search(string s);
//    void Search(const char *s);
//    void Delete(string s);
//    void Delete(const char *s);

private:
    trieNode<size> *trieRoot;
};

template<int size>
trieTree<size>::trieTree() 
{
    trieRoot = new trieNode<size>();
}


template<int size>
void trieTree<size>::Insert(string s)
{
    trieNode<size> *pRoot = trieRoot;
    for(int i = 0; i < s.size(); i++) {
	if (!pRoot->children[s[i]-'a']) {
	    pRoot->children[s[i]-'a'] = new trieNode<size>();
	} else {
	    pRoot = pRoot->children[s[i]-'a'];
	}
    }
    pRoot->isStr = true;

}

template<int size>
void trieTree<size>::Insert(const char *s)
{
    trieNode<size> *pRoot = trieRoot;
    if (!pRoot)
	return ;
    while(*s) {
	if (!pRoot->children[*s-'a']) {
	    trieNode<size> *pNewNode = new trieNode<size>();

	    if (NULL == pNewNode) {
		cout << "new trieNode failed." << endl;
		return;
	    }
	    pRoot->children[*s-'a'] = pNewNode;
	}
	else
	    pRoot = pRoot->children[*s-'a'];
    }

    pRoot->isStr = true;
}

template<int size>
trieTree<size>::~trieTree()
{
    trieNode<size> *pRoot = trieRoot;
    if (NULL == pRoot)
	return;
    for(int i = 0; i < size; i++) {
	if (pRoot->children[i])
	    //~trieTree()
	    ;
    }
    delete pRoot;
    pRoot = NULL;
}

int main(int argc, char *argv[])
{
    const char *s =  "hello";
    trieTree<26> obj;
    obj.Insert(s);
    return 0;
}
