#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<set<int > > ResSet;
        vector<vector<int> > Result;
        unordered_multimap<int,pair<int,int> > SumHash;
        if (num.size() <= 3)
        {
        	return Result;
        }
        for(int i=0;i<(num.size() - 1);i++)
        {
        	for(int j=i+1;j<num.size();j++)
        	{
        		int sum = num[i] + num[j];
        		SumHash.insert(make_pair(sum,make_pair(i,j)));
        	}
        }
        for(auto item:SumHash)
        {
        	if (item.first <= (target - item.first) )
        	{
        		unordered_multimap<int,pair<int,int> >::const_iterator it;
        		it = SumHash.find(target - item.first);
        		if (it != SumHash.end())
	        	{
					for(int index=0;index < SumHash.count(target - item.first); index++,it++)
					{

						set<int> PosSet;
						PosSet.insert(item.second.first);
						PosSet.insert(item.second.second);
						PosSet.insert(it->second.first);
						PosSet.insert(it->second.second);
						if (PosSet.size() == 4)
						{
							ResSet.insert(PosSet);
						}
					}
        		}
        	}
        }
        set<vector<int> > Stmp;
        for (auto i:ResSet)
        {
        	vector<int> v;
        	for(auto j:i)
        	{
        		v.push_back(num[j]);
        	}
        	sort(v.begin(),v.end());
        	Stmp.insert(v);
        }
        vector<vector<int> > tmp(Stmp.begin(),Stmp.end());
        return tmp;
        
    }

int main()
{
	vector<int> num = {1,3,4,24,2,-4};
	int target = 3;
	vector<vector<int> > v;
	v = fourSum(num,target);
	for (auto i:v)
	{
		for(auto j:i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}