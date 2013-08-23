/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

int ladder(string start, string end, set<string> &dict)
{
	if (start == end)
		return 1;
	int step = 1;
	queue<string> q;
	q.push(start);
	while(q.size())	//BFS队列有元素就继续查找
	{
		step++;
		int len = q.size();
		while(len--)	//相同深度的节点数目
		{
			string check = q.front();
			for(int i = 0; i<check.size(); i++)
			{
				char tmp = check[i];
				for(char j='a'; j<='z'; j++)
				{
					check[i] = j;
					if (check == end)
						return step;
					if (dict.count(check))
					{
						q.push(check);	
						dict.erase(check);
					}
		
				}
				check[i] = tmp;
			}
			q.pop();
		}
	}
	return 0;
}

int main()
{
	string start="hit";
	string end = "cog";
	string org[]= {"hot","dot","dog","lot","log"};
	set<string> dict;
	for(int i=0; i<5; i++)
		dict.insert(org[i]);
	cout << ladder(start,end,dict);
	return 0;
}

/*
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end)
    	return 1;
	int step = 1;
	queue<string> q;
	q.push(start);
	while(q.size())	//BFS队列有元素就继续查找
	{
		step++;
		int len = q.size();
		while(len--)	//相同深度的节点数目
		{
			string check = q.front();
			for(int i = 0; i<check.size(); i++)
			{
				char tmp = check[i];
				for(char j='a'; j<='z'; j++)
				{
					check[i] = j;
					if (check == end)
						return step;
					if (dict.count(check))
					{
						q.push(check);	
						dict.erase(check);
					}
		
				}
				check[i] = tmp;
			}
			q.pop();
		}
	}
	return 0;
    }
};
*/