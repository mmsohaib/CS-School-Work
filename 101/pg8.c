/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Problem 8: One Horizontal Line of Asterisks                 */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {


  int x, limit ; 

  FILE *fin ;

  fin = fopen( "testdata8", "r" ) ;

  fscanf( fin, "%d", &x ) ; 

  for( limit = 0 ;  limit < x ; limit++ ) printf( "*" ) ;  

  fclose( fin ) ; 

  return  0 ;

}
 
  
