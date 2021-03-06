/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 90: Recursive Persistence                           */
/*                                                             */
/* Approximate completion time: 40 minutes                     */
/***************************************************************/

#include <stdio.h>

int pers( int n, int count ) {

  count++ ; 

  if( n == 0 ) return ( count / 2 ) ;

  return( pers( ( ( n % 10 ) * ( n / 10 ) ), count ) ) ; 

}
 

int main( int argc, char *argv[] ) {

  int per, number, count = 0 ;

  printf( "Please enter an integer. \n" ) ;
  
  while( ( scanf( "%d", &number ) ) !=EOF ) {
    
    if( number <= 9 ) printf( "The persistence of %d is 0. \n", number ) ;
    
    else {

      per = pers( number, count ) ;   

      printf( "The persistence of %d is %d. \n", number, per ) ;
    
    }
  
  }
  
  return  0 ;

}

