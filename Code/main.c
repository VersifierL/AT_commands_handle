#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instruction_processing.h"

char Command[50];
int main()
{
    printf("please enter Command\n");
    scanf("%s",&Command);
    if (IsSettingCmd(Command)==1)
        printf("success");
    else
        printf("error");
    return 0;
}

