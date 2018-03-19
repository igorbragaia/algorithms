class Solution {
public:
  int findComplement(int num) {
      int mask = (1<<(int)(log2(num)+1)) - 1;
      return (~num)&mask;
  }
};
