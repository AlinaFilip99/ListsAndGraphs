#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    int n, r, i, m, p, max;
    int nr_tatac, nr_taparare, nr_max_tunele;
    struct a_graph *graph_1;

    for(i=1; i<=10; i++)
    {
        char temp_name_in[20];
        char temp_name_out[20];

        sprintf(temp_name_in, "teste\\test_%d.in", i);
        sprintf(temp_name_out, "teste\\test_%d.out", i);

        FILE* test_in = fopen(temp_name_in, "r");
        FILE* test_out = fopen(temp_name_out, "wt");

        if(!test_in)
        {
            return -1;
        }


        graph_1 = calloc(1, sizeof(struct a_graph));

        fscanf(test_in, "%d", &n);
        fscanf(test_in, "%d", &r);

        nr_tatac=0;nr_taparare=0;

        max=-5;
        for(m=n/2;m>=1;m--)
            {
             p=n-m;
            nr_max_tunele=m*p;
            if(nr_max_tunele>=r)
            {
                nr_tatac=m;
                nr_taparare=p;
                max=nr_tatac*nr_taparare;
            }
        }


        if(max<r)
        {
            fprintf(test_out, "Nu se pot forma %d tunele cu cele %d turnuri\n", r, n);
                 delete_graph(graph_1);
                fclose(test_in);
                fclose(test_out);
        }

        if(max>=r)
        {
                init_graph(graph_1,n,nr_tatac,r);
                    print_file(graph_1, i,nr_tatac, nr_taparare);

        }

        delete_graph(graph_1);
        fclose(test_in);
        fclose(test_out);
    }
    return 0;
}
