//problem - Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
void winner(string arr[],int n);
string legoxical(string name,string name2){
    int temp = min(name.size(),name2.size());
    for(int i=0;i<temp;i++)
    {
        if(name[i] < name2[i])
        {
            return name;
        }else if(name[i] == name2[i]){
            
        }else{
            return name2;
        }
    }
    
    if(temp == name.size())
        return name;
    else
        return name2;
}
int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        winner(arr,n);
        
        cout<<endl;
        
        
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
// Funtion to find winner
// arr[]: input array
// n: size of array


#include <string>
#include <utility>
#include <unordered_map>




void winner(string arr[],int n)
{
    unordered_map<string,int> abc;
    string shorts = arr[0];
    string name = "";
    int num  = 0;
    for(int i=0;i<n;i++)
    {
        auto temp = abc.find(arr[i]);
        if(temp == abc.end()){
            abc.insert({arr[i],1});
        }else{
            temp->second++;
            if(temp->second > num ){
                num = temp->second;
                name = temp->first;
            }else if(temp->second == num)
            {
                name = legoxical(name,arr[i]);
            }
        }
        
        shorts = legoxical(shorts,arr[i]);
    }
    
    if(num==0)
        cout << shorts << " " << 1;
    else{
        cout << name << " " << num;
    }
}
