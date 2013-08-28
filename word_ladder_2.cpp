/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
using namespace std;

void PrintPreList(map<string,vector<string> > &LadPre)
{
	map<string,vector<string> >::const_iterator  it;
	vector<string>::const_iterator vt_it;
	for (it = LadPre.begin();it != LadPre.end();it++)
	{
		cout << it->first << ":";
		for(vt_it=(it->second).begin();vt_it < (it->second).end(); vt_it++)
		{
			cout << *vt_it << " ";
		}
		cout << endl;
	}
	return;
}


void FindPath(map<string,vector<string> > &LadPre, vector<vector<string> > &LadRoad,string start,string end,vector<string> &OneRoad)
{
	if (start == end)
	{
		OneRoad.push_back(start);
		reverse(OneRoad.begin(), OneRoad.end());
		LadRoad.push_back(OneRoad);
		reverse(OneRoad.begin(), OneRoad.end());
		OneRoad.pop_back();
		return;
	}
	OneRoad.push_back(end);
	vector<string>::const_iterator it;
	vector<string> list = LadPre[end];
	for (it=list.begin(); it < list.end(); it++)
	{
		FindPath(LadPre,LadRoad,start,*it,OneRoad);
	}
	OneRoad.pop_back();
	return;
}

vector<vector<string> > findLadders(string start, string end, set<string> &dict) 
{
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<vector<string> > LadRoad;
	vector<string> OneRoad;
	map<string,vector<string> >LadPre;	//记录每个单词，在相同最少跳跃次数下可以由哪几个单词跳转来到
	if (start == end)
		return LadRoad;

	queue<string>	LadQue;
	queue<string>	DelQue;
	set<string> RoundSet;	//确保每轮queue入队的元素没有重复的

	LadQue.push(start);
	//有一个小陷阱，如果开始的元素已经在dict里面，在变化检索的时候会产生重复元素
	//if(dict.count(start))
	//	dict.erase(start);
	bool FindEnd = false;
	while(!LadQue.empty())
	{
		int length = LadQue.size();
		while(length--)
		{
			string check = LadQue.front();
			string PreWord = check;
			for(int i=0; i<check.size(); i++)
			{
				char tmp = check[i];	//每次变化一位
				for(char j='a'; j<='z'; j++)
				{
					check[i] = j;
					if (check == end)
					{
						LadPre[check].push_back(PreWord);
						FindEnd = true;						
					}
					else if (dict.count(check))	//if the string is in dict
					{
						if (!RoundSet.count(check))
						{
							RoundSet.insert(check);
							DelQue.push(check);		//这个深度的全部检查完之后，才能从dict中删除
							LadQue.push(check);
						}
						LadPre[check].push_back(PreWord);
					}
				}
				check[i] = tmp;
			}
			LadQue.pop();	//单词检查完毕,出队
		}
		RoundSet.clear();

		if (FindEnd)	//在这个深度的时候找到了最终跳转结果
		{
			PrintPreList(LadPre);
			FindPath(LadPre,LadRoad,start,end,OneRoad);
			return LadRoad;
		}

		while(!DelQue.empty())
		{
			string tmp = DelQue.front();
			dict.erase(tmp);
			DelQue.pop();
		}
	}
    return LadRoad;    
}


int main()
{
	string start="red";
	string end = "tax";
	string org[]= {"ted","tex","red","tax","tad","den","rex","pee"};
	set<string> dict;
	for(int i=0; i<8; i++)
		dict.insert(org[i]);
	vector<vector<string> > road;
	vector<vector<string> >::const_iterator road_it;
	vector<string>::const_iterator it;
	road = findLadders(start,end,dict);
	for (road_it = road.begin();road_it<road.end();road_it++)
	{
		for(it = (*road_it).begin(); it < (*road_it).end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}