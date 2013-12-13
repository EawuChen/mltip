#include<iostream>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;


int main(void)
{
    MatrixXf m(4,4);
    m << 1,2,3,4,
	 5,6,7,8,
	 9,10,11,12,
	 13,14,15,16;
    cout << "Block in right" << endl;
    cout << m.block<3,3>(2,2).eval() << endl << endl;
    cout << "Version 2 of block" << endl;
    cout << m.block(1,1,3,3) << endl;
    for (int i = 0; i <= 3; i++) {
	cout << "Block pf size " << i << "x" << i << endl;
	cout << m.block(0,0,i,i) << endl << endl;
    }
    return 0;
}
