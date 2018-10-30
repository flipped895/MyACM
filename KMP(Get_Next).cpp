void Get_Next()
{
	int Len = m;
	Next[0] = -1;
	int k = -1;
	int i = 0;
	while (i < Len - 1)
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