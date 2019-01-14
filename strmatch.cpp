#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
bool stringpattern(std::string abc,std::string mno)
{

    for (int i = 0; i < (abc.size()-mno.size()); ++i) {
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
    std::chrono::system_clock::time_point start = 
std::chrono::system_clock::now();
    string abc = "Hello there i was very happy after listenting that i 
am very cool guy in the world. But i do not like the way people treat 
me..";
    cout << stringpattern(abc,"listenting") << endl;
    
    std::chrono::system_clock::time_point end = 
std::chrono::system_clock::now();
    std::chrono::duration<float> dur;
    dur = end-start;
    cout << dur.count();
    return 0;
}
