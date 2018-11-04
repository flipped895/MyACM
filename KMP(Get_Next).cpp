void Get_Next()
{
	int Len = strlen(p);
	int i = 0;
	int k = -1;
	Next[0] = -1;
	while (i < Len)
	{
		if (k == -1 || p[i] == p[k])
		{
			i++;
			k++;
			Next[i] = k;
		}
		else
		{
			k = Next[k];
		}
	}
}
