int  stack(char *arry,char* arry2)
{
	int count = 0;
	while (*arry!='\0')
	{
		if (*arry != '#')
		{
			*(arry2+count) = *arry;
			count++;
		}
		else
		{
            count -= 1;
			if (count <= 0)
				count = 0;
		}
		arry++;
	}
	return count;
}
bool backspaceCompare(char* S, char* T)
{
	char *arry_s = (char *)malloc(201*sizeof(char));
    char *arry_t = (char *)malloc(201 * sizeof(char));
	int count_s = stack(S,arry_s);
    int count_t = stack(T, arry_t);
	if (count_s != count_t)
    {
        free(arry_s);
        free(arry_t);
		return false;
    }
	else
	{
		int i = 0;
		while (i<count_s)
		{
			*(S + i) = *(arry_s + i);
			*(T + i) = *(arry_t + i);
			i++;
		}
		free(arry_s);
        free(arry_t);
		return (memcmp(S, T, count_s) == 0);
	}
}
