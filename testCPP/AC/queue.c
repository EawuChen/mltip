#include "quque.h"
#include <stdlib.h>



void init_bfs_quque(quque ** bfs_quque)
{
      (*bfs_quque) = (quque *)malloc(sizeof(quque));
      (*bfs_quque)->num = 0;
}


int is_empty(quque * bfs_quque)
{
      return bfs_quque->num;
}


void in_quque(int n, quque * bfs_quque)
{
      int i = 0;
      for(i = bfs_quque->num; i > 0; i--)
             bfs_quque->q[i] = bfs_quque->q[i-1];
   bfs_quque->q[0] = n;
      bfs_quque->num++;
}


int out_quque(quque * bfs_quque)
{
      bfs_quque->num--;
      return bfs_quque->q[bfs_quque->num];
}
