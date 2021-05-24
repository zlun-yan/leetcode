//
// Created by ZlunYan on 2021/5/24.
//

//并查集 统计根的数量?
// 不对 并查集并不好处理这个问题
// 这里使用了BFS并修改了原数组

#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    bool doit = true;
    queue<pair<int , int>> coordinate;
    while (doit) {
        doit = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    count++;
                    doit = true;
                    coordinate.push(make_pair(i, j));
                    while (!coordinate.empty()) {
                        int x = coordinate.front().first, y = coordinate.front().second; coordinate.pop();
                        for (int k = 0; k < 4; k++) {
                            int newX = x + dir[k][0], newY = y + dir[k][1];
                            if (0 <= newX && newX < grid.size() && 0 <= newY && newY < grid[0].size() && grid[newX][newY] == '1') {
                                grid[newX][newY] = '0';
                                coordinate.push(make_pair(newX, newY));
                            }
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main () {
    vector<vector<char>> input = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    printf("%d\n", numIslands(input));
    return 0;
}