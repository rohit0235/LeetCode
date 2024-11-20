 bool isHappy(int n) {
        
          set<int>seen;

          while (true){
                 int sum=0;
                 while (n!=0){
                      sum+=pow(n%10,2.0);
                       n=n/10;
                 }

                 if (sum==1) return true;

                 n=sum;
 
                 if (seen.find(sum)!=seen.end()){
                    return  false;
                 }
                 seen.insert(sum);

          }

    }
