class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
            
             int ans = numBottles;
             int fullbottles =0;

             while (numBottles>=numExchange){
                     numBottles = numBottles-numExchange;
                     numExchange++;
                     fullbottles++;
                     ans++;
                     if (numBottles<numExchange){
                          numBottles+=fullbottles;
                          fullbottles=0;
                     }
             }

             return ans;
    } 
};