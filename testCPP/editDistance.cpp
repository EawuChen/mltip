#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define _DEBUG
#define INT_MAX 1000
//definition the cost of the operation
const int cost_copy = 0;			//0
const int cost_replace = 1;			//1
const int cost_delete = 1;			//2
const int cost_insert = 1;			//3
const int cost_twiddle = 1;		//4
const int cost_kill = 1;				//5

template<class T>
void DisplayArray(vector<T>&array)
{
	for (int i = 0;i<array.size();++i)
		cout<<array[i]<<" ";
}


template<class T>
void Display2DArray(vector< vector<T> >&array)
{
	for (int i = 0;i<array.size();++i)
	{
		DisplayArray(array[i]);
		cout<<endl;
	}
}

void MinEditDistence(const char *X,const char* Y,vector<vector<int> >&B,vector<vector<int> >&C)
{//B is operation matrix and C is the cost matrix
    int m = strlen(X);
    int n  = strlen(Y);

    for (int i = 0; i<m+1; ++i) { //if string X is Null, cost is delete all element
	C[i][0] = i*cost_delete;
	B[i][0] = 2;//delete = 2
    }

    for (int i = 0;i<n+1;++i) {
	C[0][i] = i*cost_insert;
	B[0][i] = 3 ;//3 = insert
    }

#ifdef _DEBUG
    Display2DArray(B);
    cout<<endl;
    Display2DArray(C);
    cout<<endl;
#endif // _DEBUG

    for (int i = 1;i<m+1;++i) {
	for (int j =1;j<n+1;++j) {
	    C[i][j] = INT_MAX;
	    if (X[i-1] == Y[j-1]) { //copy
		C[i][j] = C[i-1][j-1] + cost_copy;
		B[i][j] = 0;// copy =0
	    } else {
		if (C[i-1][j-1] + cost_replace < C[i][j]) { //replace
		    C[i][j] = C[i-1][j-1] + cost_replace;
		    B[i][j] = 1;
		}

		if (C[i][j] > C[i-1][j] + cost_delete) { //delete
		    C[i][j] = C[i-1][j] + cost_delete;
		    B[i][j] = 2;
		}

		if (C[i][j] > C[i][j-1] + cost_insert) { //insert
		    C[i][j] = C[i][j-1] + cost_insert;
		    B[i][j] = 3;
		}

		if (i>=2 && j>= 2 &&  
			X[i-1] == Y[j-2] && X[i-2] == Y[j-1] &&
			C[i][j] > C[i-2][j-2] + cost_twiddle)   { //twiddle
		    C[i][j] = C[i-2][j-2] + cost_twiddle;
		    B[i][j] = 4;
		}
	    }
	}
    }
}

void PrintMEDOperation(vector<vector<int> >&Operation,int m,int n)
{
	if( m==0 && n==0)
		return;
	int i,j;
	if (Operation[m][n] == 0)//copy
	{
		i = m-1;
		j = n-1;
	}
	else if (Operation[m][n] == 1)//replace
	{
		i = m-1;
		j = n-1;
	}
	else if (Operation[m][n] == 2)//delete
	{
		i = m-1;
		j = n;
	}
	else if (Operation[m][n] == 3)//insert
	{
		i = m;
		j = n-1;
	}
	else if (Operation[m][n] == 4)//twiddle
	{
		i = m-2;
		j = n-2;
	}
	else if (Operation[m][n] == 5)//kill
	{
	}
	PrintMEDOperation(Operation,i,j);
	cout<<"["<<i<<","<<j<<"] = "<<Operation[m][n]<<endl;
}

int main()
{
	char *X = "abcd";
	char *Y = "ascde";
	int m = strlen(X);
	int n  = strlen(Y);
	vector<vector<int> > B(m+1,vector<int>(n+1,0));
	vector<vector<int> > C(m+1,vector<int>(n+1,0));

	MinEditDistence(X,Y,B,C);
	Display2DArray(B);
	cout<<endl;
	Display2DArray(C);
	cout<<endl;
	PrintMEDOperation(B,m,n);
	return 0;
}
