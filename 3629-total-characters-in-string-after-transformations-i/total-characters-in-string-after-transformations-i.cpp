class Solution {
public: 

      const int M=1e9+7;
    int lengthAfterTransformations(string s, int t) {
           
            // unordered_map<char ,int>mp;
            vector<int>mp(26,0);

            for(auto  i:s){
                 mp[i-'a']++;
            }

            while (t--){
                    //   unordered_map<char ,int>temp;
                      vector<int>temp(26,0);                  
                      for(int i=0;i<26;i++){
                              char ch=i+'a';
                              int freq=mp[i];

                               if (ch !='z'){

                                     temp[ch-'a'+1]=(temp[ch-'a'+1]+freq)%M;  
                                      
                               }
                               else{
                                    
                                    temp[0]=(temp[0]+freq)%M;
                                    temp[1]=(temp[1]+freq)%M;
                               }

                      }

                    mp=temp;
 
                   
                   
            }

             int  ans=0;
            for(auto i:mp){
                 ans=(ans+i)%M;
            }
            return ans;




    }
};