class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1e9 + 7;

        long aba = 6; // RGR, GRG, ...
        long abc = 6; // RGB, GBR, ...

        for (int i = 2; i <= n; i++) {
            long newAba = (aba * 3 + abc * 2) % mod;
            long newAbc = (aba * 2 + abc * 2) % mod;

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % mod;
    }
};
