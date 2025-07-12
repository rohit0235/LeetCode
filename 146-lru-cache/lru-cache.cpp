class LRUCache {
public:
     int n =0;
     list<int>dll;
     map<int,pair<list<int>::iterator,int>>mp;

    LRUCache(int capacity) {
        n =  capacity;
    }
    

    void  Markrecentlyused(int key){
           
             int val = key;
             dll.erase(mp[key].first);
             dll.push_front(key);

             mp[key].first = dll.begin();


            
    }
    int get(int key) {
        
        if (!mp.count(key)) return -1;
 
         Markrecentlyused(key);
        return mp[key].second;


    }
    
    void put(int key, int value) {

               if (mp.find(key)!=mp.end()){
                     
                      mp[key].second = value;
                      Markrecentlyused(key);
                    
               }     
               else{
                      
                      dll.push_front(key);
                      mp[key]= {dll.begin(),value};
                     Markrecentlyused(key);
                     n--;
               }  


               if (n<0){
                 
                     int dl =dll.back();
                     dll.pop_back();
                          mp.erase(dl);
                          n++;  
               } 
            
  
              
    }


    


    // queue and will try to add element in this actually 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */