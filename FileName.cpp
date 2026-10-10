#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main() {
    vector<int>nums = { 1,3,-1,-3,5,3,6,7 };
    int k;
    cout << "please input window's max" << endl;
    cin >> k;
    vector<int>cur(nums.size());
    vector<int>max;
    int head = 0;
    int tail = -1;
    for (int i = 0;i < nums.size();i++) {
        while (head <= tail && cur[head] <= i - k) {
            head++;
        }
        while (head <= tail && nums[i] >= nums[cur[tail]]) {
            tail--;
        }
        tail++;
        cur[tail] = i;
        if (i - k >= -1) {
            max.push_back(nums[cur[head]]);
        }
    }
    for (vector<int>::iterator it = max.begin();it != max.end();it++) {
        cout << *it << " ";
    }
}