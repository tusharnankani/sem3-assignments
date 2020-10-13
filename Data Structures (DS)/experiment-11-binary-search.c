#include<stdio.h>
#include<stdlib.h>

void binarysearch(int *a, int start, int end, int target)
{
    if(end < start)
    {
        printf("\nArray does not contain the target element.");
        return;
    }
    int mid = (start + end) / 2;
    if(a[mid]==target)
    {
        printf("\nElement %d found at location %d.", target, mid + 1);
        return;
    }
    else if(a[mid] > target)
        //new end would be mid-1, because target in the lower half
        binarysearch(a, start, mid - 1, target);
    else
        //new start would be mid+1, because target in upper half
        binarysearch(a, mid + 1, end, target);
}

void sort(int *a, int n)
{
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nThe sorted array is: \t");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void main()
{
    int length, i, target;
    printf("\nEnter the length of array:   ");
    scanf("%d", &length);
    int a[length];
    printf("Enter %d elements of the array:  ", length);
    for(i = 0; i < length; i++)
        scanf("%d", &a[i]);

    // sorting if the array is not sorted;
    sort(&a, length);

    printf("\nNow, Enter target element : ");
    scanf("%d",&target);
    // Recursive Approach;
    binarysearch(a, 0 , length, target);
}
