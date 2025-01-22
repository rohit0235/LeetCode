class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         
         vector<int>ans;

         stack<int>s;

         for (int i:asteroids){
             
             bool   destroyed=false;

               while (!s.empty() && i < 0 && s.top() > 0) {
                      if (abs(i) > abs(s.top())) {
                    s.pop();  // Top asteroid is destroyed
                } else if (abs(i) == abs(s.top())) {
                    s.pop();  // Both asteroids are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // Current asteroid is destroyed
                    break;
                }
               }
               if (!destroyed) s.push(i);

         }

         while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
     }
};