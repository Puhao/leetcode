#include <iostream>
#include <string>
#include <vector>

using namespace std;

    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = a.size();
        int l2 = b.size();
        int l = l1 > l2 ? l1 : l2;
        vector<int> v(l+1,0);
        int carry = 0;
        for(int i=0;i < l;i++)
        {
        	int n1;
        	int n2;
        	if(i >= l1)
        		n1 = 0;
        	else
        		n1 = a[l1-i-1] - '0';
        	if(i >= l2)
        		n2 = 0;
        	else
        		n2 = b[l2-i-1] - '0';
        	carry = n1 + n2 + carry;
        	v[i] = carry % 2;
        	carry = carry / 2;
        }
        v[l] = carry;
        int i = l+1;
        string ret = "";
        while(v[--i] == 0 && i>0);
        while(i>=0)
        {
        	ret +=v[i--] + '0';
        }
        return ret;
    }

int main()
{
	string s1 = "111";
	string s2 = "11";
	cout << addBinary(s1,s2) << endl;
	return 0;
}