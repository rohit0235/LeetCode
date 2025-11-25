class Solution {
public:
    int smallestRepunitDivByK(int k) {
           
        //    if (k==1) return 1;
        //    if (k%2==0) return -1;
        //    if (k==11 ) return 2;
        //    if (k==3) return 3;
        //    if (k==9) return 9;
        //    if (k==7) return 6;
           
            // can we check cycle
            // i think so

            unordered_map<      long long int ,      long long int >mp;

            long long int local =1;
                  long long int  count =0;
            while (true){ 
                   count++;
                    long long int  rem = local%k;
                   if (rem==0) return count;
                   if (mp.count(rem)) return -1;
                   mp[rem]++;
                   local=rem*10+1;
            }

            return -1;

    }
};