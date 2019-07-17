//Problem - https://www.hackerrank.com/challenges/components-in-graph/problem

#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

struct DJS{
    
    vector<int> abc;
    DJS(int size)
    {
        abc.resize(size);
        for(int i=0;i<size;i++)
            abc[i] = -1;
    }

    int find(int x)
    {
        if(abc[x] < 0){
            return x;
        }
        int par = find(abc[x]);
        abc[x] = par;
        return par;
    }

    void insert(int x,int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;

        int eleinxg = abs(abc[px]);
        int eleinyg = abs(abc[py]);
        if(eleinxg > eleinyg)
        {
            abc[py] = px;
            abc[px] = 0-(eleinxg + eleinyg);
        }else{
            abc[px] = py;
            abc[py] = 0-(eleinxg + eleinyg);
        }
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    DJS djs = DJS((N*2)+1);
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        djs.insert(a,b);
    }

    int mine = INT_MAX;
    int maxe = 1;
    
    for(int i=1;i<djs.abc.size();i++){
        if(djs.abc[i] < -1){
            maxe = max(maxe,-djs.abc[i]);
            mine = min(mine,-djs.abc[i]);
        }
    }

    cout << mine << ' ' << maxe << '\n';
    return 0;
}
