#include <stdio.h>

int bin_search(int A[], int n, int target) {
int left = 0;
int right = n - 1;

while (left <= right) {
int mid = (left + right) / 2;

if (target == A[mid]) {
return mid; // Target found, return its position
} 
else if (target < A[mid]) {
right = mid - 1; // Target is in the left half
} else {
left = mid + 1; // Target is in the right half
}

}
return -1; // Element not found in the array
}


int main() {

int n, target;
printf("Enter the size of the array: ");
scanf("%d", &n);

int A[n];
printf("Enter the sorted array elements:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &A[i]);
}

printf("Enter the value to search: ");
scanf("%d", &target);

int result = bin_search(A, n, target);

if (result != -1) {
printf("Value %d found at position %d in the array.\n", target, result);
} else {
printf("Value %d not found in the array.\n", target);
}

return 0;

}