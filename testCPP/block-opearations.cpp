#include<iostream>
#include<Eigen/Dense>

using namespace Eigen;
using namespace std;


int main(void)
{
    Matrix4f m;
    m << 1, 2, 3, 4,
         5, 6, 7, 8,
	 9, 10,11,12,
	 13,14,15,16;
    cout << "topLeftCorner(1,3)" << endl;
    cout << m.topLeftCorner(1,3) << endl;
    cout << "bottomRightCorner(3,1)" << endl;
    cout << m.bottomRightCorner(3,1) << endl;

    return 0;
}
