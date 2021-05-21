#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define null -1

int* tree = NULL;
bool* picked = NULL;

void findLeft(int preOrder[], int inOrder[], int root, int low) {
    int left;
    for (int i = root + 1; ; i++)
        if (!picked[preOrder[i]]) {
            left = preOrder[i];
            break;
        } 

    for (int i = low; i < root; i++)
        if (inOrder[i] == left) {
            tree[2*root + 1] = left;
            picked[left] = true;
            findLeft(preOrder, inOrder, i, low);
            break;
        }
}

int main() {
    int n;  scanf("%d", &n);

    int preOrder[n], inOrder[n];
    picked = (bool*)calloc(n + 1, sizeof(bool));

    for (int i = 0; i < n; i++)
        scanf("%d", &preOrder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &inOrder[i]);
    
    tree = (int*)malloc((2*n + 2)*sizeof(int));

    free(tree);
}