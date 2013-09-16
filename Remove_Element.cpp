#include <iostream>

using namespace std;

    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = n;
        for (int i=0;i<len;)
        {
        	if (A[i] == elem)
        	{
        		A[i] = A[--len];
        	}
        	else
        		i++;
        }
        return len;
        
    }

int main()
{
	int a[] = {3,3};
	cout << removeElement(a,sizeof(a)/sizeof(a[0]),3) << endl;
	return 0;
}