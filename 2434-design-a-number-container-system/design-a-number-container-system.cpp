class NumberContainers {
public:
     unordered_map<int,int>mp;
     unordered_map<int,set<int>>mp2;
        NumberContainers() {
            
        }
        
    void change(int index, int number) {
        
        mp[index]=number;
        mp2[number].insert(index);
    }
    
    int find(int number) {
       
        if (mp2.find(number)!=mp2.end()){
                 int mini=INT_MAX;
               for (auto i:mp2[number]){
                    
                    if (mp[i]==number){
                        return i;
                    }
              }

               return -1;
             
                     
        } 
        else{
             return -1;
        }

        //   int find=INT_MAX;
    
        //   for (auto i:mp){
              
        //       if (i.second==number) {
        //             find=min(find,i.first);
        //       }
        //   }

        //   if (find==INT_MAX) return -1;
        //   else return find;

    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */