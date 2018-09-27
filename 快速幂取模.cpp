//快速幂取模详解原博客：https://blog.csdn.net/dbc_121/article/details/77646508
long long quick_mode(long long a, long long b, long long m)
{
	long long ans = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return ans;
}
