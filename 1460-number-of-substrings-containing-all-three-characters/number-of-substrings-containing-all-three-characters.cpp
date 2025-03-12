class Solution {
public:
    int numberOfSubstrings(string s) {

            int n=s.size();
                // a b c a b c 
                // map - a b c  count= 6-2=4+0=4
                // map - b c a - 4+6-3=7
                //  c a b count - 7+6-4=9
                // abc - 9+6-5=10

                  // test case -2 
                  // map - a a a c b // 1
                  // a a c b while mp.size()==3 mp[arr[j]--] count
                  // a c b - 3

            
                  unordered_map<char,int>mp;
                  int j=0;
                  int count=0;
                  for(int i=0;i<n;i++){
                       mp[s[i]]++;

                       while(mp.size()==3){
                           count+=n-i;
                           mp[s[j]]--;
                           if(mp[s[j]]==0){
                             mp.erase(s[j]);
                           }
                           j++;
                       }

                  }
                 
                 return count;











        // int count = 0;
        // int left = 0;
        // unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};
        
        // for (int right = 0; right < s.length(); ++right) {
        //     char_count[s[right]]++;
            
        //     while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
        //         count += s.length() - right;
        //         char_count[s[left]]--;
        //         left++;
        //     }
        // }
        
        // return count;
    }
};