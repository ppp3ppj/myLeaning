#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, arr[20], sum = 0;
    float mean = 0.0;
    system("clear");
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++)
        sum += arr[i];
    mean = (float)sum/n;
    printf("\n The sum of the array elements = %d", sum);
    printf("\n The mean of the array of the array elements = %.2f", mean);
    return 0;
}
