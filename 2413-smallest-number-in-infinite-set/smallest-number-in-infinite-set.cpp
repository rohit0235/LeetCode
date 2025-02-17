class SmallestInfiniteSet {
public:
    //    priority_queue<int,vector<int>,greater<int>>pq;
       set<int>s;
    SmallestInfiniteSet() {
          
          for (int i=1;i<=1001;i++){
                s.insert(i);
          }
    }
    
    int popSmallest() {
            int top=*s.begin();  
               s.erase(s.begin());
            if (!s.empty()) return top;
       
            return -1;
    }
    
    void addBack(int num) {
          s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */