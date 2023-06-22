#include "monty.h"

/**
 * _confirm - confirm the function
 * @num: number
 * Return: always 0
 */
int _confirm(char *num)
{
	int ptop = 0;

	if (!num)
		return (1);

	if (num[ptop] == 45)
		ptop++;
	while (num[ptop])
	{
		if (num[ptop] < 48 || num[ptop] > 57)
			return (-1);
		ptop++;
	}
	return (0);
}
