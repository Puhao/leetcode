#include <iostream>


using namespace std;

    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <=1)
        	return n;
        int i=1;
        int j=1;
        int pre = A[0];
        while(j<n)
        {
        	if (A[j] == pre)
        	{
        		j++;
        	}
        	else
        	{
        		pre = A[j];
        		if (i != j)
        			swap(A[i],A[j]);
        		i++;
        		j++;
        	}
        }
        return i;        
    }

int main()
{
	int A[] = {1,2,4,4,5,5,7,9,11,13,13,16};
	cout << removeDuplicates(A,12) << endl;
	return 0;
}