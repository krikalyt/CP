/* https://www.hackerearth.com/problem/algorithm/print-subset-sum-to-k/#c200799 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool subset_sum(vector<int> tempsum,int arr[],int i,int sum,int k,int size){

    if(sum > k)
        return false;
    if(sum == k){
        for(int x : tempsum){
            cout << x << ' ';
        }
        cout << '\n';
        return true;
    }

    if(i >= size)
        return false;


    bool gotit = subset_sum(tempsum,arr,i+1,sum,k,size);
    tempsum.push_back(arr[i]);
    bool gotit2 = subset_sum(tempsum,arr,i+1,sum+arr[i],k,size);
    tempsum.pop_back();
    return gotit or gotit2;
}
main()
{
    //subset sum equal to k 
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> abc;
    subset_sum(abc,arr,0,0,k,n);
}
