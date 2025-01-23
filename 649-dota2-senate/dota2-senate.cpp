class Solution {
public:
    string predictPartyVictory(string senate) {
        
         queue<int>r;
         queue<int>d;
    int n =senate.size();
         for (int i =0;i<senate.size();i++){
            if (senate[i]=='R')  r.push(i);
            else d.push(i);
         }

         while (r.size()>0 && d.size()>0){
               
               if (r.front()<=d.front()){
                     r.push(r.front()+n);
                     d.pop();
                     r.pop();
               }
               
              if (r.front()>=d.front()){
                     d.push(d.front()+n);
                       d.pop();
                     r.pop();

               }


              
         }

         return d.size()>r.size() ? "Dire" : "Radiant";


        
    }
};