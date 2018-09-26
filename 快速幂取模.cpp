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
