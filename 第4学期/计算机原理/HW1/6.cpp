#include <cstdio>

float u2f(unsigned int x)
{
	union {float f; unsigned u;} tmp;
	tmp.u = x;
	return tmp.f;
}
float fpower2(int x) //计算1<<x的浮点数表示
{
	unsigned exp, frac, u;
	if (x < -149) {exp = 0; frac = 0;} //0或下溢，返回0 [0, 2^-149)
	else if (x < -126) {exp = 0; frac = 1 << x+149;} //非规格化数 [2^-149, 2^-126) 
	else if (x < 128) {exp = x + 127; frac = 0;} //规格化数 [2^-126, 2^128)
	else {exp = 0xff; frac = 0;} //上溢，返回正无穷 [2^128, +∞)
	u = exp << 23 | frac;
	printf("0x%08x\n", u);
	return u2f(u);
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%f\n", fpower2(x));
	return 0;
}

