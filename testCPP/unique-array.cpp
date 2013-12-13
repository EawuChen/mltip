#include<iostream>
#include<vector>
#include<set>
#include <algorithm>

using namespace std;

template<typename T>
unsigned int uniqueArray1(T *arr, const unsigned int arr_size)
{
    set<T> s(arr, arr+arr_size);
    copy(s.begin(), s.end(), arr);
    return s.size();
}

template<typename T>
unsigned int uniqueArray2(T *arr, const unsigned int arr_size)
{
    vector<T> vec(arr, arr+arr_size);
    sort(vec.begin(), vec.end());
    T *end = unique_copy(vec.begin(), vec.end(), arr);
    return (end-arr);
}



template<typename T>
void bubbleSort(T *arr, const unsigned int arr_size)
{
    for (int i = 0; i < arr_size; i++) {
	//for (int j = arr_size-1; j -i > 0; j--) {
	for (int j = 0; j < arr_size; j++) {
	    if (arr[j-1] > arr[j]) {
		swap(arr[j-1], arr[j]);
	    }
	}
    }
}


template<typename T>
unsigned int removeDuplicated(T *arr, const unsigned int arr_size)
{
    bubbleSort(arr, arr_size);
    int j = 0;
    for (int i = 0; i < arr_size; i++) {
	while(arr[i] == arr[i+1]) {
	    i++;
	}
	arr[j++] = arr[i];
    }
    return j;
}

template<typename T>
unsigned int partition(T *arr, unsigned int left, unsigned int right)
{
    int i = left, j = right;
    int s = arr[left];
    while(i < j) {
	while(i < j && (arr[j] > s))
	    j--;
	if (i < j)
	    arr[i++] = arr[j]; 
	while(i < j && (arr[i]) < s)
	    i++;
	if (i < j)
	    arr[j--] = arr[i];
    }
    arr[i] = s;
    return i;
}


template<typename T>
unsigned int partition_second(T *arr, unsigned int left, unsigned int right)
{
    T divide = arr[right];
    int i = left-1;
    for (int j = left; j < right; j++) {
	if (arr[j] < divide) {
	    i++;
	    swap(arr[i], arr[j]);
	}
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

template<typename T>
void quickSort(T *arr, unsigned int left, unsigned int right)
{
    if(left < right) {
	//int pos  = partition(arr, left, right);
	cout << "right:" << right << endl;
	int pos  = partition_second(arr, left, right);
	quickSort(arr, left, pos-1);
	quickSort(arr, pos+1, right);
    }
}

template<typename T>
void notRecursionQuickSort(T *arr, unsigned int arr_size)
{
    T mystack[32];
    int top = -1;
    mystack[++top] = 0;
    mystack[++top] = arr_size - 1;

    while(top > 0) {
	int end = mystack[top--];
	int start = mystack[top--];
	int i = start - 1;
	T x = arr[end];
	for (int j = start; j < end; j++) {
	    if (arr[j] < x) {
		i++;
		swap(arr[i], arr[j]);
	    }
	}
	swap(arr[i+1], arr[end]);

	if (start < i) {
	    mystack[++top] = start;
	    mystack[++top] =  i;
	}

	if (i+2 < end) {
	    mystack[++top] = i+2;
	    mystack[++top] = end;
	}
    }
}


int main(void)
{
    int arr[] = { 5, 2,3 ,4,  8, 9,7, 2,3};
    int arr_size = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, arr_size-1);
    //notRecursionQuickSort(arr, arr_size);
    //bubbleSort(arr, arr_size);
    for (int i = 0; i < arr_size; i++)
	cout << arr[i] << " ";
    cout << endl;


    unsigned int newSize = removeDuplicated(arr, arr_size);
    for (int i = 0; i < newSize; i++)
	cout << arr[i] << " ";
    cout << endl;

    unsigned int sizeOfUnique = uniqueArray1(arr, arr_size);
    for (int i = 0; i < sizeOfUnique; i++)
	cout << arr[i] << " ";
    cout << endl;

    unsigned int sizeOfUnique2 = uniqueArray2(arr, arr_size);
    for (int i = 0; i < sizeOfUnique2; i++)
	cout << arr[i] << " ";
    cout << endl;


    return 0;
}
