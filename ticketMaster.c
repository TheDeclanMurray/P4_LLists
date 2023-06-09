    /***********************************************************************
     * Declan Murray and John Miller                                       *
     * Assignment name (Project  4 ticketmaster)                           *
     *                                                                     *
     * Assignment for <4/28/2022>                                          *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used: none                                 *
     *      textbook(s)                                                    *
     *      CSC 161 labs and readings;                                     *
     *                                                                     *
     *   Help obtained                                                     *
     *     None                                                            *
     *   Our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:John Miller and Declan Murray                           *
     ***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticketProc.h"

int main(void){
    ticket_t *newList = NULL;
    ticket_t *assigned = NULL;
    ticket_t *completed = NULL;
    ticket_t *tempTickit = NULL;
    int ticketNum = 1;

    int userInput = printchoicemenu();
    while (userInput != 7){
        switch (userInput){
            case 1:
                /* Create a new tracking ticket */
                newList = makenewtix( newList, ticketNum++ );
                system("clear");
                break;
            case 2:
                /* Assign a new ticket to a technician for handling */
                tempTickit = newList;          // get the first element of newList
                newList = newList->next;       // remove that first element from newList
                tempTickit->next = NULL;       // remove the firsts elements pointer
                assigned = assigntix(tempTickit,assigned); //assign
                tempTickit = NULL;            // reset tempTicket
                system("clear");
                break;
            case 3:
                /* Mark a ticket complete */
                completedtix(&assigned, &completed);
                system("clear");
                break;
            case 4:
                /* Print a list of new tickets */
                system("clear");
                printf("\n\t\tNew Tickets\n");
                printList(newList);
                break;
            case 5:
                /* Print a list of assigned tickets */
                system("clear");
                printf("\n\t\tAssigned Tickets\n");
                printList(assigned);
                break;
            case 6:
                /* Print a list of completed tickets */
                system("clear");
                printf("\n\t\tCompleted Tickets\n");
                printList(completed);
                break;
            default:
                break;
        }
        userInput = printchoicemenu();
    }
    printf("\n\n\n");
    return 0;
}