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


/* Definition of ticket */

#ifndef __Ticket_H__
#define __Ticket_H__

// Max length of the strings
#define MAXCHARS 50


typedef struct ticket ticket_t;

struct ticket // declaring the ticket structure
{
    int ticketnum;
    char companyident[MAXCHARS + 1];
    char issuecode[MAXCHARS + 1];
    char status[10];
    char technicianname[MAXCHARS + 1];
    ticket_t *next;
};

#endif