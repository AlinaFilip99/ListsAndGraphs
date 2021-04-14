#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value){
    int position1;
    int position2;

    assert(row_index < graph->no_nodes);
    assert(column_index < graph->no_nodes);

    position1 = row_index * graph->no_nodes + column_index;
    position2 = column_index*graph->no_nodes+row_index;
    *(graph->adj_matrix + position1) = element_value;
    *(graph->adj_matrix + position2) = element_value;
}

int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index) {
    int position;

    assert(row_index < graph->no_nodes);
    assert(column_index < graph->no_nodes);

    if (graph->init == 1){
        position = row_index * graph->no_nodes + column_index;
        return *(graph->adj_matrix + position);
    }else{
        printf("Please read the graph first");
        return -1;
    }
}

void init_graph(struct a_graph *graph, int n, int m, int r){
    int iterator_rows;
    int iterator_columns;
    int aux;

    graph->no_nodes=n;
    graph->init = 1;
    graph->adj_matrix = calloc(graph->no_nodes * graph->no_nodes,sizeof(int));

    assert((graph->no_nodes * graph->no_nodes) > 0);

    for (iterator_rows = 0; iterator_rows < graph->no_nodes; iterator_rows++ ){
        for (iterator_columns = iterator_rows; iterator_columns < graph->no_nodes; iterator_columns++ ){
                if((iterator_rows<=m-1)&&(iterator_columns>=m)&&(r!=0))
                {
                    aux=1;
                    set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);
                    r--;
                }
                else{
                        aux=0;
                set_adj_matrix_value(graph, iterator_rows, iterator_columns, aux);
                }

        }
    }
}

void print_file(struct a_graph *graph, int i, int atac, int aparare){
    FILE* test_out;
    int iterator_rows;
    int iterator_columns;
    int aux;
    char temp_name_out[20];

sprintf(temp_name_out, "teste\\test_%d.out", i);

    test_out=fopen(temp_name_out, "wt");

    fprintf(test_out,"Numarul turnurilor de atac este: %d\n", atac);
                fprintf(test_out, "Numarul turnurilor de aparare este: %d\n", aparare);

    iterator_rows--;
    if (graph->init == 1){
            for(iterator_rows=0;iterator_rows<graph->no_nodes;iterator_rows++){
                    fprintf(test_out,"Pentru nodul %d avem legaturile: ", iterator_rows+1);
            for (iterator_columns = 0; iterator_columns < graph->no_nodes; iterator_columns++ ){
                aux = get_adj_matrix_value(graph, iterator_rows, iterator_columns);
                if(aux==1)
                {
                    fprintf(test_out," %d", iterator_columns+1);
                }
            }
            fprintf (test_out,"\n");
            }

    }else{
        fprintf(test_out,"\nPlease read the adj_matrix first");
    }
}

void delete_graph(struct a_graph *graph){
    free(graph->adj_matrix);
    free(graph);
}

