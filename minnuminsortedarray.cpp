// problem statement - Given an array A  which is sorted and contains N distinct elements. Also, this array is rotated at some unknown point. The task is to find the minimum element in it.

{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];		
		cout << minNumber(a,0,n-1) << endl;
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
// Function to find the minimum element in sorted and rotated array
// arr: input array
// low and high are 0 and n-1, where n is the size of arr
int minNumber(int arr[], int low, int high)
{
    int indexofsmall = 0;
    for(int i=1;i<=high;i=i*2)
    {
        if(arr[i] < arr[0]){
            indexofsmall = i;
            break;
        }
    }
    
    
    
    if(indexofsmall==0)
    {
        if(arr[high]<arr[0]){
            for(int i=high;i>=0;i--)
            {
                if(arr[i-1] > arr[i]){
                    return arr[i];
                }
            }
        }else{
            return arr[0];
        }
    }else{
        for(int i=indexofsmall;i>=0;i--)
        {
            if(arr[i-1] > arr[i]){
                return arr[i];
            }
        }
    }
    
    return -1;
}
