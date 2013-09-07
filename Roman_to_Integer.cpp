#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline int c2n(char c) 
{
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
}
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int PreTmp = 0;
        int num;
        int sum = 0;
        for(int i=0;i<s.size();i++)
        {
        	num = c2n(s[i]);
        	if (num > PreTmp)
        	{
        		if (PreTmp == 0)
        			PreTmp = num;
        		else
        		{
        			sum += num - PreTmp;
        			PreTmp = 0;
        		}
        	}
        	else if (num == PreTmp)
        	{
        		PreTmp += num;
        	}
            else
            {
                sum += PreTmp;
                PreTmp = num;
            }
        }
        return sum + PreTmp;
    }

int main()
{
	string s = "MCMXCIX";
	cout << romanToInt(s) << endl;
	return 0;
}