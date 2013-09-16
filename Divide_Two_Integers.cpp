#include <iostream>

using namespace std;

    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long a = dividend;
        long long b = divisor;
        if (divisor == 0)
        	return 0;
        if (divisor == 1)
        	return dividend;
        int sign = 1;
        if(dividend < 0)
        {
        	a = -a;
        	sign *= -1;
        }
        if(divisor < 0)
        {
        	b = -b;
        	sign *= -1;
        }
        int i = 0;
        while((b << i) <= a)
        {
        	i++;
        }
        i--;
        int ret = 0;
        for(int k=i;k>=0;k--)
        {
        	if((b<<k) <= a)
        	{
        		ret += 1 << k;
        		a -= (b << k);
        	}
        }
        return sign * ret;
    }

int main()
{
	int a = 10; 

	int b = 3;
	cout << divide(a,b) << endl;
	return 0;
}