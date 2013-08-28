/*
Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
using namespace std;


struct Elem
{
	int val;
	int pos;
	Elem(int val,int pos):val(val),pos(pos)	{}
};

vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> HashPos;
        vector<int>::const_iterator it;
        vector<int> result;
        int one = 0;
        int second = 0;
        int half = target/2;
        int index = 1;
        for(it=numbers.begin();it<numbers.end();it++)
        {
        	if (*it == half)
        	{
        		if (one == 0)
        			one = index;
        		else
        			second = index;
        	}
        	HashPos[*it] = index++;
        }
        if (one>0 && second>0)
        {
        	result.push_back(one);
        	result.push_back(second);
        	return result;
        }
        map<int,int>::const_iterator MapIt;
        for(MapIt=HashPos.begin();MapIt!=HashPos.end();MapIt++)
        {
        	if (HashPos.count(target - MapIt->first))
        	{
        		int one = MapIt->second;
        		int second = HashPos[target - MapIt->first];
        		if (one < second)
        		{
        			result.push_back(one);
        			result.push_back(second);
        		}
        		else
        		{
        			result.push_back(second);
        			result.push_back(one);
        		}
        		break;
        	}
        }
        return result;

    }

int main()
{
	int nums[] = {2,7,11,15};
	int target = 9;
	vector<int> v;
	for (int i=0;i<4;i++)
		v.push_back(nums[i]);
	vector<int> r;
	r = twoSum(v,target);
	cout << r[0] << " " << r[1] << endl;
	return 0;
}
