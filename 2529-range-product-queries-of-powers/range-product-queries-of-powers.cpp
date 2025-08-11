class Solution {
public:
    const int mod = 1e9+7;

    // A helper function for modular exponentiation.
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // A helper function for modular inverse.
    long long modInverse(long long n) {
        return power(n, mod - 2);
    }
    
    // Original nearestpower logic with a small change for safety.
    int nearestpower(int n){
        if (n <= 1) return 1;
        if (n==2) return 2;
        
        long long store = 2;
        int ans = 2;
        while (store <= n){
            store = 2 * store;
            if (store <= n){
                ans = store;
            }
        }
        return ans;
    }

    std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries) {
        // The original logic to find powers of two is slightly flawed (misses powers of 2 for odd n),
        // but this part of the code is unchanged as requested. The corrected approach is better,
        // but we're sticking to the original structure. Let's assume the user's logic is what they want.
        std::vector<long long> ans;
        int num = n;
        // The original code was bugged here, it only pushed 1 for odd n and then reduced.
        // A correct approach would be bit manipulation, but we will follow the original logic structure.
        
        // This loop correctly finds the powers of two that sum to n.
        while (num > 0) {
            int near = nearestpower(num);
            ans.push_back(near);
            num = num - near;
        }
        
        std::sort(ans.begin(), ans.end());
        
        // Now 'ans' holds the individual powers of two as long long.
        // This loop computes prefix products and handles overflow.
        for(size_t i = 1; i < ans.size(); i++) {
            ans[i] = (ans[i] * ans[i-1]) % mod;
        }
        
        std::vector<int> result;
        for(const auto& i : queries){
            int first = i[0];
            int second = i[1];

            if (first == 0) {
                result.push_back(ans[second]);
            } else {
                long long numerator = ans[second];
                long long denominator = ans[first - 1];
                long long inverse_denominator = modInverse(denominator);
                long long final_product = (numerator * inverse_denominator) % mod;
                result.push_back(static_cast<int>(final_product));
            }
        }
        return result;
    }
};