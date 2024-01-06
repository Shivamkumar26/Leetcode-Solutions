class Solution {
public:
    int minMoves(int n, int maxDoubles) {
        int oper = 0;
        while(n!=1) {
            if(maxDoubles == 0) {
                oper += (n-1); 
                break; 
            }
            if(n % 2) n--;
            else n/=2, maxDoubles--;
            oper++;
        }
        return oper;
    }
};
/*

19 - 1
18 / 2
9 - 1
8 / 2
4 
(n==1)


*/