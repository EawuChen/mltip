#include <iostream>
#include <Eigen/Dense>
#include<random>
#include <unsupported/Eigen/MatrixFunctions>

using namespace std;
using namespace Eigen;


int main()
{
  MatrixXf m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << 1 + (-m).exp().array() << std::endl;

  MatrixXf x(2,2);
  x << 1,2,3,4;
  MatrixXf y(2,2);
  y << 1,2,3,4;

  cout << x * y << endl;



  VectorXf vf = VectorXf::Ones(2);

  vf += ((0.01 * 1.0 * m.row(1).array()).matrix());


  VectorXd v = VectorXd::Ones(4);




  MatrixXd mat(10, 10);
  for (int i = 0; i < 10;  i++)
      for (int j = 0; j < 10; j++)
	mat(i, j) = 1.0;

  default_random_engine dre(time(NULL));

  uniform_int_distribution<int> d(2, 10);




  VectorXf a(4);
  MatrixXf b(2,4);
  MatrixXf c(1, 4);

  a << 1,2,3,4;
  b << 1,2,3,4,
       5,6,7,8;
  c << 1,2,3,4;
    
  cout << a * b.row(0) << endl;


}
