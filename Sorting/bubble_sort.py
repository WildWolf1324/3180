# Bubble sort
# Time - O(n^2)
# Additional space - O(1)

def bubbleSort(nums): 
	swapped = True
	while swapped:
		swapped = False
		for i in range(0, len(nums)-1):
			if nums[i] > nums[i+1]: 
				swapped = True
				nums[i], nums[i+1] = nums[i+1], nums[i] # Swap
		
nums = [5, 4, 8, 0, 6, 11, 1]
bubbleSort(nums)
print(nums)
