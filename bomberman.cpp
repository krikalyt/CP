#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> bomberManHelper(int n, vector<string> grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<string> gridtemp;
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
            gridtemp = grid;
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
    return grid;
}


vector<string> bomberMan(int n, vector<string> grid) {
    vector<string> gridtemp = bomberManHelper(2,grid);
    vector<string> gridtemp3 = bomberManHelper(3,grid);
    vector<string> gridtemp3rev = bomberManHelper(3,gridtemp3);
    if(n==0) {
        return grid;
    }
    if(n==1)
        return grid;
    if(n==2)
        return gridtemp;
    if(n==3)
        return gridtemp3;

    if((n%2)==0)
    {
        return gridtemp;
    }
    int temp = n%20;
    if(temp==1)
        return gridtemp3rev;
    if(temp==3)
        return gridtemp3;
    if(temp==5)
        return gridtemp3rev;
    if(temp==7)
        return gridtemp3;
    if(temp==9)
        return gridtemp3rev;
    if(temp==11)
        return gridtemp3;
    if(temp==13)
        return gridtemp3rev;
    if(temp==15)
        return gridtemp3;
    if(temp==17)
        return gridtemp3rev;
    if(temp==19)
        return gridtemp3;
    
    return (vector<string>)NULL;
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
