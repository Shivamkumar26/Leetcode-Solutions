class Solution {
    int s=0, c=1;
public:
    int twoEggDrop(int n) {
        if(n<=0) return 0;
        s=c;
        c++;
        return 1+twoEggDrop(n-s);
    }
};
/**

100

- 9 
- 22

**/