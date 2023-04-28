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


/* this function takes pointers to the heads of both the assigned and completed
ticket lists, and returns to us th head of the updated ticket list.

preconditions: assignedtix and completedtix are valid pointers, can be null
postconditions: the completedtix head that is returned mus be valid, but can be null*/
void completedtix(ticket_t **assignedtixPtr, ticket_t **completedtixPtr){
    printf("\t---\nYou have entered the complete-ticket function\n");

    ticket_t *assignedtix = (*assignedtixPtr);
    ticket_t *completedtix = (*completedtixPtr);

    int num;
    printf("what is the ticket that is complete? ");
    scanf("%d", &num);
    printf("Now looking for ticket %d\n", num);

    // find the ticket inside of assigned tickets
    ticket_t *prev = NULL;
    ticket_t *curr = assignedtix;
    while (curr != NULL && curr->ticketnum != num){
        prev = curr;
        curr = curr->next;
    }

    // if the number is not found
    if(curr->ticketnum != num){
        printf("Not a Valid Input\n");
        return;
    }

    // fix the assigned list
    if (prev == NULL){
        // completed ticket is the first in the assigned list
        *assignedtixPtr = (*curr).next;
    }else{
        //curr is not the head of the list
        (*prev).next = (*curr).next;
    }

    // change status
    strcpy((*curr).status, "completed");
    
    // add the ticket to completed tickets
    if (completedtix == NULL){
        // completed tickets is empty
        completedtix = curr;
        (*curr).next = NULL;
        *completedtixPtr = curr;
    }else{
        // completed tickets is not empty

        // get the last ticket in completed
        ticket_t *last = completedtix;
        while ((*last).next != NULL)
        {
            last = (*last).next;
        }
        (*last).next = curr;
        (*curr).next = NULL;
    }
    printf("Ticket #%d Completeted",num);
}

/* this function takes pointers to the heads of both the new and assigned
ticket lists, and returns to us th head of the updated ticket list.

preconditions: assignedtix and new are valid pointers, can be null
postconditions: the assignedtix head that is returned mus be valid*/
ticket_t *assigntix(ticket_t *newtix, ticket_t *assignedtix){
    printf("\t---\nYou have entered the the assign ticket function\n");

    if (newtix == NULL){
        // if the new list is empty
        printf("There are no new tickets. You have to make a new node\n");
        return assignedtix;
    }else{
        // new list is not empty
        strcpy((*newtix).status, "assigned");
        printf("Technician Name: ");
        scanf("%s",newtix->technicianname);
    }

    if (assignedtix == NULL){
        // assigned tickets is empty
        assignedtix = newtix;
    }else{
        // assigned tickets is not empty
        ticket_t *curr = assignedtix;
        while ((*curr).next != NULL){
            assignedtix = (*curr).next;
        }
        (*curr).next = newtix;
    }
    return assignedtix;
}

/* this function takes a pointer to the head of the new tickets list,
and returns the newlist with modifications based on the new ticket you made

preconditions: newList is a valid pointers, can be null
postconditions: the newList head that is returned mus be valid, shouldn't be null*/
ticket_t *makenewtix(ticket_t *newlist, int ticNum){
    printf("\t---\nYou have entered the make-new-ticet procedure\n");
    ticket_t *newTicket = malloc(sizeof(ticket_t) * 1); // alllocating space for a new node
    (*newTicket).ticketnum = ticNum; 
    printf("This new ticket has been assigned the number %d\n", ticNum);

    ticket_t *newlisthead = NULL;
    ticket_t *curr = NULL;

    if (newlist == NULL){
        // head of list
        newlisthead = newTicket;
    }else{
        // not head of list
        newlisthead = newlist;
        curr = newlist;
        while ((*curr).next != NULL){ // loop to find the last ticket
            curr = (*curr).next;
        }
        (*curr).next = newTicket; // the ticket is set as the last thing in the list
        (*newTicket).next = NULL;    // the next is set to be null
    }

    strcpy((*newTicket).technicianname, "unassigned");


    printf("What's the Issue: ");
    scanf("%s",newTicket->issuecode);
    printf("Company Code: ");
    scanf("%s",newTicket->companyident);

    strcpy((*newTicket).status, "New");
    return newlisthead; // returns the head of the list
}

/* prompts the user for their input, and returns their input integer.
pre and postconditions: none*/
int printchoicemenu(void){
    int *choiceptr = (int *)malloc(sizeof(int) * 1);
    printf("\nThis procedure takes a number 1 - 7 corresponding to an action with our tickets\n");
    printf("\t1: create a new ticket\n");
    printf("\t2: assigning a ticket\n");
    printf("\t3: complete a ticket\n");
    printf("\t4: print the new ticket list\n");
    printf("\t5: print the assigned ticket list\n");
    printf("\t6: print the completed ticket list\n");
    printf("What would you like to do now: ");
    scanf("%d", choiceptr);
    return *choiceptr;
}

/*this function takes the pointer to the head of a list, and prints it out, from beginning to end
preconditions: none
postconditiions: none*/
void printList(ticket_t *list){
    while (list != NULL){
        printf("Ticket Number:   %d\n", (*list).ticketnum);
        printf("\tCompany:          \t%s\n", (*list).companyident);
        printf("\tIssue Code:       \t%s\n", (*list).issuecode);
        printf("\tStatus:           \t%s\n", (*list).status);
        printf("\tTechnician Name:  \t%s\n", (*list).technicianname);
        list = (*list).next;
    }
}
