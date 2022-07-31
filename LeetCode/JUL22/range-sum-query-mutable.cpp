//
// Created by adeshchoudhar on 31/7/22.
//

class BIT {
public:
    vector<int> bit;

    BIT(int size = 0) {
        bit.assign(size + 1, 0);
    };

    int getSum(int idx) {
        int sum = 0;
        for (int i = idx; i > 0; i -= (i & (-1 * i))) {
            sum += bit[i];
        }
        return sum;
    }

    void addValue(int idx, int val) {
        for (int i = idx, n = bit.size(); i < n; i++) {
            bit[i] += val;
        }
    }
};

class NumArray {
public:
    BIT bit;
    vector<int> nums;

    NumArray(vector<int> &nums) {
        int n = nums.size();
        this->nums = nums;
        this->bit = BIT(nums.size());
        for (int i = 0; i < n; i++) {
            bit.addValue(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        this->bit.addValue(index + 1, diff);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return bit.getSum(right + 1) - bit.getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
