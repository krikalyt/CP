#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
string stringpattern(std::string abc)
{
    string acb = "not";
    for (int i = 0; i < abc.size()-2; ++i) {

        string temp = {abc[i],abc[i+1],abc[i+2]};
        if(temp==acb)
        {
            return "true string";
        }
    }
    return "not true string";
}
int main(void)
{
    std::chrono::system_clock::time_point start = 
std::chrono::system_clock::now();
    string abc = "Hello there i was very happy after listenting that i 
am very cool guy in the world. But i do not like the way people treat 
me..";
    cout << stringpattern(abc);
    std::chrono::system_clock::time_point end = 
std::chrono::system_clock::now();
    std::chrono::duration<float> dur;
    dur = end-start;
    cout << dur.count();
    return 0;
}



