# Integer multiplication - recursive algorithm

def numDigits(num):
	count = 0
	while (num > 0):
		count += 1
		num //= 10
	return count

# Assume num1 and num2 are positive
def karatsuba(num1, num2):
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

        # a*c
	if a == 0 or c == 0:
		z2 = 0
	elif a < 10 and b < 10:
		z2 = a*c
	else:
		z2 = karatsuba(a,c)

        
        # (a + b)*(c + d)
	if (a + b) == 0 or (c + d) == 0:
		 z1 = 0
	elif (a + b) < 10 and (c + d) < 10:
                z1 = (a + b)*(c + d)
	else:
		z1 = karatsuba(a+b,c+d)

	
        # b*d	
	if b == 0 or d == 0:
		z0 = 0
	elif b < 10 and d < 10:
		z0 = b*d
	else:
		z0 = karatsuba(b,d)
	return pow(10, 2*n)*z2 + pow(10, n)*(z1 - z2 - z0)  + z0
	


# Test
print("111 x 111 = ", karatsuba(111, 111))
print("123 x 321 = ", karatsuba(123, 321))
print("5678 x 1234 = ", karatsuba( 5678, 1234))
print("7 x 8 = ", karatsuba(7,8))
print("12345678 x 1 = ", karatsuba(12345678, 1))
print("12345678 x 0 = ", karatsuba(12345678, 0))
print("11 x 11111 = ", karatsuba(11,11111))
