//
// Created by adeshchoudhar on 04/01/22.
//

class Solution {
public:
    int bitwiseComplement(int n) {
        string binary = (n == 0) ? "1" : "";
        while (n) {
            binary = (n % 2 ? "0" : "1") + binary;
            n /= 2;
        }
        int ans = 0;
        for (int i = binary.length() - 1; i >= 0; i--) {
            ans += (binary[i] == '1') ? pow(2, binary.length() - 1 - i) : 0;
        }
        return ans;
    }
};
