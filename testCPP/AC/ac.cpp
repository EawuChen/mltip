#include<iostream>


using namespace std;


void ac_func(vector<string> svec, string s)
{
    int state = 0;

    for(int i = 0; i < n; i++) {
	while(goto_func(state, s[i]))
	    state = failure_func(state);
	state = goto_func(state, s[i]);
	if (!output_func(state)) {
	    cout << i << endl;
	    cout << output_func(state) << endl;
	}
    }
}


void output_func()
{
    int newstate = 0;
    
    for( int i = 0; i < k; i++)
	enter(yi);
    for(goto_func(0, a))
}

int main(int argc, char *argv[])
{
    return 0;
}
