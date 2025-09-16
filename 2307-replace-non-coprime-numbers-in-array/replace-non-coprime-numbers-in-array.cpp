class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
             int n= nums.size();
             stack<int>st;
             
             for(int i:nums){
                      st.push(i);

                      while (st.size()>1){
                            
                            int top1 = st.top();
                            st.pop();
                            int top2 = st.top();
                            // cout<<top1<<" "<<top2<<endl;
                            if (gcd(top1,top2)>1){
                                   st.pop();
                                   st.push(lcm(top1,top2));
                                  
                            }
                            else{
                                 st.push(top1);
                                 break;
                            }
                      }
                      
             }

             vector<int>ans;
             while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
             }

             reverse(ans.begin(),ans.end());
             return ans;


    }
};