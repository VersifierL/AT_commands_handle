#include "instruction_processing.h"

//ȥ��#������ַ�
static void end_hash_clear(char *Command, int command_len)
{
    int i;
    for(i = command_len; i >= 0; i--)
    {
        if(Command[i] == '#')
            Command[i+1] = '\0';
    }
}

//�ж��Ƿ���AT+
BOOL start_command_match(char *Command)
{
    return ((Command[0]=='A') && (Command[1]=='T') && (Command[2] == '+'));
}
// ��������ĸ��ɴ�д
static void upper_case_set(char *Command, int command_len)
{
    int i;
    for (i=0; i < command_len; i++)
        {
			if ((Command[i] == '=') || (Command[i] == ':') || (Command[i] == ','))
            {
				break;
			}

			if ((Command[i] >= 'a') && (Command[i] <= 'z'))
            {
				Command[i] -= 'a' - 'A';
			}
		}
}

/*��ѯ�汾����*/
static void at_fun_version(void)
{
    printf("version\n");
}
/*��ѯ��������*/
static void at_fun_param(void)
{
    printf("para\n");
}

//AT command table
static const AT_CMD_TABLE cmd_table[]=
{
    {"VERSION", at_fun_version},
    {"PARAM", at_fun_param}
};

//ָ�����
int IsSettingCmd(char *Command)
{
    int i=0;
    int j=0;
    int command_len = strlen(Command); // get command length
    end_hash_clear(Command, command_len);
    upper_case_set(Command, command_len);

    if(start_command_match(Command) == 0)S
    {
        printf("AT HEAD ERROR");
        return 0;
    }
    char keyword[20]={0};
    strcpy(keyword,Command+AT_HEAD);
    printf("%s\n",keyword);
    while(j<=1)
    {
        if(TR_STRNCMPEQ(keyword, cmd_table[j].at_cmd, strlen(keyword)))
        {
            cmd_table[j].func();
            return 1;
        }
        j++;
    }
    return 0;

}


