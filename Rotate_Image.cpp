#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = matrix.size();
		int right = n-1;
		int index = 0;
		while(index<n/2)
		{
			right = n-1 - index;
			for(int j=index;j<right;j++)
			{
				swap(matrix[index][j],matrix[n-1-j][index]);
				swap(matrix[n-1-j][index],matrix[right][n-1-j]);
				swap(matrix[right][n-1-j],matrix[j][right]);
			}
			index++;
		}
        return;
    }

int main()
{
	vector<vector<int> > v = {vector<int>{1,2,3},std::vector<int>{4,5,6},vector<int>{7,8,9}};
	for(auto i:v)
	{
		for(auto j:i)
			cout << j << ' ';
		cout << endl;
	}
	rotate(v);
	for(auto i:v)
	{
		for(auto j:i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}