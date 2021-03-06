/**
 * Convert bubble sort example to merge sort
 *
 *
 * Some of code copied from:
 *
 *    http://faculty.salina.k-state.edu/tim/CMST302/study_guide/topic7/bubble.html
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * bubble sort
 *
 *
 * @return LIST
 */
LIST *bubble_sort( LIST *start )
{
        LIST *p, *q, *top;
        int changed = 1;

        /** We need an extra item at the top of the list just to help
         *  with assigning switched data to the 'next' of a previous item.
         *  It (top) gets deleted after the data is sorted.
         */

        if( (top = (LIST *)malloc(sizeof(LIST))) == NULL) {
                fprintf( stderr, "Memory Allocation error.\n" );
                // In Windows, replace following with a return statement.
                exit(1);
        }

        top->next = start;
        if( start != NULL && start->next != NULL ) {
                /**
                 * Variable q is always one item behind p. We need q, so
                 * that we can make the assignment q->next = list_switch( ... ).
                 */

                while( changed ) {
                        changed = 0;
                        q = top;
                        p = top->next;
                        while( p->next != NULL ) {
                                /* push bigger items down */
                                if( p->data > p->next->data ) {
                                        q->next = list_switch( p, p->next );
                                        changed = 1;
                                }
                                q = p;
                                if( p->next != NULL )
                                        p = p->next;
                        }
                }
        }
        p = top->next;
        free( top );
        return p;
}

int main(int argc, char *argv[])
{
        LIST *try;

        // This is just testing code
        try = NULL;
        try = append( try, 5 );
        try = append( try, 2 );
        try = append( try, 9 );
        try = append( try, 8 );
        try = append( try, 1 );
        try = append( try, 7 );

        printf("\n------ Start Bubble Sort ----- \n\n");

        printf("Original list:\n");
        print_list( try );
        printf("\n");

        try = bubble_sort( try );
        printf("Sorted list (bubble sort):\n");
        print_list( try );
        printf("\n");
}
