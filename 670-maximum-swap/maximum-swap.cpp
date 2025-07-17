class Solution {
public:
    int maximumSwap(int num) {
           
            string num1 =to_string(num);
            string num2 =to_string(num);
            sort(num1.rbegin(),num1.rend());
             
            int misindex=-1;
            for(int i=0;i<num1.size();i++){
                  
                      if (num1[i]!=num2[i]){
                         misindex=i;
                         break;
                      }
                  
            }

            if (misindex==-1) return num;
  int maxDigit = -1;
            int maxIndexToSwap = -1;

            for (int i = num2.size() - 1; i > misindex; i--) {
                if (num2[i] > maxDigit) { // Found a new largest digit
                    maxDigit = num2[i];
                    maxIndexToSwap = i;
                } else if (num2[i] == maxDigit) { // Found a duplicate of the largest digit, prefer rightmost
                    maxIndexToSwap = i;
                }
            }
            
            // Now, we need to check if this maxDigit is actually greater than num2[misindex]
            // and if swapping improves the number.
            // If the maxDigit found is not greater than num2[misindex], no swap is needed.
            // This is crucial, as we only want to swap if it leads to a larger number.
            if (maxDigit <= num2[misindex]) {
                return num; // No beneficial swap found
            }

            // Now, find the actual index of the digit to swap with num2[misindex].
            // We need to find the *rightmost* occurrence of the digit that *should* be at num2[misindex]
            // (which is num1[misindex]).
            // Or, more simply, find the rightmost occurrence of the `maxDigit` found above.
            
            // A more direct approach to finding the `maxIndexToSwap`
            // is to iterate from the right and find the largest digit
            // that is greater than `num2[misindex]`.
            // If multiple digits are equally large, pick the rightmost.

            int swapWithIndex = -1;
            for (int i = num2.size() - 1; i > misindex; i--) {
                if (num2[i] == num1[misindex]) { // Find the rightmost occurrence of the desired digit
                    swapWithIndex = i;
                    break;
                }
            }
            
            // If no suitable digit found to swap (e.g., all digits to the right are smaller or equal),
            // it means no swap will result in a larger number.
            if (swapWithIndex == -1) {
                return num;
            }

            // Perform the swap
            swap(num2[misindex], num2[swapWithIndex]);
                 
            return stoi(num2);
    
           
    }
};