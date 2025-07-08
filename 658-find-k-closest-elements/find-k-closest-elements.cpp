class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         
             // a-x =b-x
             // a=b
              int n =arr.size();
             int pivot =-1;
             int mindiff = INT_MAX;
             for(int i=0;i<n;i++){
                   if (abs(arr[i]-x)<mindiff){ 
                         pivot =i;
                         mindiff =abs(arr[i]-x);
                   }
                
             }

            
             int l = pivot;
             int j =pivot+1;
                 vector<int>ans;
             while (l>=0 && j<n){ 

                        if (ans.size()>=k) break;
                     int a =arr[l];
                     int b =arr[j];
                    if (abs(a-x)<abs(b-x)  || (abs(a-x)==abs(b-x) && a<b)){
                            ans.push_back(a);
                           l--;
                    }
                    else{
                           ans.push_back(b);
                           j++;
                    }
                    
                       
             }
             while ( ans.size()<k && l>=0 ){ 
                     int a =arr[l];     
                            ans.push_back(a);
                           l--;      
             }
            
             while (ans.size()<k &&  j<n ){ 
                     int b =arr[j];     
                            ans.push_back(b);
                        j++;    
             }
                   sort(ans.begin(),ans.end());
             return ans;
            

    }
};