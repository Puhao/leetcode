#include <iostream>
#include <vector>
using namespace std;

    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        int MinDst = INT_MAX;
        int Sum = 0;
        int tmp;
        int dst;
        vector<int>::const_iterator it_i,it_j,it_k;
        for(it_i=num.begin();it_i<(num.end()-2);it_i++)
        {
        	it_j = it_i + 1;
        	it_k = num.end() - 1;
        	while(it_j < it_k)
        	{
        		tmp = *it_i + *it_j + *it_k;
        		if(tmp == target)
        		{
        			return target;
        		}
        		if(tmp > target)
        		{
        			dst = tmp - target;
        			if (dst < MinDst)
        			{
        				MinDst = dst;
        				Sum = tmp;
        			}
        			it_k--;
        		}
        		if (tmp < target)
        		{
        			dst = target - tmp;
        			if (dst < MinDst)
        			{
        				MinDst = dst;
        				Sum = tmp;
        			}
        			it_j++;
        		}
        	}
        }
        return Sum;        
    }

int main()
{
	vector<int> num = {1,3,15,-3,15,1,1,-5,8,4};
	int target = 3;
	cout << threeSumClosest(num,target) << endl;
	return 0;
}