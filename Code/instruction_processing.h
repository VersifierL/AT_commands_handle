#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TR_STRNCMPEQ(STR1,STR2,N)	(strncmp((char *)STR1,(char *)STR2,(int)N)==0)
#define BOOL int
#define AT_HEAD 3 //remove AT comand head, "AT+" is 3 char.
int IsSettingCmd();

typedef void (*FUNC)(void);//函数指针

//指令结构体包括指令名以及对应的函数指针
typedef struct
{
    char * at_cmd;
    FUNC func;
}AT_CMD_TABLE;

