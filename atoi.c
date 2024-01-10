include "shell.h"

/**
 *atoi - function converts a string into an integer
 *@a: string to convert
 *Return: 0 if successful
 */
int atoi(char *a)
{
	int i, output;
	int sign = 0;
	int flag = 0;
	unsigned int result = 0;

	for (i = 0; a[i] != '\0' && flag != 2; i++)
	{
		if (a[i] == '-')
			sign *= -1;

		if (a[i] >= '0' && a[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 *_delim - unction that checks if a character is a delimeter
 *@b: char to be checked
 *@delim: the delimeter
 *Return: 1 if successful, 0 otherwise
 */
int _delim(char *delim, char b)
{
	while (*delim)
		if (*delim++ == b)
			return (1);
	return (0);
}

/**
 *interactive - function checks if shell is in interactive mode
 *@info: string
 *Return: 1 if interactive, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
