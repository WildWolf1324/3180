#quicksort
import random

def quicksort(nums):
	if len(nums) < 2:
		return nums
	else:
		pivot = nums[random.randrange(0, len(nums))]
		left = [nums[i] for i in range(0, len(nums)) if nums[i] < pivot]
		right = [nums[i] for i in range(0, len(nums)) if nums[i] > pivot]
		return quicksort(left) + [pivot] + quicksort(right)

nums = [5, 4, 8, 0, 6, 11, 1]
print(quicksort(nums))
