#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * _putstring - loops over and sequence of character and returns them to stdout
 * @c: The character to print
 * @str: The char sequence to be printed
 * Return: On success 1, on error, -1 is returned.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putstring(char *str)
{
	int count = 0, k = 0;

	while (str[k])
		count += _putchar(str[k++]);
	return (count);
}


int main(int c, char **env)
{	
	char *prompt = "enter command ₦ ", *buffer = NULL;
	char *arg[11], *delim = " \n", *path;
	size_t buffersize = 0;
	ssize_t stringVariable;
	pid_t Child_id;
	int status, i, j, executable;

	//__attribute_warn_unused_result__ c;
	(void)c;

	while(1)
	{
		/*Isatty only prints th prompt here if its from the stdin (interactive mode)*/
		if (isatty(0))
			_putstring(prompt);

		stringVariable = getline(&buffer, &buffersize, stdin);

		if (stringVariable == -1)
		{
			/*If end of file or CTRL+C, exit prompt*/
			_putstring("Exiting shell...");
			free(buffer);
			exit(0);
		}
		
		/*for execeve to be executed, it should be terminated with a null terminator*/
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = 0;
			i++;
		}

		j = 0;
		arg[j] = strtok(buffer, delim);
		while (arg[j])
			arg[++j] = strtok(NULL, delim);
			
		arg[j] = NULL;

		path = path_getter(arg[0]);
		
		if (path == NULL)
		{
			_putstring("Command does not exist");
			continue;
		}
		
		/*allocate momery to the arg[0] for the buffer (inputed data)*/
		Child_id = fork();
		if (Child_id < 0)
		{
			_putstring("Fork failed");
			free(buffer);
			exit(0);
		}
		else if(Child_id == 0)
		{
			/*If execve is successful, it doesnt return anything else it returns -1*/
			executable = execve(path, arg, env);
			if (executable == -1)
			{
			perror( "Command does not exist" );
    		exit( EXIT_FAILURE );
			}
		}
		else
			wait(&status);
	}
	free(path);
	free(buffer);
	return (0);
}