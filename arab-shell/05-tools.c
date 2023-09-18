#include "shell.h"
void freearray2D(char **array)
{
    int m;

    if (!array)
       return;
    
    for (m = 0; array[m]; m++)
    {
        free(array[m]);
        array[m] = NULL;
    }
    free(array), array = NULL;
}


void print_error(char *name, char *cmd, int idx)
{
    char *index, mssg[] = ": not found\n";

    index = _itoa(idx);

    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mssg, _strlen(mssg));

    free(index);

}

char *_itoa(int o)

{
    char buffer[20];
    int m = 0;

    if (o == 0)
       buffer[m++] = '\0';
    else
    {
        while (o > 0)
        {
            buffer[m++] = (o % 10) + '0';
            o /= 10;
        }
    }

    buffer[m] = '\0';
    reverse_string(buffer, m);

    return (_strdup(buffer));    
}

void reverse_string(char *str, int len) 
{
    int start = 0;
    int end = len - 1;
    char tmp;

    while (start < end) 
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

