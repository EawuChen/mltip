#ifndef AC_H_INCLUDED
#define AC_H_INCLUDED
#define MAX_STATE   100        //自动机最大状态数
#define MAX_SYMBOL      256        //匹配的字符数可以匹配所有的ASCII码
#define MAX_MODE   4                  //最大模式串数
#define MODE_LEN   10
int DFD[MAX_STATE][MAX_SYMBOL];               //状态转移表--DFA包括转向函数和失效函数
int F[MAX_STATE] ; //失败函数
struct output_t
{
      int flag;
      char str[MODE_LEN];
}output[MAX_STATE];
int father[MAX_STATE];
unsigned int statecount;//总状态数-1
unsigned int modecount;             //模式串数-1
struct struct_quque * bfs_quque;
void printAC();
void init_ac();
void go();
void fail();
void output_str(int state,int j);
void prec();
int AC(unsigned char*s, int http_len);
#endif // AC_H_INCLUDED
