//
// Created by ZlunYan on 2021/5/30.
//

#include <cstdio>
#include <vector>
using namespace std;

// 虽然是计数排序 但是这里还是有一些处理来节省空间的
int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> count(n + 1);

    for (int i = 0; i < n; i++) count[min(n, citations[i])] ++;

    // 下面这个循环写的也挺有意思的
    int answer = n;
    for (int s = count[n]; answer > s; s += count[answer])
        answer--;
    return answer;
}

int main () {
    vector<int> input = {3, 0, 6, 1, 5};
    printf("%d\n", hIndex(input));
    return 0;
}