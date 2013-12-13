#include "ac.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quque.h"

void printAC()
{
   int i = 0;
   int j = 0;
   printf("DFD\n");
   for(i = 0; i < MAX_STATE; i++)
   {
       for(j = 0; j < MAX_SYMBOL; j++)
       {
           printf("%d ",DFD[i][j]);
           if(j == MAX_SYMBOL - 1)
               printf("\n");
       }
   }
   printf("F\n");
   for(i = 0; i < MAX_STATE; i++)
       printf("%d ",F[i]);
   printf("\noutput\n");
   for(i = 0; i < MAX_STATE; i++)
       printf("%d %s\n",output[i].flag,output[i].str);
}
void init_ac()
{
   int i,j;
   statecount = 1;
   modecount = 0;
   for (i = 0 ; i < MAX_STATE; i++)
   {
       output[i].flag = -1;
       output[i].str[0] = '\0';
       F[i] = 0;
       father[i] = 0;
       for (j = 0 ; j < MAX_SYMBOL; j++)
       {
           DFD[i][j] = 0;
       }
   }
}
void go()
{
   int c;
   int currentstate ;
   char str[MODE_LEN];
   int start = 1;
   int temp = 0;
      getchar();
   printf("input patter strings,interval with blank and end with enter:\n");
   while((c = getchar()) != '\n')
   {
       if (c != ' ')
       {
           if (start)
           {
               start = 0;
               modecount++;
               currentstate = 0;
               temp = 0;
           }
           str[temp++] = c;
           if(DFD[currentstate][c] == 0)
           {
               DFD[currentstate][c] = statecount;
               father[statecount] = currentstate;
               currentstate = statecount;
               statecount++;
           }
           else
               currentstate = DFD[currentstate][c];
       }
       else
       {
           output[currentstate].flag = 1;
           str[temp] = '\0';
           strcpy(output[currentstate].str, str);
           start = 1;
           if (modecount == MAX_MODE)
           {
               printf("Max patter string number is: %d",MAX_MODE);
               goto END;
           }
       }
   }
   output[currentstate].flag = 1;
   str[temp] = '\0';
   strcpy(output[currentstate].str, str);
   return;
END:
   printf("Press any key to continue...");
   //c = getch();
   return;
}



int main(void)
{
    go();
    return 0;
}
