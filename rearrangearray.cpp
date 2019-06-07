//Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
//Note: O(1) extra space is allowed. Also, try to modify the input array as required.


{
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
// Driver program to test above function 
int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

}
/*This is a function problem.You only need to complete the function given below*/
// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(int *arr, int n) 
{ 
    int turn = 0;
    int low = 0;
    int high = n-1;
    int brr[n];
	for(int i=0;i<n;i++)
	{
	    if(turn==0)
	    {
	       brr[i] = arr[high];
	       high--;
	       turn  = 1;
	    }else{
	       brr[i] = arr[low];
	       low++;
	       turn = 0;
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    arr[i] = brr[i];
	}
}
