#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define N 10
int n;
bool touch = false;
using namespace std;
//N Queens function
bool checking_function(int arr[][10],int row,int column){
    for(int i=0;i<n;i++){
        if(arr[row][i]==1){
            return false;
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i][column]==1){
            return false;
        }
    }

    for(int i=row,j=column;i>=0 && j >= 0;  i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }

    for(int i=row,j=column;i>=0 && j < n;  i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }

    return true;
}
bool solve_nqueens(int arr[][10],int row){
    if(row >= n){
        touch = true;
        cout << '[';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(arr[i][j])
                    cout << j+1 << ' ';
        }
        cout << ']';
        cout << ' ';
    }

    for(int i=0;i<n;i++)
    {
        if(checking_function(arr,row,i)){
            arr[row][i] = 1;
            solve_nqueens(arr,row+1);
            arr[row][i] = 0;
        }
    }

    return false;
}
main()
{
    //N Queens Problem
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
    {
        touch = false;
        cin >> n;
        int arr[n][10];
        for(int i=0;i<n;i++)
        {
            fill(arr[i],arr[i]+n,0);
        }
        solve_nqueens(arr,0);
        if(touch == false)
            cout << -1;
        cout << '\n';
    }
}
