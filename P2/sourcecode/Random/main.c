#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, j, nr_copii, k;
    char temp_name_in[20];
    time_t t;
    srand((unsigned) time(&t));

    for(j=1;j<=10;j++)
        {
    sprintf(temp_name_in, "teste\\test_%d.in", j+1);
    FILE* test_in = fopen(temp_name_in, "wt");

        n=rand()%100;
        k=rand()%100;

        while(n<=0 || n==1)
        {
            n=rand()%100;
        }

        while (k<=0)
        {
            k=rand()%100;
        }

        printf("%d\n", nr_copii);
        fprintf(test_in, " %d\n", nr_copii);
        printf("%d\n", k);
        fprintf(test_in, "%d", k);

        fclose(test_in);
    }

    return 0;
}
