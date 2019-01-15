#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> bomberMan(int n, vector<string> grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<pair<int,int>> temp;
    for(int i=0;i<=(3)&&i<=n;i++) {
        if (i == 0) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    if (grid[j][k] == 'O') {
                        temp.push_back(pair<int, int>(j, k));
                    }
                }
            }
        }

        if (i == 2) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    grid[j].at(k) = 'O';
                }
            }

        }

        if (i == 3) {
            for (auto item: temp) {
                grid[item.first].at(item.second) = '.';
                if (item.first != (r - 1)) {
                    grid[item.first + 1].at(item.second) = '.';
                }

                if (item.first != 0) {
                    grid[item.first - 1].at(item.second) = '.';
                }
                if (item.second != (c - 1)) {
                    grid[item.first].at(item.second + 1) = '.';
                }
                if (item.second != 0) {
                    grid[item.first].at(item.second - 1) = '.';
                }
            }
            temp.clear();
        }
    }


    for(int i=4;i<=(n);i++)
    {
        int remainder = i%2;
        if(remainder==0)
        {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    if(grid[j][k]=='O')
                    {
                        temp.push_back(pair<int,int>(j,k));
                    }
                }
            }

            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    grid[j].at(k) = 'O';
                }
            }
            if(i==n)
                return grid;
            continue;
        }

        if(remainder==1)
        {
            for(auto item: temp)
            {
                grid[item.first].at(item.second) = '.';
                if(item.first!=(r-1))
                {
                    grid[item.first+1].at(item.second) = '.';
                }

                if(item.first!=0)
                {
                    grid[item.first-1].at(item.second) = '.';
                }
                if(item.second!=(c-1))
                {
                    grid[item.first].at(item.second+1) = '.';
                }
                if(item.second!=0)
                {
                    grid[item.first].at(item.second-1) = '.';
                }
            }
            temp.clear();
        }
    }
    return grid;
}
int main(void)
{
    string kri = ".......";
    string kum = "...O.O.";
    string yad = "....O..";
    string kal = "..O....";
    string tiw = "OO...OO";
    string khu = "OO.O...";
    vector<string> abc = {kri,kum,yad,kal,tiw,khu};
    vector<string> abb =  bomberMan(1,abc);
    cout << abb[0] << endl;
    cout << abb[1] << endl;
    cout << abb[2] << endl;
    cout << abb[3] << endl;
    cout << abb[4] << endl;
    cout << abb[5] << endl;

    return 0;
}