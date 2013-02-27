#include "prime.h"

int isPrime(int num) {

    if (num <= 1)
        return 0;
    else if (num == 2)
        return 1;
    else if (num % 2 == 0)
        return 0;
    else {

        int prime = 1;
        int divisor = 3;
        double num_d = (double)(num);
        int upperLimit = (int)(sqrt(num_d) + 1);

        while (divisor <= upperLimit) {

            if (num % divisor == 0)
                prime = 0;

            divisor += 2;
        }
        return prime;
    }
}

int do_work( struct PrimeStartEnd primeStartEnd ) {
	
	/* Declare */
	int i;
	int tmpNumber = 2; /* tmp variable that holds a prime number to be later checked */
	int counter = 0;
	
	/* Get all the primes between 1 and num */
    for (i = primeStartEnd.start; i <= primeStartEnd.end; i++) {

		/* 
		 * Check if i is odd and the previous tmpNumber is an odd consecutive number 
		 * 
		 * ie.  977 979
		 * ie.  997 999
		 * 
		 * example of not an odd consecutvie number is
		 * 		9 15
		 */
		if( is_odd(i) == 1 && tmpNumber+2 == i ) 
			counter++;
		
		/* The number is a prime and odd */
        if( isPrime(i) && is_odd(i) ) 
			tmpNumber = i;		

	}
	
	return counter;
}

int is_odd( int num ) {
	
	if( num % 2 == 0)
		return 0;
	else
		return 1;
	
}
