class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c=0, flip=0;
        for(auto i:s) {
            if(i=='1') c++;
            else flip++;
            flip = min(flip, c);
        }
        return flip;
    }
};

/** 

#1 failed at "0101100011"
count one - 2

cz, co

if(co == count one) return min(z,o); 
--------------------------------------

#2  
    "00111"
    
    "00110"
     00122
    
    
    "010110"
     011233
    
    min(len from 1st '1' - longest incr subarray (lsis), lsis)
    
    "00011000"
     00012222
    
    "0101100011"
     0112333345

**/