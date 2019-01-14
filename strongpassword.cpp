#include <iostream>
#include <regex>
#include <string>
using namespace std;

int strongpassword(int n,string password){
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    int number=0;
    int lower_c = 0;
    int upper = 0;
    int special =0;


    for(int i=0;i<password.size();i++)
    {
        for (int j = 0; j < 26; ++j) {
            if(number==0)
            {
                if(password[i]==numbers[j] && j<10)
                {
                    number=1;
                    continue;
                }
            }

            if(special==0)
            {
                if(password[i]==special_characters[j] && j < 13)
                {
                    special=1;
                    continue;
                }
            }


            if(upper==0)
            {
                if(password[i]==upper_case[j]){
                    upper=1;
                    continue;
                }
            }

            if(lower_c==0)
            {
                if(lower_case[j]==password[i])
                {
                    lower_c = 1;
                    continue;
                }
            }
        }
    }

    int total = 4-(lower_c + upper + number + special);
    if(n<6)
    {
        int rsize = 6 - n;
        if(rsize>(total))
            return rsize;
        else
            return total;
    }
    return total;
}


int main(void) {
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string pass = "abcd";

    cout << strongpassword(3,"zss");
}
