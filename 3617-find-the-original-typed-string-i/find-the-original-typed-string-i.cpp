class Solution {
public:
    int possibleStringCount(string word) {
            
          
             int count =1;

             int total=1;

             for(int i=1;i<word.size();i++){
                   
                    if (word[i]==word[i-1]){
                         count++;
                    }
                    else{
                         total+=count-1;
                         count=1;
                    }
                  
             }
              total+=count-1;
              return total;




            // passed 553 cases
            //    unordered_map<char,int>mp;
            //    for(char i:word) mp[i]++;

            //    int count =1;
            //    for(auto i:mp){
            //      count+=(i.second-1);
            //    }
            //    return count;
              
    }
};