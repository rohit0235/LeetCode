class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          
          unordered_map<char,int>mp;
     
          int start=0;

          int maxi=1;
           int n=s.size();
           int end;
           if (s.empty()) return 0;
           for(end=0;end<n;end++){
                    if (mp.find(s[end])!=mp.end()){
                           if (mp[s[end]]>=start){
                            maxi=max(maxi,end-start);
                  
                           start=mp[s[end]]+1;
                           }
                  
                    }

                    mp[s[end]]=end;
                     

           }
             return max(maxi,end-start);

        //   int n =s.size();
        //   int left=0;
        //   int right=0;
        //   if (s.size()<=1){
        //         return s.size();
        //   } 
        //         unordered_map<char ,int>mp;
        //         int res=0;
        //   for (right=0;right<n;right++){

        //         if (mp.find(s[right])!=mp.end()){
        //             int index=mp[s[right]];
        //             if (index>=left){
        //                 res=max(res,right-left); 
        //                  left=index+1;
        //             }
                  
        //         }

        //         mp[s[right]]=right;
        //   }
        //   return max(res,right-left);
    }
};