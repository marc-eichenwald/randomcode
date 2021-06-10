#include <stdlib.h>

typedef struct node{
    int value;
    node *left;
    node *right;
}node;

int maxdepth(node *head){
    int max;
    int left = 1;
    int right = 1;
    if (head == NULL)
        return 0;
    else{
        left += maxdepth(head->left);
        right += maxdepth(head->right);
        if (left < right)
            max = right;
        else 
            max = left;
    }
    return max;
}
