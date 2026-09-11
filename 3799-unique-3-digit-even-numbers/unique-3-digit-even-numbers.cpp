class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

        // Count how many copies of each digit we have
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Try every 3-digit number
        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int a = x / 100;          // hundreds
            int b = (x / 10) % 10;    // tens
            int c = x % 10;           // units

            // Check if we have enough copies
            freq[a]--;
            freq[b]--;
            freq[c]--;

            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0) {
                ans++;
            }

            // Restore frequencies
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return ans;
    }
};