#include <stdio.h>
#include <math.h>

struct MaxNumSub {
	int max;//最大数
	int subscript;//子列中最后的下标
	struct MaxNumSub *next;
};

int maxSubArray(int *nums, int numsSize);
struct MaxNumSub *newMaxSub(int maxAns, int subscript);

int main(void)
{
	int K = 0;

	scanf("%d", &K);
	int nums[K];
	for(int i = 0; i < K; i++) {
		scanf("%d", nums + i);
	}

	int result = maxSubArray(nums, K);

	printf("%d", result);

	return 0;
}

int maxSubArray(int *nums, int numsSize)
{
	int pre = 0, maxAns = nums[0];
	int max = nums[0];
	struct MaxNumSub *p = NULL;
	for(int i = 0; i < numsSize; i++) {
		pre = fmax(pre + nums[i], nums[i]);
		maxAns = fmax(maxAns, pre);
		if(!(maxAns - pre)) {
			p = newMaxSub(maxAns, i);
		}
	}

	return maxAns;
}

void printMaxSub()
{

}

struct MaxNumSub *newMaxSub(int maxAns, int subscript)
{
	struct MaxNumSub *new = malloc(sizeof(struct MaxNumSub));
	new->max = maxAns;
	new->subscript = subscript;

	return new;
}