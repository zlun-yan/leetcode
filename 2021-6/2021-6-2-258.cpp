//
// Created by ZlunYan on 2021/6/2.
//

#include <iostream>
using namespace std;

// 对于一个数 asdf 我们这个函数要求的是 a + s + d + f
// 而这个数 asdf 实际上是这样求出来的 a * 1000+  s * 100 + d * 10+  f
// 那么对上面那个算式就可以分为: a * 999 + s * 99 + d * 9 + (a + s + d + f)
// 可以发现 a * 999 和 s * 99 和 d * 9 都是 9 的倍数, 也就是说 模9为0
// 最终模9求出来的就是 (a + s + d + f) % 9

// 能够被9整除的整数，各位上的数字加起来也必然能被9整除，所以，连续累加起来，最终必然就是9。
// 不能被9整除的整数，各位上的数字加起来，结果对9取模，和初始数对9取摸，是一样的，所以，连续累加起来，最终必然就是初始数对9取摸。
int addDigits(int num) {
    return (num - 1) % 9 + 1;
}

int main () {
    cout << addDigits(38) << endl;
    return 0;
}