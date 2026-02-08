#include <stdio.h>
#define MAX 100
typedef struct {
    int row;
    int col;
    int val;
} Term;
int toTriplet(int mat[MAX][MAX], int r, int c, Term triplet[]) {
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                triplet[k].row = i;
                triplet[k].col = j;
                triplet[k].val = mat[i][j];
                k++;
            }
        }
    }
    triplet[0].row = r;
    triplet[0].col = c;
    triplet[0].val = k - 1;
    return k - 1;
}
void transpose(Term a[], Term b[]) {
    int n = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;
    if (n > 0) {
        int currentB = 1;
        for (int i = 0; i < a[0].col; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[currentB].row = a[j].col;
                    b[currentB].col = a[j].row;
                    b[currentB].val = a[j].val;
                    currentB++;
                }
            }
        }
    }
}
void displayTriplet(Term t[]) {
    printf("\nRow\tCol\tValue\n");
    printf("--------------------------\n");
    for (int i = 0; i <= t[0].val; i++) {
        printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
    }
}
int main() {
    int r, c, mat[MAX][MAX];
    Term triplet[MAX], transposed[MAX];
    printf("Enter dimensions of the web page matrix (rows cols): ");
    scanf("%d %d", &r, &c);
    printf("Enter the adjacency matrix (0 for no link, 1 for link):\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
    toTriplet(mat, r, c, triplet);
    printf("\n--- Original Triplet Representation ---");
    displayTriplet(triplet);
    transpose(triplet, transposed);
    printf("\n--- Transposed Triplet Representation ---");
    displayTriplet(transposed);
    return 0;
}
