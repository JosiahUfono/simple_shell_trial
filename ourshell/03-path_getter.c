#include "main.h"

char *location(char *path, char *arg)
{
    char *path_duplicate, *pathToken, *delim = ":", *filePath, *buffer;

    path_duplicate = strdup(path);

    pathToken = strtok(path_duplicate, delim);

    filePath = malloc(strlen(arg) + strlen(pathToken) + 2);

    while(pathToken != NULL)
	{
		strcpy(filePath, pathToken);
        strcat(filePath, "/");
		strcat(filePath, arg);
		strcat(filePath, "\0");

        if (access(filePath, X_OK) == 0)
		{
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
    char *path;

    path = getenv("PATH");

    if (path)
	{
		path = location(path, arg);
		return (path);
	}

	return (NULL);
}