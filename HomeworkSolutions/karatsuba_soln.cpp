/* Karatsuba multiplication */
#include <iostream>
#include <cassert>

using namespace std;

int numDigits(int num);
int pow10(int n);



int karatsuba(int x, int y) {
    int m, n, a, b, c, d;
    n = numDigits(x); // Determine number of digits in x
	m = numDigits(y); // Determine number of digits in y

	if (m > n)
        n = m;
	n = n/2;

    if (n > 1) { // If there is more than one digit 
        a = x / pow10(n/2); // First half of x
        b = x % pow10(n/2); // Second half of x
    }
    else {
        a = 0;
        b = x;
    }
        
    if (n > 1) {
        c = y / pow10(n/2); // First half of y
        d = y % pow10(n/2); // Second half of y
    }
    else {
        c = 0;
        d = y;
    }
        
    int ac, bd, ab_cd, ad_bc;
    
    if (a == 0 || c == 0)
        ac = 0;
    else if ((a < 10) && (c  < 10)) // Base case
        ac = a*c;
    else
        ac = karatsuba(a,c); 
    
    if (b == 0 || d == 0)
        bd = 0;
    else if ((b < 10) && (d  < 10)) // Base case
        bd = b*d;
    else
        bd = karatsuba(b,d);
        
    if (((a+b) == 0) || ((c+d) == 0))
        ab_cd = 0;
    else if ((a+b < 10) && (c+d  < 10)) // Base case
        ab_cd = (a+b)*(c+d);
    else
        ab_cd = karatsuba(a+b, c+d);
    
    ad_bc = ab_cd - ac - bd;
    	
    return pow10(2*n)*ac + pow10(n)*(ad_bc) + bd;
    
}

// Helper function - returns number of digits
int numDigits(int num) {
    if (num == 0)
        return 1;
    if (num < 0)
        num *= -1;
    int n = 0;
    while (num > 0) {
        n++;
        num /= 10;
    }
    return n;
}

// Helper function - integer exponentiation
int pow10(int n) {
    assert(n >= 0);
    int p = 1;
    for (int i = 0; i < n; i++) {
        p *= 10;
    }
    return p;
}





