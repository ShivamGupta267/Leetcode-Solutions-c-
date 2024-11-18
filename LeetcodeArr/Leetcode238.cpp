#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i = 1; i < n; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for(int i = n-2; i >= 0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }

int main() {
    
    vector<int> nums = {5, 6, 3, 2, 5, 7, 6, 5, 6};

    vector<int> result = productExceptSelf(nums);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    return 0; 
}