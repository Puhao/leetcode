#include <iostream>

using namespace std;



    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while(i<n)
        {
        	if (A[i] >= 0 && A[i] < n && i != A[i])
        		swap(A[i],A[A[i]]);
        	else
        		i++;
        }
        for(int i=0;i<n;i++)
        	cout << A[i] << ' ';
        cout << endl;
        for(int j=1;j<n;j++)
        {
        	if (j != A[j])
        		return j;
        }
        return n;
        
}

int main()
{
	int A[] = {-5,1000};
	cout << firstMissingPositive(A,sizeof(A)/sizeof(A[0])) << endl;
	return 0;
}