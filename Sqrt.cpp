#include <iostream>

using namespace std;

    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    long long left = 0;
    long long right = x/2 + 1;
    while(left <= right)
    {
    	long long middle = left + (right - left) / 2;
    	long long ret = middle * middle;
    	if (ret == x)
    		return middle;
    	if (ret > x)
    		right = middle -1;
    	else
    		left = middle + 1;    	
    }
    return right;
        
}

int main()
{
	cout << sqrt(3) << endl;
	return 0;
}