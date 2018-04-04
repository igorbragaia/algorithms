#include <bits/stdc++.h>
using namespace std;


class Sort {
public:
    Sort(vector<int> input): arr(input){}
    virtual void sort(){};
    void printArray(){
        for (int el : arr) {
            cout << el << " ";
        }
        cout << endl;
    }
    vector<int> getArray(){
        return arr;
    }
protected:
    vector<int> arr;
};


class BubbleSort : public Sort {
public:
    BubbleSort(vector<int> input): Sort(input){
        cout << "BubbleSort constructor called!" << endl;
    }
    ~BubbleSort() {
      cout << "BubbleSort destructor called!" << endl;
    }
    void sort(){
        int tmp;
        bool loop = true;
        for (int i = 0; i < arr.size() and loop; i++) {
            loop = false;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] > arr[j]) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    loop = true;
                }
            }
        }
    }
};


class MergeSort : public Sort {
public:
    MergeSort(vector<int> input): Sort(input){
        cout << "MergeSort constructor called!" << endl;
        for (int i = 0; i < input.size(); i++)
            aux.push_back(0);
    }
    ~MergeSort() {
      cout << "MergeSort destructor called!" << endl;
    }
    void iterative_sort(){
      int middle, end, n = (int) arr.size();
      for(int chunk_size = 1; chunk_size < n; chunk_size *= 2){
        // in case of
        // for(int i = 0; i < n; i += 2 * chunk_size){
        // when i == n - 1, in merge, second_begin = middle + 1 = end + 1, so there will be a memory error
        for(int i = 0; i < n - 1; i += 2 * chunk_size){
          middle = i + chunk_size - 1;
          end = min(i + 2 * chunk_size - 1, n - 1);
          merge(i, end, middle);
        }
      }
    }
    void recursive_sort(){
        mergesort(0, arr.size() - 1);
    }
private:
    vector<int> aux;

    void mergesort(int i, int j){
        if (i != j) {
            int middle = (i + j) / 2;
            mergesort(i, middle);
            mergesort(middle + 1, j);
            merge(i, j, middle);
        }
    }

    void merge(int begin, int end, int middle){
        int pos = begin, second_begin = middle + 1;
        for (int k = begin; k <= end; k++)
            aux[k] = arr[k];
        while (begin <= middle and second_begin <= end) {
            if (aux[begin] < aux[second_begin])
                arr[pos++] = aux[begin++];
            else
                arr[pos++] = aux[second_begin++];
        }

        while (begin <= middle)
            arr[pos++] = aux[begin++];
    }
};


class QuickSort : public Sort {
public:
    QuickSort(vector<int> input): Sort(input){
        cout << "QuickSort constructor called!" << endl;
    }
    ~QuickSort() {
      cout << "QuickSort destructor called!" << endl;
    }
    void sort(){
      quicksort(0, arr.size() - 1);
    }
private:
    void quicksort(int i, int j){
      int index = partition(i, j);
      if(i < index - 1)
        quicksort(i, index - 1);
      if(j > index)
        quicksort(index, j);
    }

    int partition(int i, int j){
      int left = i, right = j, aux;
      int pivot = arr[(i + j)/2];
      while(left < right){
        while(arr[left] < pivot)
          left++;
        while(arr[right] > pivot)
          right--;

        if(left <= right){
          aux = arr[left];
          arr[left] = arr[right];
          arr[right] = aux;
          left++;
          right--;
        }
      }
      return left;
    }
};


// this radix not work for two complement binary representation
class RadixSort : public Sort {
public:
    RadixSort(vector<int> input): Sort(input){
        cout << "RadixSort constructor called!" << endl;
    }
    ~RadixSort() {
      cout << "RadixSort destructor called!" << endl;
    }
    void sort(){
      for(int i = 0; i < 32; i++){
        queue<int> queues[2];
        for(unsigned j = 0; j < arr.size(); j++)
          queues[(bool) (arr[j] & (1 << i))].push(arr[j]);
        arr.clear();
        for(int k = 0; k <= 1; k++){
          while(!queues[k].empty()){
            arr.push_back(queues[k].front());
            queues[k].pop();
          }
        }
      }
    }
private:

};



int main()
{
    vector<int> array = { 15, 4, 2, 1, 50, 0, 3, 100, 3 };

    // vector<int> array = { 3, 1, 2};

    BubbleSort bubblesort(array);
    bubblesort.printArray();
    bubblesort.sort();
    bubblesort.printArray();

    MergeSort mergesort2(array);
    mergesort2.printArray();
    mergesort2.recursive_sort();
    mergesort2.printArray();

    MergeSort mergesort(array);
    mergesort.printArray();
    mergesort.iterative_sort();
    mergesort.printArray();

    QuickSort quicksort(array);
    quicksort.printArray();
    quicksort.sort();
    quicksort.printArray();

    RadixSort radixsort(array);
    radixsort.printArray();
    radixsort.sort();
    radixsort.printArray();

    return 0;
}
