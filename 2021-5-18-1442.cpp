//
// Created by ZlunYan on 2021/5/18.
//

// 异或的逆运算是异或 可以用这个性质来求前缀和
// suffix[i] : 数组下标0到下标i的元素的异或
// m到n的异或 = suffix[m] ^ suffix[n - 1]
// (i, j - 1) 和 (j, k)的异或相等 : suffix[k] ^ suffix[j - 1] == suffix[i - 1] ^ suffix[j - 1]  因此只需要 suffix[k] == suffix[i - 1]
#include <cstdio>
const long len = 310;
int suffix[len], arr[len];

int main () {
    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i ++) scanf("%d", &arr[i]);
    suffix[0] = arr[0];
    for (int i = 1; i < l; i++) suffix[i] = suffix[i - 1] ^ arr[i];
    for (int i = 0; i < l; i++) printf("%d ", suffix[i]);
    printf("\n");

    int answer = 0;
    for (int k = 0; k < l; k++) {
        for (int j = 0; j <= k; j++) {
            for (int i = 0; i < j; i++) {
                int a = i == j - 1 ? suffix[i] : suffix[j - 1] ^ suffix[i];
                int b = j == k ? suffix[k] : suffix[k] ^ suffix[j];
                printf("## %d %d %d ##\n", i, j, k);
                printf("** %d %d **\n", a, b);
                if (a == b) {
                    printf("bingo\n");
                    answer ++;
                }
            }
        }
    }

    printf("%d", answer);
    return 0;
}
