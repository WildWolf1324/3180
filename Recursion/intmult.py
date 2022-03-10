# Integer multiplication - recursive algorithm

def numDigits(num):
	count = 0
	while (num > 0):
		count += 1
		num //= 10
	return count

# Assume num1 and num2 are positive
def intMult(num1, num2):
	#print(num1, num2)
	if num1 < 10 and num2 < 10:
		return num1 * num2

	nd1 = numDigits(num1)
	nd2 = numDigits(num2)
	n = max(nd1, nd2)
	n = n//2
	# Split number into 2 halves
	if nd1 > 1:
		a = num1 // pow(10, n)
		b = num1 % pow(10, n)
	else:
		a = 0
		b = num1

	if nd2 > 1:
		c = num2 // pow(10, n)
		d = num2 % pow(10, n)
	else:
		c = 0
		d = num2
	if a == 0 or c == 0:
		ac = 0
	elif a < 10 and b < 10:
		ac = a*c
	else:
		ac = intMult(a,c)

	if a == 0 or d == 0:
		ad = 0
	elif a < 10 and d < 10:
		ad = a*d
	else:
		ad = intMult(a,d)

	
	if b == 0 or c == 0:
		bc = 0
	elif b < 10 and c < 10:
		bc = b*c
	else:
		bc = intMult(b,c)

	if b == 0 or d == 0:
		bd = 0
	elif b < 10 and d < 10:
		bd = b*d
	else:
		bd = intMult(b,d)

	return pow(10, 2*n)*ac + pow(10, n)*ad + pow(10, n)*bc + bd
	


# Test
print(intMult(111, 111))
print(intMult(123, 321))
print(intMult(5678, 1234))
print(intMult(7,8))
print(intMult(12345678, 1))
print(intMult(12345678, 0))
print(intMult(11,11111))
