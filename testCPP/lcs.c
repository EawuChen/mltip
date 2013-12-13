#include<stdio.h>
#include<string.h>



#define MAXLEN  100

void lcs(char *x, int xlen, char *y, int ylen, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;

    for(i = 0; i < xlen; i++)
	c[i][0] = 0;
    for(j = 0; j < ylen; j++)
	c[0][j] = 0;

    for (i = 1; i <= xlen; i++) {
	for (j = 1; j <= ylen; j++) {
	    if (x[i-1] == y[j-1]) {
		c[i][j] = c[i-1][j-1] + 1; 
		b[i][j] = 0;
	    } else {
		c[i][j] = c[i-1][j] > c[i][j-1] ? (b[i][j] = 1, c[i-1][j]) : (b[i][j] = -1, c[i][j-1]);
	    } 
	}
    }

}



void printlcs(int b[][MAXLEN], char *x, int i, int j)
{
    if (i == 0 || j == 0)
	return;
    if (b[i][j] == 0) {
	printlcs(b, x, i-1, j-1);
	printf("%c", x[i-1]);
    } else if (b[i][j] == 1) {
	printlcs(b, x, i-1, j);
    } else {
	printlcs(b, x, i, j-1);
    }
}


int main(void)
{

    //char x[MAXLEN] = {"ABCBDAB"};
    //char y[MAXLEN] = {"BDCABA"};
    char x[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char y[] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];

    int xlen = strlen(x);
    int ylen = strlen(y);

    lcs(x, xlen, y, ylen, c, b);
    printlcs(b, x, xlen, ylen);
    return 0;
}
