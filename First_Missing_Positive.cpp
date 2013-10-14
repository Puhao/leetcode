#include <iostream>

using namespace std;



    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return 1;
        if (n == 1)
        {
            if (A[0] == 1)
                return 2;
            else
                return 1;
        }
        int i = 0;
        while(i<n)
        {
        	if (A[i] >= 0 && A[i] < n && i != A[i])
            {
        		swap(A[i],A[A[i]]);
                i++;
            }
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
	int A[] = {1,1};
	cout << firstMissingPositive(A,sizeof(A)/sizeof(A[0])) << endl;
	return 0;
}