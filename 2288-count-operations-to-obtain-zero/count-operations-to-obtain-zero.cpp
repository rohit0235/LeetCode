class Solution {
public:
    int countOperations(int num1, int num2) {
             int a = max(num1, num2);
             int b = min(num1, num2);
             if (a==0 || b==0) return 0;
             if (a==b) return 1;
             int count =0;
             while (a!=b){
                   count++;
                   int c= a-b;
               
              
             
                   a=max(c,b);
               
                   b=min(c,b);
                //    cout<<a<<" "<<b;
                        //    if (a==b) return count+1;
             }
             return count+1;
    }
};