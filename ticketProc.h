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


// interface for a ticket list data type based on a list ticket_t type

#ifndef __ticketProc_H__
#define __ticketProc_H__

#include "ticket.h"

/* this function takes pointers to the heads of both the assigned and completed
ticket lists, and returns to us th head of the updated ticket list.

preconditions: assignedtix and completedtix are valid pointers, can be null
postconditions: the completedtix head that is returned mus be valid, but can be null*/
void completedtix(ticket_t **assignedtixPtr, ticket_t **completedtixPtr);

/* this function takes pointers to the heads of both the new and assigned
ticket lists, and returns to us th head of the updated ticket list.

preconditions: assignedtix and new are valid pointers, can be null
postconditions: the assignedtix head that is returned mus be valid*/
ticket_t *assigntix(ticket_t *newtix, ticket_t *assignedtix);

/* this function takes a pointer to the head of the new tickets list,
and returns the newlist with modifications based on the new ticket you made

preconditions: newList is a valid pointers, can be null
postconditions: the newList head that is returned mus be valid, shouldn't be null*/
ticket_t *makenewtix(ticket_t *newlist, int ticNum);

/* prompts the user for their input, and returns their input integer.
pre and postconditions: none*/
int printchoicemenu(void);

/*this function takes the pointer to the head of a list, and prints it out, from beginning to end
preconditions: none
postconditiions: none*/
void printList(ticket_t *list);

#endif