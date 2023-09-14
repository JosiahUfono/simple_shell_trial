#include "main.h"
/*to get the path of the shell commands, we need to manually add "/bin/" before
the command. Like /bin/ls... This program would help us get the ₦PATH dynamically.*/


/*Location function toeknises the wntor path and */
char *location(char *path, char *arg)
{
	char *path_duplicate, *pathToken, *delim = ":", *filePath, *buffer;
	/*getenv returns the entire path so we have to split it into tokens again*/
	/*We don't want to alter the original *path, so we make a copy*/
	path_duplicate = strdup(path);

	pathToken = strtok(path_duplicate, delim);

	filePath = malloc(strlen(arg) + strlen(pathToken) + 2);

	/*2 is added because of the null terminator and the "/" */
	while(pathToken != NULL)
	{
		strcpy(filePath, pathToken);
		/*We end out path tokens with a / else mv would assume we want to move the file*/
		strcat(filePath, "/");
		strcat(filePath, arg);
		strcat(filePath, "\0");
		
		if (access(filePath, X_OK) == 0)
		{
			free(path_duplicate);
			return (filePath);
		}
		pathToken = strtok(NULL, delim);
	}
	free(filePath);
	free(path_duplicate);
	return (NULL);
}

char *path_getter(char *arg)
{
	/*getenv helps us get environment variables. It takes a char pointer and returns the 
	value if there's a match else returns NULL.*/
	char *path;

	//if(access("PATH", X_OK) == 0)
	path = getenv("PATH");

	if (path)
	{
		path = location(path, arg);
		return (path);
	}

	return (NULL);
}