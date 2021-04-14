#ifndef CODE_LIST
#define CODE_LIST

struct g_node{
    int info;
    struct g_node *next;
};

void push_element_end(struct g_node *head ,int new_element_value);
int pop_element_at_position(struct g_node *head, int position);

#endif //CODE_LIST
