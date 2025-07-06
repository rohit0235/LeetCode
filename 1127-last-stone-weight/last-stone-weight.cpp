class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
                        
                         // 8 7 4 2 1 1
                         // 8 7 - 
                         priority_queue<int>pq;
                        for(int i:stones) pq.push(i);
                         while (!pq.empty() && pq.size()>1){
                               
                                    int first = pq.top();
                                    pq.pop();
                                    int second = pq.top();
                                    pq.pop();
                              
                                    if (first!=second){
                               
                                           pq.push(abs(first-second));
                                           
                                    }

                                    // cout<<pq.top();

                               
                         }


                         while (!pq.empty()){
                              return pq.top();

                         }
                        

                         return 0;

    }
};