#include <stdio.h>
#define MAX 100
struct Element {
    int row;
    int col;
    int val;
};
int toTriplet(int matrix[MAX][MAX], int r, int c, struct Element sparse[]) {
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0].row = r;
    sparse[0].col = c;
    sparse[0].val = k - 1;
    return k - 1;
}
void addSparse(struct Element s1[], struct Element s2[], struct Element result[]) {
    if (s1[0].row != s2[0].row || s1[0].col != s2[0].col) {
        printf("Matrices dimensions do not match. Addition impossible.\n");
        return;
    }
    int i = 1, j = 1, k = 1;
    while (i <= s1[0].val && j <= s2[0].val) {
        if (s1[i].row < s2[j].row || (s1[i].row == s2[j].row && s1[i].col < s2[j].col)) {
            result[k++] = s1[i++];
        } else if (s1[i].row > s2[j].row || (s1[i].row == s2[j].row && s1[i].col > s2[j].col)) {
            result[k++] = s2[j++];
        } else {
            result[k].row = s1[i].row;
            result[k].col = s1[i].col;
            result[k].val = s1[i].val + s2[j].val;
            i++; j++;
            if (result[k].val != 0) k++;
        }
    }
    while (i <= s1[0].val) result[k++] = s1[i++];
    while (j <= s2[0].val) result[k++] = s2[j++];

    result[0].row = s1[0].row;
    result[0].col = s1[0].col;
    result[0].val = k - 1;
}
void display(struct Element s[]) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= s[0].val; i++) {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
    }
}
int main() {
    int r, c, m1[MAX][MAX], m2[MAX][MAX];
    struct Element s1[MAX], s2[MAX], result[MAX];
    printf("Enter dimensions (rows columns): ");
    scanf("%d %d", &r, &c);
    printf("Enter Matrix 1 elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &m1[i][j]);
    printf("Enter Matrix 2 elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &m2[i][j]);
    toTriplet(m1, r, c, s1);
    toTriplet(m2, r, c, s2);
    addSparse(s1, s2, result);
    printf("\nConsolidated Sparse Dataset (Triplet Form):\n");
    display(result);
    return 0;
}
