{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
   
// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    int totalwater = 0;
    int maxleft = arr[0];
    int maxright = -1;
    for(int k=2;k<n;k++)
    {
        if(arr[k] > maxright){
            maxright = arr[k];}
    }

    for(int i=1;i<n-1;i++)
    {
        if(arr[i-1] > maxleft){
            maxleft = arr[i-1];
        }
		
		if(arr[i] == maxright)
		{
		    maxright = 0;
		    for(int k=i+1;k<n;k++)
            {
                if(arr[k] > maxright){
                    maxright = arr[k];}
            }
		}
        int minoftwo = min(maxleft,maxright);
		if(minoftwo > arr[i])
		{
			totalwater = totalwater + (minoftwo - arr[i]);
		}
    }
	return totalwater;
}
