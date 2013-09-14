#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

    vector<vector<int> > threeSum(vector<int> &num) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        set<vector<int> > ResSet;
        vector<int>::const_iterator it,it_s,it_e;
        for(it = num.begin();it != num.end();it++)
        {
        	it_s = it+1;
        	it_e = num.end()-1;
        	while(it_s < it_e)
        	{
        		int tmp = *it + *it_s + *it_e;
        		if (tmp == 0)
        		{
        			vector<int> find = {*it,*it_s,*it_e};
        			ResSet.insert(find);
        			it_s++;
        		}
        		if (tmp < 0)
        		{
        			it_s++;
        		} 
        		if (tmp > 0)
        		{
        			it_e--;
        		}
        	}
        }
		vector<vector<int> > result(ResSet.begin(),ResSet.end());
        return result;
        
    }

int main()
{
	vector<int> num = {-2,0,1,1,2};
	vector<vector<int> > v;
	v = threeSum(num);
	for (auto i:v)
	{
		for(auto j:i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}