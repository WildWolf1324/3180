# Selection sort 
# Time - O(n^2)
# Additional space - O(1)

def selectionSort(nums):
	count = 0	
	while count < len(nums):
		minNum = min(nums[count:])
		minPos = nums.index(minNum)
		nums[count], nums[minPos] = nums[minPos], nums[count] # Swap
		count +=1 
		
nums = [5, 4, 8, 0, 6, 11, 1]
selectionSort(nums)
print(nums)
