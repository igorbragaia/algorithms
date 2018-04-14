class Solution {
public:
    int search(Listy& array, int target) {
      if(array.elementAt(0) == -1)
        return -1;
      int m, i = 0, f, middle;
      while(array.elementAt(f) != -1)
        f *= 2;
      while(i <= f){
        m = (i + f) / 2;
        middle = array.elementAt(m);
        if(middle == -1 || middle > x)
          f = m - 1;
        else
          f = m + 1;
      }
      return -1;
    }
};
