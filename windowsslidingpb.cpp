{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    int maxsum = 0;
    int max = 0;
    int maxele = -10000001;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > maxele){
            maxele = arr[i];
        }
        max = max + arr[i];
        
        if(max > maxsum)
        {
            maxsum = max;
        }
        
        if(max < 0)
        {
            max = 0;
        }
    }
    
    if(maxele < 0)
    {
        return maxele;
    }
    
    return maxsum;
}
