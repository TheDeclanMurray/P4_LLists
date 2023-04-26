
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