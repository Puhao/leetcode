#include <iostream>
//#define INT_MAX (2147483647) 
//#define INT_MIN (-2147483648)
using namespace std;

    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(isspace(*str))
        	str++;
        int sign = 0;
        int sum = 0;
        if (*str=='-' || *str=='+')
        {
        	if (*str=='-')
        		sign = -1;
        	str++;
        }
        while(isdigit(*str))
        {
        	int tmp = *str++ - '0';
        	if (sum >= INT_MAX / 10)
        	{
        		if (sum <1000000000)	
        		{
        			int Threshold = 0;
        			if (sign == 0)
        			{
        				Threshold = INT_MAX % 10;
        				if (tmp > Threshold)
        					return INT_MAX;
        			}
        			else
        			{
        				Threshold = - (INT_MIN % 10);
        				if (tmp > Threshold)
        					return INT_MIN;
        			}
        		}
        		else
        		{
        			if (sign == 0)
        				return INT_MAX;
        			else
        				return INT_MIN;
        		}

        	}
        	sum = sum * 10 + tmp;
        }
        if (sign == 0)
        	return sum;
        else
        	return -sum;
        
    }

int main()
{
	char a[] = "-11919730356";
	cout << atoi(a) << endl;
	return 0;
}