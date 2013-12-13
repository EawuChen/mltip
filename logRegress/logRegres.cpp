#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<Eigen/Dense>
#include<vector>
#include <algorithm>
#include <iterator>
#include <unsupported/Eigen/MatrixFunctions>
#include<math.h>

using namespace std;
using namespace Eigen;


void split(string s, vector<string> &svec)
{
    istringstream iss(s);
    copy(istream_iterator<string>(iss),
	    istream_iterator<string>(),
	    back_inserter(svec));
}

void loadDataSet(char *fileName , MatrixXf &trainMat, VectorXf &labelMat)
{
    string line;
    ifstream in(fileName);
    if(!in) {
	cout << "Open file failed: " << fileName << endl; 
	exit(-1);
    }

    vector<string> svec;
    int row = 0, col, i = 0;
    while(getline(in, line)) {
	split(line, svec);
	col = 0;
	for (auto it = svec.begin(); it != svec.end() - 1; it++)
	    trainMat(row, col++) = stof(*it);
	row++;
	labelMat(i++) = stof(svec[svec.size()-1]);
	svec.clear();
    }
}

void range(vector<int> &ivec, int n)
{
    for (int i = 0; i < n; i++)
	ivec.push_back(i);
    return;
}

int random(int min, int max)
{
    default_random_engine dre(time(NULL));
    uniform_int_distribution<int> di(min, max);
    return di(dre);
}

int crandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

double sigmoid(double inX)
{
    return 1.0/(1 + exp(-inX));
}

void stocGradAscent(const MatrixXf &trainMat, const MatrixXf &labelMat, VectorXf &weights, int numIter)
{
    int row = trainMat.rows();
    int col = trainMat.cols();

    weights = VectorXf::Ones(col);
    double h, error;
    vector<int> dataIndex;
    int randIndex;
    double alpha = 0.0;

    for (int i = 0; i < numIter; i++) {
	range(dataIndex, row); 
	for (int j = 0; j < row; j++) {
	    alpha = 4/(1.0+j+i) + 0.0001;
	    //randIndex = random(0, dataIndex.size());
	    srand(time(NULL));
	    randIndex = rand() % dataIndex.size();
	    //randIndex = crandom(dataIndex.size());
	    h = sigmoid((trainMat.row(randIndex) * weights));
	    error = labelMat(randIndex) - h;
	    weights += (alpha * error * trainMat.row(randIndex).array()).matrix().transpose();
	    dataIndex.erase(dataIndex.begin() + randIndex);
	}
	dataIndex.clear();
    }
}

int classifyVector(MatrixXf inX, VectorXf weights)
{
    double prob = sigmoid((inX * weights).sum());
    if (prob > 0.5) 
	return 1;
    else
	return 0;
}

double colicTest(char *trainFile, char *testFile)
{
    MatrixXf trainMat(299, 21);
    VectorXf labelVec(299);
    VectorXf weights;

    loadDataSet(trainFile, trainMat, labelVec);

    stocGradAscent(trainMat, labelVec, weights, 1000);

    int errorCount = 0;
    double errorRate = 0.0;
    MatrixXf testMat(67, 21);
    VectorXf testLabelVec(67);

    loadDataSet(testFile, testMat, testLabelVec);
    int predictedLabel;

    for (int i = 0; i < 67; i++) {
	predictedLabel = classifyVector(testMat.row(i), weights);
	if (predictedLabel != (int)testLabelVec(i))
	    errorCount += 1;
    }
    errorRate = errorCount/67.0;

    cout << "the error rate of this test is: " << errorRate << endl;
    return errorRate;
}

int main(int argc, char *argv[])
{

    double sum = 0.0;
    for (int i = 0; i < 10; i++)
	sum += colicTest(argv[1], argv[2]);
    cout << "Averange error rate of 10 times: " << sum/10.0 << endl;
    return 0;
}
