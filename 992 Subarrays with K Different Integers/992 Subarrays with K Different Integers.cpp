#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int subarraysWithKDistinct(vector<int>& nums, int k);
int atMostK(vector<int>& nums, int k);
int main()
{
	vector<int> nums = { 1, 2, 1, 2, 3 };
	int k = 2;
	int d = subarraysWithKDistinct(nums, k);
	cout << d;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {

	return atMostK(nums, k) - atMostK(nums, k - 1);
}
int atMostK(vector<int>& nums, int k)
{
	int n = nums.size();
	vector<int> freq(n + 1, 0);
	int left = 0;
	int right = 0;
	int count = 0;
	int ans = 0;
	while (right < n)
	{
		if (freq[nums[right]] == 0)
		{
			count++;
		}
		freq[nums[right]]++;
		right++;
		while (count > k)
		{
			freq[nums[left]]--;
			if (freq[nums[left]] == 0)
			{
				count--;
			}
			left++;
		}
		ans += right - left;
	}
	return ans;
}
