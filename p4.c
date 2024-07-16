#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 30000
int partition(int a[], int low, int high) {
    int pivot = a[low], i = low + 1, j = high, temp;
    while (1) {
        while ((a[i] <= pivot) && (i < high)) i++;
        while ((a[j] > pivot) && (j >= low)) j--;
        if (i < j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        } else {
            temp = a[low]; a[low] = a[j]; a[j] = temp;
            return j;
        }
    }
}
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}
int main() {
    int a[MAXSIZE], nk, i;
    clock_t start, end;
    double runtime = 0;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &nk);
    for (i = 0; i < nk; i++) {
        a[i] = rand() % 1000;
    }
    start = clock();
    quicksort(a, 0, nk - 1);
    end = clock();
    runtime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted elements:\n");
    for (i = 0; i < nk; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Time taken for sorting is %0.6lf seconds\n", runtime);
    return 0;
}
