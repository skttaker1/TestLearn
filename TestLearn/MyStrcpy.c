void MyStrcpy(char* a, char* b)
{
	int i = 0;
	while (*(b + i))
	{
		*(a + i) = *(b + i);
		i++;
	}

	*(a + i) = '\0';
}