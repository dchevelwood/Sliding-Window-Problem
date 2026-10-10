#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main() {
    \\测试案例
    vector<int>nums = { 1,3,-1,-3,5,3,6,7 };
    \\定义窗口大小
    int k;
    cout << "please input window's max" << endl;
    cin >> k;
    vector<int>cur(nums.size());
    vector<int>max;
    int head = 0;
    int tail = -1;
    for (int i = 0;i < nums.size();i++) {
        \\防止元素滑出窗口
        while (head <= tail && cur[head] <= i - k) {
            head++;
        }
        \\判断新元素和当前元素的大小
        while (head <= tail && nums[i] >= nums[cur[tail]]) {
            tail--;
        }
        tail++;
        cur[tail] = i;
        if (i - k >= -1) {
            max.push_back(nums[cur[head]]);
        }
    }
    \\输出每个窗口内最大值
    for (vector<int>::iterator it = max.begin();it != max.end();it++) {
        cout << *it << " ";
    }
}
