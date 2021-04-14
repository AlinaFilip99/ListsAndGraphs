#ifndef CODE_SKELETON_GRPAPHS_GRAPHS_H
#define CODE_SKELETON_GRPAPHS_GRAPHS_H

struct a_graph {
    int no_nodes;
    int init;
    int *adj_matrix;
};

void set_adj_matrix_value(struct a_graph *graph, int row_index, int column_index, int element_value);
int get_adj_matrix_value(struct a_graph *graph, int row_index, int column_index);
void init_graph(struct a_graph *graph, int n, int m, int r);
void print_file(struct a_graph *graph, int i, int atac, int aparare);
void delete_graph(struct a_graph *graph);

#endif //CODE_SKELETON_GRPAPHS_GRAPHS_H
