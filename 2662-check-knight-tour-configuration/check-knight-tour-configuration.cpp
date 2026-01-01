class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        
            int n =  grid.size();
            int m =  grid[0].size();
  int c=0;
  if (grid[0][0]!=0) return false;
            for(int i=0;i<n;i++){
               
                 for(int j=0;j<m;j++){
                 bool flag= false;
                        int val= grid[i][j]+1;
    
                      if (i+2<n && j+1<m &&  (val==grid[i+2][j+1])){
                         cout<<"2";
                            // if(val==8){
                            //      cout<<"KYo true"<<endl;
                            // }
                                 flag= true;
                        
                      }
                  else   if (i+2<n && j-1>=0 &&  (val==grid[i+2][j-1])){
                        cout<<"1";
                        //    if(val==8){
                        //          cout<<"KYo true"<<endl;
                        //     }
                                 flag= true;
                            
                      }
              else    if (i-2>=0 && j-1>=0 &&  (val==grid[i-2][j-1])){
                 cout<<"1";
                            if(val==8){
                                 cout<<"KYo true"<<endl;
                            }
                                 flag= true;
                            
                      }
                else   if (i-2>=0 && j+1<m && (val==grid[i-2][j+1]) ){
                            if(val==8){
                                 cout<<"KYo true"<<endl;
                            }
                                 flag= true;
                        
                      }
                 else   if (j+2<m && i+1<n && (val==grid[i+1][j+2])){
                            if(val==8){
                                 cout<<"KYo true"<<endl;
                            }
                                  flag= true;
                        
                      }
                 else    if (j+2<m && i-1>=0 && (val==grid[i-1][j+2])){
                
                            if(val==8){
                                 cout<<"KYo true"<<endl;
                            }
                                 flag= true;
                            
                      }
                  else   if (j-2>=0 && i+1<n && (val==grid[i+1][j-2])){
                                if(val==8){
                                 cout<<"KYo true"<<endl;
                            }
                                 flag= true;
                            
                      }
                  else   if (j-2>=0 && i-1>=0 && (val==grid[i-1][j-2])){
                        if(val==8){
                                 cout<<"KYo true"<<endl;
                            }
                                 flag= true;
                            
                      }
         
                      if (!flag ) {
                        // cout<<i<<" "<<j<<endl;
                        // cout<<val;
                         if(c>=1)   return false;
                          c++;
                      }
                 }
            }


            return true;
    }
};