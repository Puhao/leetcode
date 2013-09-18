#include <iostream>

using namespace std;

bool search(int A[], int n, int target)
{
	int left = 0;
	int right = n-1;
	while(left<= right)
	{
		int middle = left + (right - left) / 2;
		if (target == A[middle])
			return true;
		if (A[middle] > A[right])
		{
			if(target >= A[left] & target < A[middle])
			{
				right = middle -1;
			}
			else
			{
				left = middle + 1;
			}
		}
		else if (A[middle] < A[right])
		{
			if(target > A[middle] && target <= A[right])
			{
				left = middle + 1;
			}
			else
			{
				right = middle - 1;
			}
		}
		else //middle = right
		{
			while(A[middle] == A[--right]);
		}
	}
	return false;
}


int main()
{
	int a[] = {6,7,9,10,11,1,2,3,4,5};
	int t = 4;
	cout << search(a,sizeof(a)/sizeof(a[0]),t) << endl;
	return 0;
}