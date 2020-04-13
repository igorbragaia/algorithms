class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = vector<int>(size, 0);
        qty = 0;
        i=0;
        windowSum = 0;
    }
    
    double next(int val) {
        windowSum -= window[i];
        window[i] = val;
        windowSum += window[i];
        
        i = (i+1) % (int)window.size();
        
        qty = min(qty+1, (double)window.size());

        return (double)windowSum / qty;
    }
private:
    vector<int> window;
    int windowSum, i;
    double qty;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */