class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());


        int count =0;

          int l=0;
          int r=0;
          while(l<players.size() && r<trainers.size()){
              
                if (players[l]<=trainers[r]){
                     l++;
                     r++;
                     count++;
                }
                else{
                     r++;
                }
              
          }
          return count;




        //  //  2 5 8 8
        // for(int i=0;i<trainers.size();i++){
              
        //          // 4 7 9 
        //          int  l= 0;
        //          int r = players.size()-1;
        //         int ans =-1;
        //         int num = trainers[i];
        //          while (l<=r){
                      
        //                  int mid =  (l+(r-l))/2;

        //                  if (players[mid]>num){
        //                        r= mid-1;
        //                  }
        //                  else{
        //                      ans = i;
        //                      r = mid-1;
        //                  }
                       
        //          }

        //          cout<<ans<<endl;
        //          if (ans!=-1 && players[ans]<=num){
        //               count++;
        //               players[ans]=INT_MAX;
        //          }
              
        // }

        // return count;










    //     multiset<int>st;
    //    int n = trainers.size();
    //     for(int i:trainers) st.insert(i);
    //      int count=0;
    //     for(auto i:players){
                
    //             int lowerbound = *lower_bound(st.begin(),st.end(),i);
    //              cout<<lowerbound<<endl;
    //             if (st.count(lowerbound) && lowerbound>=i){

    //                 if (lowerbound==i){
    //                       count++;
    //                       st.erase(lowerbound);
    //                 }
    //                 else{
    //                         count++;
    //                       st.erase(lowerbound);
    //                 }
                    
    //             }
                
    //     }

    //     return count;

    }
};