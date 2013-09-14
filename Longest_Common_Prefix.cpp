#include <iostream>
#include <string>
#include <vector>

using namespace std;



  string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  	string prefix;
  	vector<string>::const_iterator it;
  	if (strs.size() == 0)
  		return prefix;
  	int index = 0;
  	char tmp;
  	while(true)
  	{
  		if (index >= strs.begin()->size())
  			return prefix;
  		tmp = (*strs.begin())[index];
  		for(it = strs.begin();it != strs.end();it++)
  		{
  			if (it->size() <= index)
  				return prefix;
  			if ((*it)[index] != tmp)
  				return prefix;
  		}
  		index++;
  		prefix.push_back(tmp);
  	}
  	return prefix;
  }



int main()
{
	vector<string> strs;
	string s[] = {"abc","abd","ab","abef"};
	for (int i=0;i<sizeof(s)/sizeof(s[0]);i++)
		strs.push_back(s[i]);
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}