//PARTITION PROBLEM USING RECURSION
#include <stdio.h>

int isSubsetSum(int a[], int n, int sum)
{
	// Base Cases
	if (sum == 0)
		return 1;
	if (n == 0 && sum != 0)
		return 0;

	// If last element is greater than sum, then ignore it
	if (a[n - 1] > sum)
		return isSubsetSum(a, n - 1, sum);

	/* else, check if sum can be obtained by
		(a) including the last element
		(b) excluding the last element*/
	return isSubsetSum(a, n - 1, sum)
		|| isSubsetSum(a, n - 1, sum - a[n - 1]);
}

int check(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];

	// If sum is odd, there cannot be two subsets with equal sum
	if (sum % 2 != 0)
		return 0;

	// Find if there is subset with sum equal to half of total sum
	return isSubsetSum(a, n, sum / 2);
}

// Driver code
void main()
{
	int a[20],n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
	if (check(a, n))
		printf("Can be divided into two subsets of equal sum\n");
	else
		printf("Cannot be divided into two subsets of equal sum\n");
}
