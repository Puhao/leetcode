#include <iostream>
#include <vector>

using namespace std;

int SearchLeft(int A[],int n,int target)
{
	int left = 0;
	int right = n-1;
	while(left<right)
	{
		int middle = left + (right - left)/2;
		if (A[middle] >= target)
		{
			right = middle;
		}
		else
			left = middle+1;
	}
	if (A[left] == target)
		return left;
	return -1;
}

int SearchRight(int A[],int n,int target)
{
	int left = 0;
	int right = n-1;
	while (left < right)
	{
		int middle = right - (right - left)/2;
		if (target >= A[middle])
		{
			left = middle;
		}
		else
			right = middle - 1;
	}
	if (A[right] == target)
		return right;
	return -1;
}

vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int left = SearchLeft(A,n,target);
		int right = SearchRight(A,n,target);
		vector<int> v;
		v.push_back(left);
		v.push_back(right);
		return v;       
    }


int main()
{
	int a[] = {2,2};
	cout << SearchLeft(a,sizeof(a)/sizeof(a[0]),2) << endl;
	cout << SearchRight(a,sizeof(a)/sizeof(a[0]),2) << endl;
	return 0;
}