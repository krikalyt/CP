#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
std::string::iterator findsmall(string &abc,int pos)
{
    string abc2(abc);
    string::iterator it;
    string::iterator it2;

    it = abc.begin()+pos;
    sort(abc2.begin()+pos+1,abc2.end());

    for(it2=abc2.begin()+pos+1;it2!=abc2.end();it2++)
    {
        if((*it2)>*it)
        {
            return find(it+1,abc.end(),*it2);
        }
    }
    return abc.end();
}

string biggerisGreater(string abc)
{
    string::iterator it;
    string::iterator it2;
    int number = (abc.size()-2);
    for(int i=number;i>=0;i--) {
        it = abc.begin() + i + 1;
        it2 = findsmall(abc,i);
        if(*it2==0)
        {
            continue;
        }
        if (*it2 > abc[i])
        {
            char temp = *it2;
            *it2 = abc[i];
            abc[i] = temp;
            sort(it,abc.end());
            return abc;
        }
    }
    return "no answer";
}



int main(void) {
    string abc = "fedcbabcd";
    cout << biggerisGreater(abc);
    return 0;
}


