#ifndef QUQUE_H_INCLUDED
#define QUQUE_H_INCLUDED
#include "ac.h"
struct struct_quque
{
      int q[MAX_STATE];
      int num;
};
typedef struct struct_quque quque;
void init_bfs_quque(quque ** bfs_quque);
int is_empty(quque * bfs_quque);
void in_quque(int n, quque * bfs_quque);
int out_quque(quque * bfs_quque);
#endif // QUQUE_H_INCLUDED
