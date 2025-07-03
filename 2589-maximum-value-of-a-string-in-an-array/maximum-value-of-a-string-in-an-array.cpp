class Solution {
public:
    int maximumValue(vector<string>& strs) {
                 

                 int count =0;
             for(auto i:strs){
                 
                         unordered_map<char,int>mp;
                   bool flag =false;
                         for(auto j:i){
                              
                                 if (j>='a' && j<='z') {
                                     flag =true;
                                   break;
                                 }
                              
                         }
                            int z=  i.size();
                        
                         if (flag ) count =max(count,z);

                         else count =max(count,stoi(i));

                    
             }

             return count;


    }
};