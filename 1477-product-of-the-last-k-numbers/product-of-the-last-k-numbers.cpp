class ProductOfNumbers {
public:
    vector<int>number;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        number.push_back(num);
    }
    
    int getProduct(int k) {
          
          int n=number.size();
            int pro=1;
           int i=n-1;
           while (k--){
                
                pro*=number[i];
                i--;

           }

           return pro;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */