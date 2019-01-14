#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> minutes = {" 
","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
                          
"fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty 
one","twenty two","twenty three",
                          "twenty four","twenty five","twenty 
six","twenty seven","twenty eight","twenty nine","half"};

string timeInWords(int h,int m) {
    if (m == 00) {
        return std::string(minutes[h]) + std::string(" o' clock");
    }

    if (m <= 30) {
        if(m==1)
            return std::string(minutes[m]) + std::string(" minute past 
") + std::string(minutes[h]);

        if(m==15)
            return std::string("quarter past ") + 
std::string(minutes[h]);

        if (m == 30)
            return std::string("half past ") + std::string(minutes[h]);


        return std::string(minutes[m]) + std::string(" minutes past ") + 
std::string(minutes[h]);
    }
    if(m>30) {
        m = 60 - m;
        h = h+1;
        if(h==13)
            h = 01;
        if (m == 1)
            return std::string(minutes[m]) + std::string(" minute to ") 
+ std::string(minutes[h]);

        if (m == 15)
            return std::string("quarter to ") + std::string(minutes[h]);

        if (m == 30)
            return std::string("half to ") + std::string(minutes[h]);

        return std::string(minutes[m]) + std::string(" minutes to ") + 
std::string(minutes[h]);
    }
}
int main() {

    cout << timeInWords(12,40);
    return 0;
}
