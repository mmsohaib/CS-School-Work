/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 22: Reverse the Command Line                        */
/*                                                             */
/* Approximate completion time: 5 minutes                      */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int i ;

  for (i = ( argc - 1 ) ; i >= 0 ; i-- ) {

    printf( "\n\n %s", argv[ i ] ) ;

  }

  return  0 ;

}

