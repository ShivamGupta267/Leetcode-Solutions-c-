#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the maximum area
int maxArea(vector<int>& height) {
        int maxWater = 0;
        int leftPointer = 0 , rightPointer = height.size()-1;

        while(leftPointer < rightPointer){
            int widthTo = rightPointer - leftPointer ;
            int heightTo = min(height[leftPointer], height[rightPointer]);
            int currWater = widthTo * heightTo;
            maxWater = max(maxWater, currWater);
            
            height[leftPointer] < height[rightPointer] ? leftPointer++ : rightPointer--;
        }
        return maxWater;
    }

int main() {
    
    vector<int> height = {5, 6, 3, 2, 5, 7, 6, 5, 6};

    int result = maxArea(height);

    cout << "Maximum area: " << result << endl;

    return 0; 
}