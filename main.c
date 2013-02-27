#include <stdio.h>
#include "prime.h"
#include "mpi.h"

/**
 * Range upper limit of the number to find the primes.
 */
#define N 5000000

/**
 * Find how many prime odd consecutive numbers there
 * are between 1 and 5,000,000.  Tried 100,000,000 
 * and 50,000,000 but it took more than 30 mintues.
 * 
 * Splits the data evenly into ranks.  It then
 * processes and find how many odd consecutive
 * numbers there is for a given rank.  Once 
 * all this is done it print how long it took.
 */
int main( int argc , char **argv ) {
	
	/* Declare */
	double starttime, endtime;
	struct PrimeStartEnd primeStartEnd;
    int rank,size;
	int i;
	int result=0;
	
    /* Initialize MPI. */
    MPI_Init( &argc , &argv );
    
    /* Find rank. */
    MPI_Comm_rank( MPI_COMM_WORLD , &rank );
    /* Find size. */
    MPI_Comm_size( MPI_COMM_WORLD , &size );

	/* Go through each rank. */
    for(i=0; i < size ; i++) {
	
		/* Select the correct rank. */
		if( i==rank ) {
			
			/* Algorithm to calculate the start and end range of the ranks. */
			primeStartEnd.start = ( (i)*(N/(size)) + 1 );
			primeStartEnd.end = (i+1)*(N/(size));
			
			/* Start time stopwatch. */
			starttime = MPI_Wtime();
			
			/* How many consecutive odd primes for a given rank */
			result = do_work( primeStartEnd );
			
			/* Stop stopwatch. */
			endtime = MPI_Wtime();
			
			/* Print how long it took to find the numbers for a given rank. */
			printf("time: %f\n", endtime - starttime);

		}
	}

    /* Shut down MPI */
    MPI_Finalize();

    return 0;
}

