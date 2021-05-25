//
// Created by ZlunYan on 2021/5/24.
//

// 既然之前那样做超时了
// 也很简单可以想到解决的办法 那就是在建树的时候，对于每一条边 都更新从这条边走的子树的高度
// 这样就可以不用DFS了
// 因为边的方向确定，这棵树的方向也就确定了

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int LEN = 2e4 + 5;

bool vis[LEN] = {0};
int head[LEN] = {0};
struct Edge {
    int nxtNode, nxtEdge, height;
    // maxHeight 代表 以 nxtNode 为根的子树 按照 root->nxtNode 的方向 的高度
    Edge() : nxtNode(0), nxtEdge(0), height(0) {}
}edge[LEN * 2];

// 计算以root为根 按照 pre->root 的方向的子树的高度
int cntMaxHeight(int root, int pre) {
    int answer = 1;
    for (int i = head[root]; i; i = edge[i].nxtEdge) {
        if (edge[i].nxtNode != pre) {
            if (!edge[i].height) edge[i].height = cntMaxHeight(edge[i].nxtNode, root);
            answer = max(answer, edge[i].height + 1);
        }
    }
    return answer;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    for (int i = 1; i <= edges.size(); i++) {
        edge[i].nxtNode = edges[i - 1][1] + 1;
        edge[i].nxtEdge = head[edges[i - 1][0] + 1];
        head[edges[i - 1][0] + 1] = i;

        edge[i + edges.size()].nxtNode = edges[i - 1][0] + 1;
        edge[i + edges.size()].nxtEdge = head[edges[i - 1][1] + 1];
        head[edges[i - 1][1] + 1] = i + edges.size();
    }

    int minHeight = n + 1;
    vector<int> answer;
    for (int i = 1; i <= n; i++) {
        int height = cntMaxHeight(i, 0);
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