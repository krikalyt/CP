#include<bits/stdc++.h>
using namespace std;
void merge(int arr1[],int arr2[],int sizeofone,int sizeoftwo)
{
    int arsize = sizeofone+sizeoftwo;
    int arr[arsize];
    int f = 0;
	int s = 0;
    int i=  0;

    while(f < sizeofone && s < sizeoftwo)
    {
        if(arr1[f]<=arr2[s])
        {
            arr[i] = arr1[f];
            f++;
        }
        else{
            arr[i] = arr2[s];
            s++;
        }
        i++;
    }

    while(f<sizeofone)
    {
        arr[i] = arr1[f];
        f++;
        i++;
    }

    while(s<sizeoftwo)
    {
        arr[i] = arr2[s];
        s++;
        i++;
    }
    
    if(arsize%2==0)
    {
        cout << (arr[(arsize/2)-1] + arr[((arsize/2))])/2 << '\n';
    }else{
        cout << arr[arsize/2] << '\n';
    }
    
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	int test;
	cin >> test;
	while(test--)
	{
	    int sizeofone;
	    int sizeoftwo;
	    cin >> sizeofone;
	    cin >> sizeoftwo;
	    int arr[sizeofone];
	    int arr2[sizeoftwo];
	    for(int i=0;i<sizeofone;i++)
	        cin >> arr[i];
	    for(int i=0;i<sizeoftwo;i++)
	        cin >> arr2[i];
	   
	    merge(arr,arr2,sizeofone,sizeoftwo);
	}
	return 0;
}
