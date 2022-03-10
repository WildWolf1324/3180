# Merge sort 
# Time - O(nlogn)
# Additional space - O(n)


def mergeSort(nums): 
  	# Base case - nothing to sort! 
    if len(nums)>1: 
        mid = len(nums)//2
        left = nums[:mid] 
        right = nums[mid:] 
        left = mergeSort(left) 
        right = mergeSort(right) 
  
        nums = []
  		# Merge
        while len(left)>0 and len(right)>0: 
            if left[0]<right[0]: 
                nums.append(left[0]) 
                left.pop(0) 
            else: 
                nums.append(right[0]) 
                right.pop(0) 
  
        for num in left: 
            nums.append(num) 
        for num in right: 
            nums.append(num) 
                  
    return nums

		
nums = [5, 4, 8, 0, 6, 11, 1]
nums = mergeSort(nums)
print(nums)
