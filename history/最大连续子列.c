#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct MaxNumSub {
	int max;//最大数
	int subscript;//子列中最后的下标
	struct MaxNumSub *next;
};

struct MaxNumSub *maxSubArray(int *nums, int numsSize);
struct MaxNumSub *newMaxSub(int maxAns, int subscript);
void printMaxSub(int *nums);

int numsMax;
struct MaxNumSub *head = NULL;

int main(void)
{
	int K = 0;

	scanf("%d", &K);
	int nums[K];
	for(int i = 0; i < K; i++) {
		scanf("%d", nums + i);
	}

	struct MaxNumSub *q = maxSubArray(nums, K);

	printMaxSub(nums);

	return 0;
}

struct MaxNumSub *maxSubArray(int *nums, int numsSize)
{
	int pre = 0, maxAns = nums[0];
	struct MaxNumSub *p = NULL;
	numsMax = nums[0];
	for(int i = 0; i < numsSize; i++) {
		pre = fmax(pre + nums[i], nums[i]);
		maxAns = fmax(maxAns, pre);
		if(!(maxAns - pre)) {
			if(numsMax < maxAns) {
				numsMax = maxAns;
			}
			if(!i) {
				head = p = newMaxSub(maxAns, i);
			} else {
				p->next = newMaxSub(maxAns, i);
				p = p->next;
			}
		}
	}

	return head;
}

void printMaxSub(int *nums)
{
	struct MaxNumSub *p = head;
	while(p != NULL) {
		if(p->max == numsMax) {
			printf("%d =", numsMax);
			for(int i = 0,sum = 0; sum != numsMax; i++) {
				sum += nums[p->subscript - i];
				printf(" %d", nums[p->subscript - i]);
			}
			printf("\n");
		}
		p = p->next;
	}
}

struct MaxNumSub *newMaxSub(int maxAns, int subscript)
{
	struct MaxNumSub *new = malloc(sizeof(struct MaxNumSub));
	new->max = maxAns;
	new->subscript = subscript;
	new->next = NULL;

	return new;
}