//https://practice.geeksforgeeks.org/problems/range-sum-queries/0/?track=PC-W9-ST&batchId=140
//Square Root Decomposition 
#include <iostream>
#include <cmath>
#include <climits>

#define min(a,b) a<b?a:b;
#define max(a,b) a>b?a:b;
using namespace std;

/*Build Segment for SqureRoot Decomposition*/
int size;
int ssize;
int sstep;

long segment[10000];
void fill(int arr[],int segno){
	long sum = 0;
	int left =	segno*sstep;
	int right = min(left+sstep,size);
	for(int i=left;i<right;i++)
		sum = sum + arr[i];
	segment[segno] = sum;
}

//update 
void update(int arr[],int index,int value){
	int segfind = index/sstep;
	segment[segfind] = segment[segfind] - arr[index] + value;
	arr[index] = value;
}

//Range Query
long rangeQuery(int arr[],int left,int right){
	int leftseg = left/sstep;
	int rightseg =	right/sstep;
	long ans = 0;
	for(int i=leftseg+1;i<rightseg;i++)
		ans = ans + segment[i];
	
	if(leftseg == rightseg){
		for(int i=left;i<=right;i++)
			ans = ans + arr[i];
	}else{
		for(int i=left;i<(sstep*(leftseg+1));i++)
			ans = ans + arr[i];
		for(int i=rightseg*sstep;i<=right;i++)
			ans = ans + arr[i];
	}
	return ans;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
	int test;
	cin >> test;
	while(test--)
	{
	    int query;
		cin >> size;
		cin >> query;
		int arr[size];
		for(int i=0;i<size;i++)	
			cin >> arr[i];
		ssize = ceil(sqrt(size));
		sstep = sqrt(size);
		for(int i=0;i<ssize;i++)
			fill(arr,i);
		
		while(query--)
		{
		    char c;
		    cin >> c;
		    if(c=='G'){
		        int left,right;
		        cin >> left >> right;
		        cout << rangeQuery(arr,left,right) << '\n';
		    }else{
		        int index,value;
		        cin >> index >> value;
		        update(arr,index,value);
		    }
		}
	}
	return 0;
}
