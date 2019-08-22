/* Krishna
Input  
First Line - Testcase
For every testcase First Line consists no of node and edge size seperated by space 
and next esize line consists from,to,cost
*/
#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;
int main() {

//    freopen("input.txt","r",stdin);
    int test;
    cin >> test;

    while(test--) {

        int Node,esize;
        cin >> Node >> esize;
        int cost[Node];
        int where[Node];

        for(int i=0;i<Node;i++){

            cost[i] = 0;
            where[i] = 0;

        }

        vector<pair<int,int>> edge[Node];
        for(int i=0;i<esize;i++){

            int from,to,price;
            cin >> from >> to >> price;
            edge[from-1].push_back({to-1,price});

        }

        cost[Node-1] = 0;
        where[Node-1] = Node-1;

        for(int i=Node-2;i>=0;i--){

            int temp = INT_MAX;
            int temp2 = 0;

            for(pair<int,int> x : edge[i]){

                if(x.second + cost[x.first] < temp){

                    temp = x.second + cost[x.first];
                    temp2 = x.first;

                }

            }

            cost[i] = temp;
            where[i] = temp2;

        }

//        for(int i=0;i<Node;i++)
//        {
//            cout << cost[i] << ' ' << where[i]+1 << '\n';
//        }

        cout << cost[0] << '\n';
    }

    return 0;
}
