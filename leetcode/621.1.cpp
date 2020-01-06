class Solution {
  public:
    int leastInterval(vector < char > & tasks, int n) {
      map < int, int > mapa;
      for (int task: tasks) {
        if (mapa.find(task) == mapa.end())
          mapa[task] = 0;
        mapa[task]++;
      }

      vector < int > nums;
      for (auto it = mapa.begin(); it != mapa.end(); it++)
        nums.push_back(it - > second);

      int last = nums.size() - 1;
      sort(nums.begin(), nums.end());
      int time = 0;
      while (nums[last] > 0) {
        for (int i = 0; i <= n && nums[last] > 0; i++) {
          if (last - i >= 0 && nums[last - i] > 0)
            nums[last - i]--;
          time++;
        }
        sort(nums.begin(), nums.end());
      }

      return time;

    }
};