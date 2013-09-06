#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<vector<char> > Matrix;
        if(s.size() <= nRows)
        	return s;
        if(nRows <= 1)
        	return s;
        std::vector<char> v;
        for(int i=0;i<nRows;i++)
        	Matrix.push_back(v);
        for(int i=0;i<s.size();i++)
        {
        	int pos = i % (nRows+nRows-2);
        	if(pos < nRows)
        	{
        		Matrix[pos].push_back(s[i]);
        	}
        	else
        	{
        		Matrix[2*nRows - pos - 2].push_back(s[i]);
        	}
        }
        string r;
        vector<vector<char> >::const_iterator m_it;
        vector<char>::const_iterator v_it;
        for(m_it=Matrix.begin();m_it<Matrix.end();m_it++)
        {
        	for(v_it=m_it->begin();v_it!=m_it->end();v_it++)
        	{
        		r.push_back(*v_it);
        	}
        }
        return r;
    }

int main()
{
	string s = "PAYPALISHIRING";
	cout << convert(s,3) << endl;
	return 0;
}
