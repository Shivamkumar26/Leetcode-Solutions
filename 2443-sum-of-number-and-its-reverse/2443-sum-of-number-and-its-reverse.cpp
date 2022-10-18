class Solution
{
    public:
        bool sumOfNumberAndReverse(int num)
        {
            for (int i = 0; i <= num; i++)
            {
                int n = i;
                int rev = 0;
                while (n)
                {
                    rev = rev *10 + n % 10;
                    n /= 10;
                }
                if (rev + i == num) return 1;
            }
            return 0;
        }
};