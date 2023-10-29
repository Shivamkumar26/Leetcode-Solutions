class Solution {
    int binaryToDecimal(string binary) {
    int decimal = 0;
    int binaryLength = binary.length();

    for (int i = 0; i < binaryLength; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, binaryLength - 1 - i);
        }
    }

    return decimal;
}

// Function to convert a decimal integer to a binary string
string decimalToBinary(int decimal, int len) {
    string binary = "";

    if (decimal == 0) {
        binary = "0";
    } else {
        while (decimal > 0) {
            binary = to_string(decimal % 2) + binary;
            decimal /= 2;
        }
    }

    while (binary.length() < len) {
        binary = "0" + binary;
    }
    return binary;
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), c=0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(binaryToDecimal(nums[i]) != c)
            return decimalToBinary(c, nums[0].length());
            c++;
        }
        return decimalToBinary(c, nums[0].length());
    }
};

// 10

// 7 3 1  O(logn)