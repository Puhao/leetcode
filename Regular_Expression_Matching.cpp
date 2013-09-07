#include <iostream>

using namespace std;

bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if ( *p == 0)
        {
        	return *s == 0;
        }  
        if(*(p+1) == '*')
        {
        	if (((*s == *p) || (*p == '.')) && (*s != '\0'))
        	{
        		if (isMatch(s+1,p))
        			return true;
        	}
        	return isMatch(s,p+2);
        }
        if (((*s == *p) || (*p == '.')) && (*s != '\0'))
        {
        	return isMatch(s+1,p+1);
        }
        else
        	return false;       
    }


int main()
{
	char s[]="b";
	char p[]="";
	cout << isMatch(s,p) << endl;
	return 0;
}