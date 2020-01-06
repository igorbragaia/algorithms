class Solution {
  public:
    int leastInterval(vector < char > & tasks, int n) {
      vector < int > nums('Z' - 'A' + 1, 0);
      for (int task: tasks)
        nums[task - 'A']++;

      sort(nums.begin(), nums.end());

      int last = 'Z' - 'A';
      int max_task = nums[last] - 1, idle = n * max_task;
      for (int i = last - 1; i >= 0 && nums[i] > 0; i--)
        idle -= min(nums[i], max_task);
      return idle > 0 ? tasks.size() + idle : tasks.size();
    }
};