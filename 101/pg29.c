/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 29: Find the Average                                */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x[ 4 ], i ;

  float ave, f[ 4 ] ;

  FILE *fin ;

  fin = fopen( "testdata26", "r" ) ; 
  
  printf( "The numbers in the file are: " ) ;

  for ( i = 0 ; i < 4 ; i++ ) {

    fscanf( fin, "%d", &x[ i ] ) ;

    printf( "%d ", x[ i ]) ;

    f[ i ] = ( float )x [ i ] ; 

  }

  ave = ( f[ 0 ] + f[ 1 ] + f[ 2 ] + f[ 3 ] ) / 4 ;   

  printf( "\nThe average of the numbers in the file is %f. \n\n", ave ) ;

  fclose( fin ) ;

  return  0 ;
}

