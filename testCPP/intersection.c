#include<stdio.h>


void display(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
	printf("%d ", arr[i]);
    printf("\n");
}


int intersection(int a[], int alen, int b[], int blen, int mix[])
{
    int i = 0, j = 0, k = 0;

    while(i < alen && j < blen) {
	if (a[i] == b[j]) {
	    mix[k++] = a[i];
	    i++;
	    j++;
	} else if (a[i] > b[j]) {
	    j++;
	} else {
	    i++;
	}
    }
    return k;

}



int main(void)
{
    int a[] = {1, 2, 3, 5, 8, 12, 19};
    int b[] = {3, 5, 6, 7, 8, 10, 14, 16, 18, 21};

    int alen = sizeof(a)/sizeof(int);
    int blen = sizeof(b)/sizeof(int);
    int clen = alen > blen ? alen : blen;
    int c[clen];

    int mixed = intersection(a, alen, b, blen, c);


    display(a, alen);
    display(b, blen);
    display(c, mixed);


    return 0;
}
