class Solution {
public:
    int minimumLength(string s) {
        int n =s.size();

        unordered_map<char,int>mp;
        for (char i:s) mp[i]++;

        int left=0;
        for (auto i:mp){
            
            int number=i.second;
            while (number>=3){
                  number-=2;
            }
             
             left+=number;
        }
        return left;
    }
};