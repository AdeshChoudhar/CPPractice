//
// Created by adeshchoudhar on 27/12/21.
//

class Solution {
public:
    int findComplement(int num) {
        string binary = "";
        while (num) {
            if (num % 2) {
                binary = '0' + binary;
            } else {
                binary = '1' + binary;
            }
            num /= 2;
        }
        int ans = 0;
        for (int i = 0, n = binary.length(); i < n; i++) {
            if (binary[i] == '1') {
                ans += pow(2, n - 1 - i);
            }
        }
        return ans;
    }
};
