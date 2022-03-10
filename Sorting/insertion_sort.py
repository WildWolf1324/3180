# Insertion sort
# Time - O(n^2)
# Additional space - O(1)

def insertionSort(nums):
	for i in range(0, len(nums)): # C++:  for(int i = 0; i < nums.size(); i++)
		key = nums[i]
		j = i-1
		while j >= 0 and key < nums[j]: # Find insertion point
			nums[j+1] = nums[j] # Shifting
			j -= 1
		nums[j+1] = key # Insert
		
nums = [5, 4, 8, 0, 6, 11, 1]
insertionSort(nums)
print(nums)
