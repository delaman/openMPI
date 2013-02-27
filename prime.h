/* 
 * File:   prime.h
 * Author: pedro
 *
 * Created on March 19, 2010, 5:30 PM
 */

#ifndef _PRIME_H
#define	_PRIME_H

#include <math.h>

#ifdef	__cplusplus
extern "C" {
#endif
	
	/**
	 * This holds the start and end of the prime calulations range.
	 */
	struct PrimeStartEnd {
		int start;
		int end;
	};

    /**
     * Tests for prime number.
     *
     * @param num The number to test if it is a prime number.
     * @return This will return true if it a prime false otherwise.
     */
    int isPrime( int num );
    
	/**
	 * Does the actual calculations of the odd consecutive
	 * numbers.
	 * 
	 * @param primeStartEnd A struct that holds where to start
	 * and stop the calculatios of prime numbers.
	 * @return How many odd consecutive numbers there are.
	 */
	int do_work( struct PrimeStartEnd primeStartEnd );

	/**
	 * Checks if a given number is odd or not.
	 * 
	 * @param num The number to check if it is a odd number.
	 * @return True if it is a odd number.
	 */
	int is_odd( int num );


#ifdef	__cplusplus
}
#endif

#endif	/* _PRIME_H */

