/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	set<int> setmap;
	const int LEN = 10;
	int num[LEN] = {10,23,13,1,4,5,2,6,7,8};
	for(int i=0; i<LEN; i++)
	{
		//hashmap[num[i]] = 1;
		setmap.insert(num[i]);
	}
	set<int>::iterator it;
	int ans = 0;
	int cnt = 0;
	while(!setmap.empty())
	{
		int value = *setmap.begin();
		int test = value;
		cnt = 0;
		{
			cnt++;
			setmap.erase(test);
			while(setmap.find(++test) != setmap.end())
			{
				setmap.erase(test);
				cnt++;
			}
			test = value;
			while(setmap.find(--test) != setmap.end())
			{
				setmap.erase(test);
				cnt++;
			}
			if (ans < cnt)
			{
				ans = cnt;
			}

		}
	}
	cout << ans << endl;
	return 0;
}

/*
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> setmap(num.begin(),num.end());
	int ans = 0;
	int cnt = 0;
	while(!setmap.empty())
	{
		int value = *setmap.begin();
		int test = value;
		cnt = 0;
		{
			cnt++;
			setmap.erase(test);
			while(setmap.find(++test) != setmap.end())
			{
				setmap.erase(test);
				cnt++;
			}
			test = value;
			while(setmap.find(--test) != setmap.end())
			{
				setmap.erase(test);
				cnt++;
			}
			if (ans < cnt)
			{
				ans = cnt;
			}

		}
	}
	return ans;
    }
};
*/