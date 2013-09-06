#include <iostream>

using namespace std;

   int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
   		bool pos = true;
   		int y = 0;
   		if (x < 0)
   		{
   			x = -x;
   			pos = false;
   		}
   		while (x > 0)
   		{
   			y = y*10 + x % 10;
   			x = x / 10;
   		}
   		if (pos == false)
   			y = -y;
   		return y;
        
    }

int main()
{
	int x = 1341013;
	cout << reverse(x) << endl;
	return 0;
}