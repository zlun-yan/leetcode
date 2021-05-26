//
// Created by ZlunYan on 2021/5/26.
//

// 拓扑排序吧
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int Num_Node = 100010;
const int Num_Edge = 5010;

int preCourse[Num_Node] = {0};
// 链式向前星
int head[Num_Node] = {0};
int nxtNode[Num_Edge] = {0};
int nxtEdge[Num_Edge] = {0};
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for (int i = 0; i < prerequisites.size(); i++) {
        nxtEdge[i + 1] = head[prerequisites[i][0] + 1];
        head[prerequisites[i][0] + 1] = i + 1;
        nxtNode[i + 1] = prerequisites[i][1] + 1;
        preCourse[nxtNode[i + 1]] ++;
    }

    stack<int> available;
    int count = 0;
    for (int i = 1; i <= numCourses; i++) if (!preCourse[i]) {
            available.push(i);
            count ++;
    }
    while (!available.empty()) {
        int root = available.top(); available.pop();
        for (int i = head[root]; i; i = nxtEdge[i]) {
            preCourse[nxtNode[i]] --;
            if (!preCourse[nxtNode[i]]) {
                available.push(nxtNode[i]);
                count ++;
            }
        }
    }

    return count == numCourses;
}

int main () {
    vector<vector<int>> input = {{1, 0}, {0, 1}};
    printf("%d\n", canFinish(2, input));
    return 0;
}