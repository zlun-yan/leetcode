//
// Created by ZlunYan on 2021/6/1.
//

// 这个题有意思奥
// 既然所有的数组元素的取值都在 1 ~ n 内
// 那么就可以当作链表来处理
// 有两个相同元素,意思就是有两个元素的指针(也就是数组元素的值啦)指向同一个地方
// 但是这其中 怎么样通过数组中的元素得到一个链表也是很神奇的
// 那么这样就会有环 找出环的最快的方法就是快慢指针了

#include <cstdio>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;
    // 通过这个到环中(确定有环)
    do {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (fast != slow);  // 这样只能说明到了环内了 而我们实际要找的是环的入口(只有这里才是在数组中出现了两次的元素)

    // 通过这个到环的里面
    slow = 0;
    while (fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
    }  // 通过这样 就可以确定环的入口 这个也太奇妙了吧

    return fast;
}

int main () {
    vector<int> input = {1,3,4,2,2};
    printf("%d\n", findDuplicate(input));
    return 0;
}