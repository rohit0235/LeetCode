class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
           
           vector<int>ans;
             int n=spells.size();
           sort(potions.begin(),potions.end());
           for(int i=0;i<n;i++){
                 long long int  l=0;
                 long long int  r=potions.size()-1;
                 int  index=-1;
                 while (l<=r){
                  
                    long long int  mid=l+(r-l)/2;
                    //   cout<<potions[mid]*spells[i];
                      long long  int  prod= 1LL * potions[mid]*spells[i];
                      if (prod>=success){
                            index=mid;
                            r=mid-1;
                      }
                      else{
                           l=mid+1;
                      }
                 }    
                //  cout<<index<<" ";
                if (index==-1) ans.push_back(0);   
                else ans.push_back(potions.size()-index);   
                     
           }

           return ans;
          
           
    }
};