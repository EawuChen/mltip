#include<stdio.h>
#include<string.h>



#define MAXLEN  100

#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))


#define max_bug(a, b) (a > b ? a : b)


int  editDistance(char *x, int xlen, char *y, int ylen, int c[][MAXLEN])
{
    int i, j;

    for(i = 0; i < max(xlen, ylen); i++) {
	c[i][0] = i;
	c[0][i] = i;
    }

    for(i = 1; i <= xlen; i++) {
	for(j = 1; j <= ylen; j++) {
	    if (x[i-1] == y[j-1]) {
		c[i][j] = c[i-1][j-1];
	    } else {
		c[i][j] = min(c[i-1][j]+1, min(c[i][j-1]+1, c[i-1][j-1]+1));
	    }
	}
    }

    return c[xlen][ylen];

}


int main(void)
{
    char *x = "ABDCBD";
    char *y = "BACDA";

    int xlen = strlen(x);
    int ylen = strlen(y);

    int c[MAXLEN][MAXLEN];

    int ed = editDistance(x, xlen, y, ylen, c);
    printf("editDistance:%d\n", ed);

    printf("max_bug:%d\n", max_bug(2*10+1, 9*2+4));

    return 0;
}
