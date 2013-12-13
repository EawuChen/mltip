#include<stdio.h>
#include<stdlib.h>



int main(void)
{
    int iInput;
    char *str = "-100";
    sscanf(str, "%d", &iInput);
    if (iInput < 0) {
	printf("Less than 0\n");
    }
    return 0;
}
