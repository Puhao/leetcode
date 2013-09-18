#include <iostream>

using namespace std;

int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (n <= 0)
		return -1;
	if (n == 1)
	{
		if (target == A[0])
			return 0;
		else
			return -1;
	}
	int left = 0;
	int right = n -1;
	int middle;
	while(left <= right)
	{
		middle = left + (right -left) / 2;
		if (target == A[middle])
			return middle;
		if (A[middle] > A[right])
		{
			if (target >= A[left] && target < A[middle])
			{
				right = middle -1;
			}
			else
				left = middle + 1;
		}
		else
		{
			if (target > A[middle] && target <= A[right])
			{
				left = middle + 1;
			}
			else
				right = middle - 1;
		}
    }
    return -1;
}

int main()
{
	int a[] = {6,7,9,10,11,1,2,3,4,5};
	int t = 4;
	cout << search(a,sizeof(a)/sizeof(a[0]),t) << endl;
	return 0;
}