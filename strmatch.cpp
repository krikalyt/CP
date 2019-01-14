#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
bool stringpattern(std::string abc,std::string mno)
{

    for (int i = 0; i < (abc.size()-mno.size()+1); ++i) {
        string temp = abc.substr(i,mno.size());
        if(temp==mno)
        {
            return true;
        }
    }
    return false;
}
int main(void)
{
    string abc = "Hello there i was very happy after listenting that i am very cool guy in the world. But i do not like the way people treat mz";
    cout << stringpattern(abc,"z") << endl;
    return 0;
}
