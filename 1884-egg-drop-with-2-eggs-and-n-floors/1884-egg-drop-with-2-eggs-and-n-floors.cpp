class Solution {
    int s=1;
public:
    int twoEggDrop(int n) {
        return (n<=0) ? 0 : 1+twoEggDrop(n-s++);
    }
};
/**

100

- 9 
- 22

**/