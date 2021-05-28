//
// Created by ZlunYan on 2021/5/27.
//

// 拓扑排序啦
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int Num_Course = 100005;
const int Num_Edge = 5005;

int pre[Num_Course] = {0};
int head[Num_Course] = {0};
int nxtCourse[Num_Edge] = {0};
int nxtEdge[Num_Edge] = {0};

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    for (int i = 0; i < prerequisites.size(); i++) {
        nxtEdge[i + 1] = head[prerequisites[i][1] + 1];
        head[prerequisites[i][1] + 1] = i + 1;
        nxtCourse[i + 1] = prerequisites[i][0] + 1;
        pre[prerequisites[i][0] + 1] ++;
    }

    stack<int> available;
    vector<int> answer;
    for (int i = 1; i <= numCourses; i++) if (!pre[i]) available.push(i);
    while (!available.empty()) {
        int top = available.top(); available.pop();
        answer.push_back(top - 1);
        for (int i = head[top]; i; i = nxtEdge[i]) {
            pre[nxtCourse[i]] --;
            if (!pre[nxtCourse[i]]) available.push(nxtCourse[i]);
        }
    }

//    return answer;
    if (answer.size() == numCourses) return answer;
    else return {};
}

int main () {
    /*
    {1, 0},
            {2, 0},
            {3, 1},
            {3, 2}

            4
     */
    vector<vector<int>> input = {
            {1, 0},
            {0, 1}
    };
    vector<int> answer = findOrder(3, input);
    for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
}