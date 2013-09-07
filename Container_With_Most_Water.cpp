#include <iostream>
#include <vector>

using namespace std;

    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = height.size()-1;
        int MaxNum = 0;
       	int num = 0;
        while(i<j)
        {
        	num = min(height[i],height[j])*(j-i);
        	if (num > MaxNum)
        		MaxNum = num;
        	if(height[i]<height[j])
        	{
        		i++;
        	}
        	else
        		j--;
        }
        return MaxNum;
    }

int main()
{
	vector<int> v(5,1);
	cout << maxArea(v) << endl;
	return 0;
}