#include<stdio.h>

void main()
{
	char a[] = "123#*@($";

	int i = 0;
	int count = 0;
	while (a[i] != 0)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			a[i] -= 32;
			count++;
		}
		i++;
	}
	if (count == 0)
	{
		printf("ERR!");
	}
	else
	{
		printf("%s\n", a);
	}

	//return 0;
}