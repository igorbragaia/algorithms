class Solution {
public:
    int getSum(int a, int b)
    {
        return sum(a, b, 0, 0, 0);
    }

private:
    int sum(int a, int b, int result, int i, int add)
    {
        bool a_bool = (bool) (a & (1 << i)), b_bool = (bool) (b & (1 << i));
        if (i == 32)
            return result;
        if (a_bool && b_bool && add) {
            result |= 1 << i;
            return sum(a, b, result, i + 1, 1);
        }
        else if (a_bool ^ b_bool ^ add) {
            result |= 1 << i;
            return sum(a, b, result, i + 1, 0);
        }
        else if (!a_bool && !b_bool && !add) {
            return sum(a, b, result, i + 1, 0);
        }
        else {
            return sum(a, b, result, i + 1, 1);
        }
    }
};
