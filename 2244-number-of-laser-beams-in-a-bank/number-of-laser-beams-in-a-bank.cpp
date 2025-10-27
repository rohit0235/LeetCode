class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
              int n = bank.size();

              int ans =0;
              int mintwo = 0;
               int prev= -1;
              for(string i:bank){
                       int count =0;
                     for(auto c:i){
                         if (c!='0'){
                             count++;
                             
                         }
                     }
                     if (count>0){  
                        if (prev==-1){
                             prev= count;
                        }
                        else{
                                //    cout<<prev<<" "<<count<<endl;
                                 ans+=(prev*count);
                                   prev= count;
                          }
                         mintwo++;
                  
                       
                     }
                    
              }
              if (mintwo>1){
                 return ans;
              }
              return 0;
    }
};