#include <iostream>

using namespace std;

int findKthNum(int a[], int m, int b[],int n,int k)
{
	if (m > n)
		return findKthNum(b,n,a,m,k);
	if (m <= 0)
		return b[k-1];
	if (k == 1)
		return min(a[0],b[0]);
	int p = min(k/2,m);
	if (a[p-1] < b[p-1])
	{
		return findKthNum(a+p,m-p,b,n,k-p);
	}
	else
		return findKthNum(a,m,b+p,n-p,k-p);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int sum = m+n;
		if (sum%2 == 0)
			return (findKthNum(A,m,B,n,sum/2) + findKthNum(A,m,B,n,sum/2+1))/2.0;
		else
			return findKthNum(A,m,B,n,sum/2+1);

}

int main()
{
	int a[] = {1,2,3,4,6,35,45,55};
	int b[] = {4,7,9};
	cout << findKthNum(a,8,b,3,11) << endl;
	cout << findMedianSortedArrays(a,8,b,3) << endl;
	return 0;
}