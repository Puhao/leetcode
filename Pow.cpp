#include <iostream>
#include <vector>

using namespace std;


double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
	if (x == 1)
		return 1;
	if (x == -1)
	{
		if (n%2)
			return -1;
		else
			return 1;
	}
	if (x == 0)
		return 0;
	if (n == 0)
		return 1;
	if (n < 0)
		return 1 / pow(x,-n);
	if (n%2)
		return x * pow(x,n-1);
	else
	{
		double tmp = pow(x,n/2);
		return tmp*tmp;
	}

}

int main()
{
	cout << pow(2,11) << endl;
	return 0;
}