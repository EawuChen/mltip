#include<iostream>
#include<vector>

using namespace std;



int main(void)
{
    vector<int> ivec;

    for (decltype(ivec.size()) ix = 0; ix != 20; ix ++)
	ivec.push_back(ix);


    for (auto &i : ivec) {
	i *= i;
    }

    for (auto i : ivec) 
	cout << i << " ";
    cout << endl;

    auto f =  [] (char *s) {
	cout << s  << endl;
    };

    f((char *)"Hello, I am using lambda syntax.");

    return 0;
}
