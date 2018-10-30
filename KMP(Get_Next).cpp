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
			if (p[i] != p[k])
				Next[i] = k;
			else
				Next[i] = Next[k];
		}
		else
		{
			k = Next[k];
		}
	}
}
