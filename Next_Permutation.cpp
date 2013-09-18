#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if (n <= 1)
        	return;
        int i = n-1;
        int j = i-1;
        while(j>=0)
        {
            if(num[j] < num[i])
                break;
            else
            {
                i--;
                j--;
            }
        }
        if (j == -1)
        {
            sort(num.begin(),num.end());
            return;
        }
        int k = i;
        for(;i<n;i++)
        {
            if (num[i] > num[j])
                k = i;
            else
                break;
        }
        swap(num[j],num[k]);
        sort(&num[j+1],&num[n]);
        return;
    }

int main()
{
	vector<int> num = {4,2,0,2,3,2,0};
	nextPermutation(num);
	for (auto i:num)
		cout << i << ' ';
	return 0;
}