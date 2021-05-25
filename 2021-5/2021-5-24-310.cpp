//
// Created by ZlunYan on 2021/5/24.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int LEN = 2e4 + 5;

// 链式向前星
// 这样做超时了 嘤嘤嘤
bool vis[LEN] = {0};
int head[LEN] = {0};
struct Edge {
    int nxtNode, nxtEdge;
    Edge() : nxtNode(0), nxtEdge(0) {}
}edge[LEN * 2];

int dfs(int root) {
    int maxHeight = 0;
    vis[root] = 1;

    for (int i = head[root]; i; i = edge[i].nxtEdge) if (!vis[edge[i].nxtNode]) maxHeight = max(maxHeight, dfs(edge[i].nxtNode) + 1);
    return maxHeight;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    int minHeight = n + 1;
    vector<int> answer;
    // 先建图吧
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= edges.size(); i++) {
        edge[i].nxtNode = edges[i - 1][1] + 1;
        edge[i].nxtEdge = head[edges[i - 1][0] + 1];
        head[edges[i - 1][0] + 1] = i;

        edge[i + edges.size()].nxtNode = edges[i - 1][0] + 1;
        edge[i + edges.size()].nxtEdge = head[edges[i - 1][1] + 1];
        head[edges[i - 1][1] + 1] = i + edges.size();
    }

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        int height = dfs(i);
        if (height < minHeight) {
            minHeight = height;
            answer.clear();
            answer.push_back(i - 1);
        } else if (height == minHeight) answer.push_back(i - 1);
    }

    return answer;
}

int main () {
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    vector<int> answer = findMinHeightTrees(4, edges);
    for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
    printf("\n");
    return 0;
}