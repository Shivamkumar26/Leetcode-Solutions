class Solution {
    int countdigits(int n) {
        int c = 0;
        while(n) {
            c++;
            n/=10;
        }
        return c;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        int dlow = countdigits(low);
        int dhigh = countdigits(high);
        
        for(int i=dlow; i <= dhigh; i++) {
            for(int j = 0; j <= 9-dlow; j++) {
                int num = j, digits = 0;
                int start = 0;
                
                while(digits < i) {
                    int r = num % 10;
                    num = (start)*10 + r + 1; 
                    start = num;
                    digits++;
                }
                
                if(num >= low && num <= high) 
                    res.push_back(num);
                
                // handled last 9+1=10 condition
                if(num % 10 == 9 || num > high) break;
            }
        }
        
        return res;
    }
};
/*

low -> no. of digits 
high -> no. of digits

loop (0 to (high-low))
123 
234 


1

*/