#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> haveSeen;
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y<grid[x].size(); y++) {
                if (1 == grid[x][y])
                    res += getPerimeter(grid, x, y);
            }
        }
        return res;
    }
    
    //找到一个陆地点
    int getPerimeter(const vector<vector<int>>& grid, int posX, int posY) {
        int res = 0;
        //左
        if (0 == posY || 0 == grid[posX][posY - 1])
            res++;
        
        //右
        if (posY == grid[posX].size() - 1 || 0 == grid[posX][posY + 1])
            res++;
        
        //上
        if (0 == posX || 0 == grid[posX-1][posY])
            res++;
        
        //下
        if (posX == grid.size() - 1 || 0 == grid[posX+1][posY])
            res++;
        
        return res;
    }
};

int main() {
	Solution s;
    vector<int> a1 = {0, 1, 0, 0};
    vector<int> a2 = {1, 1, 1, 0};
    vector<int> a3 = {0, 1, 0, 0};
    vector<int> a4 = {1, 1, 0, 0};
    vector<vector<int>> test;
    test.push_back(a1);
    test.push_back(a2);
    test.push_back(a3);
    test.push_back(a4);
    cout << s.islandPerimeter(test);
	getchar();
	return 0;
}
