/* 
 * File:   prog1014.cpp
 * Author: Paul
 *
 * Created on December 2, 2010, 12:59 PM
 */

#include <iostream>
#include "Card.h"
#include "DeckofCards.h"

using namespace std;

void bubblesort( int *array, int length ) {
  //This is based on a bubblesort found online @ http://codecodex.com/wiki/Bubble_sort
  int i, j, temp ;
  int test ;

  for( i = ( length - 1 ) ; i > 0 ; i-- ) {
    test = 0 ;
    for( j = 0 ; j < i ; j++ ) {
      if( array[ j ] > array[ j + 1 ] ) {

        temp = array[ j ] ;
        array[ j ] = array[ j + 1 ] ;
        array[ j + 1 ] = temp;
        test = 1;

      }
    }

    if( test == 0 ) break ;

  }

  return ;

}



int checkWin( Card cards[ 5 ] ) {

    int i, j, checker = 0, win = 0, val ;
    int faces[ 5 ] ;

    for( i = 0 ; i < 5 ; i++ ) {
        for( j = 0 ; j < 5 ; j++ ) {
            if( i != j ) if( cards[ i ].getFace() == cards[ j ].getFace() ) {
                checker++ ;
                cards[ i ].setWincard( 1 ) ;
                cards[ j ].setWincard( 1 ) ;
            }
        }
    }


    if( checker == 2 ) win = 1 ; //Found a pair
    if( checker == 4 ) win = 2 ; //Found two pair
    if( checker == 6 ) win = 3 ; //Found three of a kind
    if( checker == 12 ) return 7 ; //Found four of a kind
    if( checker == 8 ) return 6 ;// Found a pair and three of a kind, full house

    //reset checker
    checker = 0 ; 
    //Check for a straight, Get all the face values
    for( i = 0 ; i < 5 ; i++ ) faces[ i ] = cards[ i ].getFace() ;

    //Sort the values in faces
    bubblesort( faces, 5 ) ;

    j = 1 ; 
    for( i = 0 ; i < 5 ; i++ ) {
        if( faces[ i ] + 1 == faces[ j ] ) {
            checker++ ;
        }
        j++ ; 
    }
  
    //cout << "checker is " << checker ;
    if( checker == 4 ) win = 4 ; // Found a straigt ;

    checker = 0 ; 
    //check for flush
    for( i = 0 ; i < 5 ; i++ ) {
        for( j = 0 ; j < 5 ; j++ ) {
            if( i != j ) if( cards[ i ].getSuit() == cards[ j ].getSuit() ) checker++ ;
        }
    }
    //cout << "checker is " << checker ;
    if( checker == 20 ) win = 5 ; // Found a flush

    return win ;

}

void wintype( int win ) {

    if( win != 0 ) {

        //cout << "The type of win is : " << endl ;

        if( win == 1 ) cout << " A Pair " << endl ;
        if( win == 2 ) cout << " Two Pair " << endl ;
        if( win == 3 ) cout << " Three of a Kind" << endl ;
        if( win == 4 ) cout << " A Straight " << endl ;
        if( win == 5 ) cout << " A Flush " << endl ;
        if( win == 6 ) cout << " Full House " << endl ;
        if( win == 7 ) cout << " Four of a Kind " << endl ;

        if( win == 10 ) cout << "The High Card" << endl ; 

    }

    else cout << "No win" << endl ;

    return ;
}

int highcard( Card hand[] ) {

    //Finds highest value card, that is also a winning card and returns its position in the hand
    int i, temp, post ;

    temp = 0 ;

    for( i = 0 ; i < 5 ; i++ ) {
        if( hand[ i ].getWincard() == 1 ) {
            if( temp < hand[ i ].getFace() ) {
                post = i ;
                temp = hand[ i ].getFace() ;
            }
        }
    }

    return post ;

}

int kicker( Card hand1[], Card hand2[] ) {
    
    int i, j, h1, h2 ;

    //Check to see if there are any non-winning aces in both hands if so return 3 since both have the same kicker
    for( i = 0 ; i < 5 ; i++ ) {
        if( hand1[ i ].getWincard() == 0 ) {
            if( hand1[ i ].getFace() == 1 ) {
                for( j = 0 ; j < 5 ; j++ ) {
                    if( hand2[ j ].getFace() == 1 ) return 3 ;
                }
            }
        }
    }
    
    //Set remaining win_card values to 1 for use with high card function
    for( i = 0 ; i < 5 ; i++ ) {
        hand1[ i ].setWincard( 1 ) ;
        hand2[ i ].setWincard( 1 ) ;
    }  

    //Get positions of highest value cards in hands
    h1 = highcard( hand1 ) ;
    h2 = highcard( hand2 ) ;

    //Return hand number that has highest kicker
    if( hand1[ h1 ].getFace() == hand2[ h2 ].getFace() ) return 3 ;
    if( hand1[ h1 ].getFace() > hand2[ h2 ].getFace() ) return 1 ;
    else return 2 ;       

    return -1 ; //Something went wrong
    
}

int betterhand( Card hand1[], Card hand2[], int win ) {

    //See who has the better hand if they both have the same type of win
    //Return 1 in hand1 won or 2 if hand2 won

    int i, counter1, counter2, post1, post2 ;
    counter1 = counter2 = 0 ;
    int faces1[ 5 ], faces2[ 5 ] ;

    if( win == 1 || win == 3 || win == 7 ) { //See which pair or three of a kind or four of a kind is better
        for( i = 0 ; i < 5 ; i++ ) {
            if( hand1[ i ].getWincard() == 1 ) counter1 = hand1[ i ].getFace() + counter1 ;
            if( hand2[ i ].getWincard() == 1 ) counter2 = hand2[ i ].getFace() + counter2 ; 
        }
        if( counter1 == counter2 ) return kicker( hand1, hand2 ) ;

        //If the pair is a pair of aces it beats the other pair, provided it isnt another ace pair, which is what the if() above will catch
        if( counter1 == 2 ) return 1 ; //Since the face value of ace is 1 counter == 2 if there is a pair of aces 
        if( counter2 == 2 ) return 2 ;

        if( counter1 > counter2 ) return 1 ;
        else return 2 ; 
    }

    if( win == 2 ) { //See which two-pair is better

        post1 = highcard( hand1 ) ; //find high card position
        counter1 = hand1[ post1 ].getFace() ;

        post2 = highcard( hand2 ) ;
        counter2 = hand2[ post2 ].getFace() ;
        
        //If they both have the same two pair check for a kicker
        if( counter1 == counter2 ) return kicker( hand1, hand2 ) ;
        if( counter1 > counter2 ) return 1 ; //In two pair the highest pair of both hands wins
        else return 2 ;
    }

    //Check to see which straight is better
    if( win == 4 ) {
        for( i = 0 ; i < 5 ; i++ ) {
            counter1 = counter1 + hand1[ i ].getFace() ;
            counter2 = counter2 + hand2[ i ].getFace() ;
        }
        if( counter1 > counter2 ) return 1 ; 
        else return 2 ;
    }

    //Determine better flush
    if( win == 5 ) {
        //Put a 1 in wincard so we can find the high card
        for( i = 0 ; i < 5 ; i++ ) {
            hand1[ i ].setWincard( 1 ) ;
            hand2[ i ].setWincard( 1 ) ;
        }

        post1 = highcard( hand1 ) ; //find high card position
        counter1 = hand1[ post1 ].getFace() ;

        post2 = highcard( hand2 ) ;
        counter2 = hand2[ post2 ].getFace() ;

        if( counter1 > counter2 ) return 1 ; 
        else return 2 ;

    }

    //Check who has better full house
    if( win == 6 ) {

        for( i = 0 ; i < 5 ; i++ ) {
            faces1[ i ] = hand1[ i ].getFace() ;
            faces2[ i ] = hand2[ i ].getFace() ;
        }

        //Sort the values in hand1 and hand2
        bubblesort( faces1, 5 ) ;
        bubblesort( faces2, 5 ) ;

        if( faces1[ 2 ] == faces1[ 3 ] ==  faces1[ 4 ] )
            counter1 = faces1[ 2 ] + faces1[ 3 ] +  faces1[ 4 ] ;
        else counter1 = faces1[ 0 ] + faces1[ 1 ] +  faces1[ 2 ] ;

        if( faces2[ 2 ] == faces2[ 3 ] ==  faces2[ 4 ] )
            counter2 = faces2[ 2 ] + faces2[ 3 ] +  faces2[ 4 ] ;
        else counter2 = faces2[ 0 ] + faces2[ 1 ] +  faces2[ 2 ] ;

        if( counter1 > counter2 ) return 1 ;
        else return 2 ;

    }

    return -1 ; //Something went wrong

    
}

void dealer_ai( Card *hand, int win, DeckofCards deck ) {

    //If the dealer has a straigt / flush / four of a kind do nothing
    int i ; 
    
    //If the dealer has a pair, two pair, three of a kind discard the non winning cards
    if( win == 1 || win == 2 || win == 3 ) {
        for( i = 0 ; i < 5 ; i++ ) {
            //If the card at hand[i] is not a part of the winning cards discard and get new cards
            if( hand[ i ].getWincard() == 0 ) hand[ i ] = deck.dealCard() ;
        }
        return ; 
    }

    //If the dealer has nothing discard the hand
    if( win == 0 ) for( i = 0 ; i < 5 ; i++ ) hand[ i ] = deck.dealCard() ; 

    return ; 
}

void hands( Card hand[], int player, int print ) {

    //This function gets hands and then prints them
    int counter = 0 ;

    if( player == 1 ) cout << "Player's Hand :" << endl ;
    if( player == 2 ) cout << "Dealer's Hand :" << endl ;

    while( counter != 5 ) {
        if( print == 0 ) cout << hand[ counter ].toString() << endl ; //Only print the cards out if the code is 0
        if( print == 1 ) cout << "HIDDEN" << endl ; // only for computer
        counter++ ;
    }
    return ;
}

void whowon( int win1, int win2, Card hand1[], Card hand2[], int code ) {

    //Determine who wins and such
    if( ( win1 == 0 ) && ( win2 == 0 ) ) {
        //Set win_card to 1 so that the highest_card() can find the high card
        for( int i = 0 ; i < 5 ; i++ ) {
            hand1[ i ].setWincard( 1 ) ;
            hand2[ i ].setWincard( 1 ) ;
        }
        int pos1 = highcard( hand1 ) ;
        int pos2 = highcard( hand2 ) ;

        if( hand1[ pos1 ].getFace() == hand2[ pos2 ].getFace() ) win1 = win2 = 9 ;
        //cout << "the high card" << hand1[ pos1 ].getFace() << " and for hand2 " << hand2[ pos2 ].getFace() ;
        if( hand1[ pos1 ].getFace() > hand2[ pos2 ].getFace() ) win1 = 10 ;
        else win2 = 10 ;
    }

    if( win1 == 9 ) {
        cout << "Both players have no types of win. Both players have the same high card. It is a tie." << endl ;
        return ;
    }

    if( ( win1 == win2 ) ) code = betterhand( hand1, hand2, win1 ) ;

    if( code == 3 ) {
        cout << "Both players have the same type of win : " ;
        wintype( win1 ) ;
        cout << " and have the same kicker card so it is a tie." << endl ;
        return ;
    }

    if( ( win1 > win2 ) || ( code == 1 ) ) {
        cout << "Player 1 wins they have : " ;
        wintype( win1 ) ;
        if( win1 == win2 ) cout << " A better one than Player 2. " << endl ;
        cout << endl ;

        cout << "Compared to Player 2 who has : " ;
        wintype( win2 ) ;
        cout << endl ;

    }

    else {

        cout << "Player 2 wins they have : " ;
        wintype( win2 ) ;
        if( win1 == win2 ) cout << " A better one than Player 1. " << endl ;
        cout << endl ;

        cout << "Compared to Player 1 who has : " ;
        wintype( win1 ) ;
        cout << endl ;



    }
    return ;

}

void discard( int win1, Card *hand1, DeckofCards &deck1 ) {

    int counter = 0, discard ;
    int i, err[ 5 ] ;

     //Initialize err[] to all 0
    for( i = 0 ; i < 5 ; i++ ) err[ i ] = 0 ;

    win1 = checkWin( hand1 ) ;
    cout << "You have : " ;
    wintype( win1 ) ;
    cout << "You may now discard cards if you want." << endl <<
            "To discard cards enter the position (1-5) in you hand of the card to discard. " << endl <<
            "You can discard 0 or 5 cards." << endl <<
            "Enter the position of the card to discard ONE at a time" << endl <<
            "Entering 0 will finish discarding cards." << endl ;

    counter = 0 ; //Reset counter
    while( 1 ) {
       if( counter == 5 ) {
            cout << "You have discarded all your cards once." << endl ;
            break ;
        }
        cout << "Enter another card position to discard it (or 0 to finish)." << endl ;
        cin >> discard ;
        if( discard > 5 || discard < 0 ) cout << "That is not a valid card poisiton" << endl ;
        if( discard == 0 ) break ;

        discard-- ;
        if( err[ discard ] == 1 ) cout << "You have already discarded this card" << endl ;

        else {
            cout << "You are discarding : " << hand1[ discard ].toString() << endl ;
            hand1[ discard ] = deck1.dealCard() ;
            err[ discard ] = 1 ;
            counter++ ;

            //hands( hand1, 1, 0 ) ;
            //cout << "You have : " ;
            //win1 = checkWin( hand1 ) ;
            //wintype( win1 ) ;
        }
    }

    return ; 

}

int main() {

    DeckofCards deck1 ;
    Card hand1[ 5 ], hand2[ 5 ] ; 
    int counter = 0, win1, win2, code = 0 ;
 

    deck1.shuffle() ;

    //Deal hands

    while( counter != 5 ) {
        hand1[ counter ] = deck1.dealCard() ;
        hand2[ counter ] = deck1.dealCard() ;
        counter++ ; 
    }

    hands( hand1, 1, 0 ) ; //hand1 is the players hand, 1 means player 1, 0 means print
    cout << endl ; 
    hands( hand2, 2, 0 ) ; // 1 at end means Print out HIDDEN
    cout << endl ;

    //Discard cards for player hand
    discard( win1, hand1, deck1 ) ;
      
    //Check what type of win ai has and see if it should discard some cards
    win2 = checkWin( hand2 ) ;
    dealer_ai( hand2, win2, deck1 ) ;
    win2 = checkWin( hand2 ) ;

    //Print out both hands
    hands( hand1, 1, 0 ) ;
    cout << endl ;
    hands( hand2, 2, 0 ) ; //Print hand

    cout << endl ;
    whowon( win1, win2, hand1, hand2, code ) ;

    
    return 0 ;
    
}

