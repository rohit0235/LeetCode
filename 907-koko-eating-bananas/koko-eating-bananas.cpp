class Solution {
public:
            bool ispossible(int  midh,vector<int>& piles,int h){
                 int maxho=0;
                //  if (midh==0) return false;
                 for(int i=0;i<piles.size();i++){
                       
                       maxho+=(piles[i]+midh-1)/midh;

                       if (maxho>h){
                           return false;
                       }
                 }
                 return maxho<=h;
                   
            }
    int minEatingSpeed(vector<int>& piles, int h) {
               int maxhours=*max_element(piles.begin(),piles.end());
               int l=1;
               int r=maxhours;
               int ans=-1;
               while (l<=r){
                   
                      int mid=l+(r-l)/2;

                       if (ispossible(mid,piles,h)){
                            ans=mid;
                            r=mid-1;
                       }
                       else{
                              l=mid+1;
                       }
               }
               return ans;

    }
};