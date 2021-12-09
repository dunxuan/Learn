#include <iostream>

using namespace std;

int findKthLargest(int S[], int K);

int main(void)
{
	int testArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int testMedian = findKthLargest(testArray, )

	return 0;
}

int findKthLargest(int S[], int K)
{
	int e = S[0];
	int lengthOfArrayS = sizeof(S) / sizeof(*S);
	int S1[lengthOfArrayS] = {0};
	int S2[lengthOfArrayS] = {0};
	int lengthOfArrayS1 = 0;
	int lengthOfArrayS2 = 0;

	for (int i = 0; i < lengthOfArrayS; ++i)	{
		if (S[i] <= e)	{
			S1[lengthOfArrayS1] = S[i];
			lengthOfArrayS1++;
		} else	{
			S2[lengthOfArrayS2] = S[i];
			lengthOfArrayS2++;
		}
	}
	if (lengthOfArrayS1 >= K)	{
		return findKthLargest(S1, K);
	} else if (lengthOfArrayS1 < K - 1)	{
		return findKthLargest(S2, K - lengthOfArrayS1 - 1);
	} else	{
		return e;
	}
}