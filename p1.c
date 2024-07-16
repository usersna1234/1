#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target);
int main() {
    int n, target;
    printf("Enter number of elements and sorted integers:\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search for: ");
    scanf("%d", &target);
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) 
    printf("Element %d found at index %d.\n", target, index);
    else printf("Element %d not found.\n", target);
    return 0;
}
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) 
    return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) 
    return mid;
    else if (arr[mid] > target) 
    return binarySearch(arr, left, mid - 1, target);
    else return binarySearch(arr, mid + 1, right, target);
}
