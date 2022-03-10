# Radix sort

def extractDigit(num, pos):
	for i in range(0, pos):
		num = num / 10
	return num % 10

def countingSort(numList, pos):
	countList = [[], [], [], [], [], [], [], [], [], []]
	for num in numList:
		digit = extractDigit(num, pos)
		countList[digit].append(num)
	i = 0
	for nList in countList:
		for num in nList:
			numList[i] = num
			i += 1

def radixSort(nums):
	maxNum = max(nums)
	for pos in range(0, len(str(maxNum))):
		countingSort(nums, pos)
		print(nums)


nums = [170, 45, 75, 90, 2, 802, 2, 66]
radixSort(nums)
	
	
