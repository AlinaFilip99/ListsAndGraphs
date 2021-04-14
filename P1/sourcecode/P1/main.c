#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "linkedlist.h"

int main()
{
    struct g_node *head = malloc(sizeof(struct g_node));
    int aux;
    int nr_copii, i, k, m, j;
    char temp_name_in[20];
    char temp_name_out[20];

    for(j=1; j<=10; j++)
    {
        sprintf(temp_name_in, "teste\\test_%d.in", j);
        sprintf(temp_name_out, "teste\\test_%d.out", j);

        FILE* test_in = fopen(temp_name_in, "r");
        FILE* test_out = fopen(temp_name_out, "wt");

        if(!test_in)
        {
            return -1;
        }

        fscanf(test_in, "%d", &nr_copii);
        fscanf (test_in, "%d", &k);

        head->next = head;

        for(i=1; i<=nr_copii; i++)
        {
            push_element_end(head, i);
        }

        if(k==1)
        {
            fprintf (test_out,"\nOrdinea in care copii sunt eliminati din joc este:\n");
            for(i=1; i<=nr_copii; i++)
            {
                aux=pop_element_at_position(head,0);
                fprintf(test_out, " %d", aux);
            }
            fclose(test_out);
            free(head);
        }

        if(k!=1)
        {

            fprintf (test_out,"\nOrdinea in care copii sunt eliminati din joc este:\n");

            if(k<=nr_copii)
            {
                i=k-1;
                while (i!=nr_copii)
                {
                    aux = pop_element_at_position(head,k-1);
                    fprintf(test_out, " %d", aux);
                    i++;
                }
                nr_copii=k-1;
            }

            for(i=1; i<=nr_copii; i++)
            {
                aux = pop_element_at_position(head,k);
                fprintf(test_out, " %d", aux);
            }

            free(head);
            fclose(test_out);
            fclose(test_in);
        }
    }
    printf ("SUCCES");
    return 0;
}

