class Solution {
public:
    int differenceOfSums(int n, int m) {
        
           int num1 = ((n)*(n+1))/2;

           if (n<m)  return num1;
           int numterm = n/m;
           int an=  numterm*m;
           int num2 = ((numterm)*(m+an))/2;
        //    cout<<num1<<" " <<num2;

           return num1-2*num2;

    }
};