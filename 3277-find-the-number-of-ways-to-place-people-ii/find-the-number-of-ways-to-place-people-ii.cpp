class Solution {
public:
    int numberOfPairs(vector<vector<int>>& arr) {
            
            int n = arr.size();
             
            sort(arr.begin(),arr.end(), [](vector<int>&a , vector<int>&b){
                    
                      if (a[0]==b[0]) return a[1]>b[1];
                      return a[0]<b[0];
                   
            });
             
             int count =0;
            for(int i=0;i<n;i++){
                      int y = arr[i][1];
                      int maxy = INT_MIN;
                      for(int j=i+1;j<n;j++){
                                
                               if (y<arr[j][1]) continue;
                               if (arr[j][1]>maxy){
                                    count++;
                                    maxy =  arr[j][1];
                               }
                           
                      }

            }
            return count;

    }
};