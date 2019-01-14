#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void swap(vector<int> &abc,int i,int j)
{
    int temp = abc[i];
    abc[i] = abc[j];
    abc[j] = temp;
}
void almostSorted(vector<int> abc)
{
    vector<int> temp4;
    stack<int> temp;
    for (int i = 0; i < abc.size() -1 ; ++i) {
        if(abc[i]>abc[i+1])
        {
            temp.push(i);
            temp4.push_back(i);
        }
    }

    if(temp.size()==0)
    {
        cout << "yes" << endl;
        return;
    }

    if(temp.size()==1)
    {
        int temp2 = temp.top();
        temp.pop();
        swap(abc,temp2,temp2+1);

        if(is_sorted(abc.begin(),abc.end())){
            cout << "yes" << endl;
            cout << "swap " << temp2+1 << " " << temp2+2;
            return;
        }
        else{
            cout << "no" << endl;
            return;
        }

    }

    if(temp.size()==2)
    {
        int temp2 = temp.top()+1;
        temp.pop();
        int temp3 = temp.top();
        temp.pop();
        swap(abc,temp2,temp3);

        if(is_sorted(abc.begin(),abc.end())){
            cout << "yes" << endl;
            cout << "swap " << temp3+1 << " " << temp2+1;
            return;
        }
        else{
            cout << "no" << endl;
            return;
        }

    }

    if(temp.size()>2)
    {
        vector<int> ::iterator it;
        it = abc.begin();
        int temp3 = temp4.front();
        int temp5 = temp4.back();
        reverse(it+temp3,it+temp5+2);

        if(is_sorted(abc.begin(),abc.end())){
            cout << "yes" << endl;
            cout << "reverse " << temp3 + 1 << " " << temp5+2;
            return;
        }

        else{
            cout << "no" << endl;
            return;
        }
    }
}
int main(void)
{
    vector<int> abc = {2,3,5,4};
    almostSorted(abc);
    return 0;
}
