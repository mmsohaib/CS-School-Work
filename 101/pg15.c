/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 15: Using the sqrt Function                         */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] ) {

  float x ;

  printf( "\nPlease enter a number.\n\n" ) ;
 
  scanf( "%f", &x ) ;
 
  printf( "\nThe square root of your number is: %f.\n", sqrt( x ) ) ; 

  return  0 ;

}

