//This program does some operations on arrays

public class IntArray {

    public static void main( String[] args ) {

	//Declare variables 
	int firstInt[] ;
	int my2DArray[][] ;
	int i, j ;

	//Make space for arrays
	firstInt = new int[ 20 ] ;
	my2DArray = new int[ 2 ][ 20 ] ;

	//Initialize array with loop 
	for( i = 0 ; i < 20 ; i++ ) firstInt[ i ] = i ; ; 

	//Shorthand method of array initialization
	int secondInt[] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 } ;

	//Print out the array values 
	System.out.print( "The values in the first array : " ) ;
	for( i = 0 ; i < 20 ; i++ ) {
	    System.out.print( " " + firstInt[ i ] ) ;
	}
	System.out.print( "\n" ) ;

        System.out.print( "The values in the second array : " ) ;
        for( i = 0 ; i < 20 ; i++ ) {
            System.out.print( " " + secondInt[ i ] ) ;
        }

	//Assign those value in the firstInt array and secondInt array into my2DArray 
	for( i = 0 ; i < 2 ; i++ ) {
	    for( j = 0 ; j < 20 ; j++ ) {
		if( i == 0 ) my2DArray[ i ][ j ] = firstInt[ j ] ;
		if( i == 1 ) my2DArray[ i ][ j ] = secondInt[ j ] ;
	    }
	}

	System.out.print( "\nThe values in the 2D Array are : " ) ;
	//Print out all the values in the 2DArray 
	for( i = 0 ; i < 2 ; i++ ) {
            for( j = 0 ; j < 20 ; j++ ) {
		System.out.print ( " " + my2DArray[ i ][ j ] ) ;
	    }
	}

    }

} 
