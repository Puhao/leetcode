#include <iostream>
#include <vector>
#include <string>

using namespace std;
string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        char Roman[]={'I','V','X','L','C','D','M'};
        int scale = 1000;
        int n = num / scale;
        string s;
        if (n>0)
        	s.append(n,Roman[6]);
        for(int i=0;i<3;i++)
        {
        	num = num % scale;
        	scale = scale / 10;
        	n = num / scale;
        	if(n>=0 && n<4)
        	{
        		for(int j=0;j<n;j++)
        			s.append(1,Roman[5-2*i-1]);
        	}
        	else if(n == 4)
        	{
        		s.append(1,Roman[5-2*i-1]);
        		s.append(1,Roman[5-2*i]);
        	}
        	else if(n>4 && n<9)
        	{
        		s.append(1,Roman[5-2*i]);
        		for(int k=0;k<n-5;k++)
        		{
        			s.append(1,Roman[5-2*i-1]);
        		}
        	}
        	else
        	{
        		s.append(1,Roman[5-2*i-1]);
        		s.append(1,Roman[6-2*i]);
        	}
        }
        return s;

    }


int main()
{
	int a = 1;
	cout << intToRoman(a) << endl;
	return 0;
}