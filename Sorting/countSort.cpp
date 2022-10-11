#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr)
{
    //getting maximum element in array
    int max = *max_element(arr.begin(), arr.end());
    //getting minimum element in array
    int min = *min_element(arr.begin(), arr.end());
  
    //calculating the length of the count array needed
    int range = max - min + 1;
    
   //array for storing frequency of particular number 
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
  
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
  
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
  
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
  
void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}
  

int32_t main()
{
    vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
    countSort(arr);
    printArray(arr);
}
