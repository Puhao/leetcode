#include <iostream>
#include <string>
#include <vector>

using namespace std;


string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int l1 = num1.size();
	int l2 = num2.size();
	vector<int> v(l1+l2,0);
	for(int i=0;i<l1;i++)
	{
		int n1 = num1[l1-i-1] - '0';
		int carry = 0;
		for(int j=0;j<l2;j++)
		{
			int n2 = num2[l2-j-1] - '0';
			carry = carry + n1*n2 + v[i+j];
			v[i+j] = carry % 10;
			carry = carry / 10;
		}
		v[i+l2] = carry;
	}
	int i = l1+l2;
	while(v[--i] == 0 && i > 0);
	string s = "";
	while(i>=0)
	{
		s += v[i--] + '0';
	}
	return s;
        
}

int main()
{
	string s1 = "34";
	string s2 = "25";
	cout << multiply(s1,s2) << endl;
	return 0;
}
