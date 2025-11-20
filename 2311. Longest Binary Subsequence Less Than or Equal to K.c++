














class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;          // count of characters in the result
        int power = 0;          // position of the bit from the right
        long long value = 0;    // current binary value being built

        // Traverse from right to left (least significant bit to most)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++; // always safe to add zero
            } else {
                // If power is more than 31, 2^power will overflow int
                if (power < 32) {
                    // Try to add '1' at this position
                    long long add = 1LL << power; // 2^power
                    if (value + add <= k) {
                        value += add;
                        count++;
                    }
                }
            }
            power++;
        }

        return count;
    }
};


