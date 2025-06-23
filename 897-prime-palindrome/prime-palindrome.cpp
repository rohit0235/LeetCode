class Solution {
public:

     bool isprime(int k){
               
               for(int i=2;i<=sqrt(k);i++){
                    if (k%i==0) return false;
               }

               return true;
                       


     }
     bool ispalindrome(int i){
               
               string num = to_string(i);

               int l =0;
               int r =num.size()-1;

               while (l<r){
                    
                       if (num[l]!=num[r]){
                            return false;
                       }

                       l++;
                       r--;
                   
               }

               return true;
           
     };

    int primePalindrome(int n) {
            if (n==1 || n==2) return 2;
             int no = n==1?2:n;
        while(1){
            if((no>1e3 and no<1e4) or
               (no>1e5 and no<1e6) or
               (no>1e7 and no<1e8)){
                no = pow(10,ceil(log10(no)));;
                continue;
               }
            if(isprime(no) and ispalindrome(no))
                return no;
            no++;
        }
        return -1;

    }
};