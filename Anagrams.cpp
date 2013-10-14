#include <iostream>
#include <vector>

using namespace std;

bool IsValid(string &str)
{
	int len = str.size();
	if (len == 0)
		return false;
	int i = 0;
	int j = len-1;
	while(i<j)
	{
		if(str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}
vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
	vector<string> Ret;
	for(auto i:strs)
	{
		if (IsValid(i))
			Ret.push_back(i);
	}
	return Ret;
}

int main()
{
	vector<string> strs = {"aba","bbd","aa"};
	vector<string> v;
	v = anagrams(strs);
	for (auto i:v)
	{
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}