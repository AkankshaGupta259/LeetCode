class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long power = 1000;  // First number that needs a comma
        long long commas = 1;

        while (power <= n) {
            long long next = power * 1000;

            // Numbers in [power, min(n, next - 1)] have `commas` commas
            long long count = min(n, next - 1) - power + 1;
            ans += count * commas;

            power = next;
            commas++;
        }

        return ans;
    }
};