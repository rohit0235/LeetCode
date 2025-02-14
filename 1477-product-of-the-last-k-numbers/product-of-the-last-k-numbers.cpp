class ProductOfNumbers {
public:
    // 3 0     2     5 4
    // 3 1 2 10 40 
    vector<int>number{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num!=0)
            number.push_back(num*number.back());
        else{
              number={1};

        }
    }
    
    int getProduct(int k) {
          int n=number.size();
        return  (k>=number.size()) ? 0: number.back()/number[n-k-1]; 
        
        //   int n=number.size();
        //     int pro=1;
        //    int i=n-1;
        //    while (k--){
                
        //         pro*=number[i];
        //         i--;

        //    }

        //    return pro;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */