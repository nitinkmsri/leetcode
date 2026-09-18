#include <stdio.h>
#include <stdlib.h>

/* Find two indices whose values add up to target using brute force. */
void twoSum(const int *nums, int numsSize, int target, int result[2]) {
	result[0] = -1;
	result[1] = -1;

	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				return;
			}
		}
	}
}

/* Find two indices whose values add up to target using a simple hash table. */
void twoSumHashmap(const int *nums, int numsSize, int target, int result[2]) {
	int capacity = numsSize * 2 + 1;
	int *keys = malloc((size_t)capacity * sizeof(*keys));
	int *indices = malloc((size_t)capacity * sizeof(*indices));
	char *used = calloc((size_t)capacity, sizeof(*used));

	result[0] = -1;
	result[1] = -1;
	if (keys == NULL || indices == NULL || used == NULL) {
		free(keys);
		free(indices);
		free(used);
		return;
	}

	for (int i = 0; i < numsSize; i++) {
		int complement = target - nums[i];
		unsigned int hash = (unsigned int)complement;
		int slot = (int)(hash % (unsigned int)capacity);

		while (used[slot]) {
			if (keys[slot] == complement) {
				result[0] = indices[slot];
				result[1] = i;
				free(keys);
				free(indices);
				free(used);
				return;
			}
			slot = (slot + 1) % capacity;
		}

		hash = (unsigned int)nums[i];
		slot = (int)(hash % (unsigned int)capacity);
		while (used[slot] && keys[slot] != nums[i]) {
			slot = (slot + 1) % capacity;
		}
		keys[slot] = nums[i];
		indices[slot] = i;
		used[slot] = 1;
	}

	free(keys);
	free(indices);
	free(used);
}

int main(void) {
	int n;
	printf("Enter list length: ");
	if (scanf("%d", &n) != 1 || n < 0) {
		return 1;
	}

	int *nums = malloc((size_t)n * sizeof(*nums));
	if (nums == NULL && n > 0) {
		return 1;
	}

	for (int i = 0; i < n; i++) {
		printf("Enter number %d of %d: ", i, n - 1);
		if (scanf("%d", &nums[i]) != 1) {
			free(nums);
			return 1;
		}
	}

	int target;
	printf("Enter target: ");
	if (scanf("%d", &target) != 1) {
		free(nums);
		return 1;
	}

	int result[2];
	int hashmapResult[2];
	twoSum(nums, n, target, result);
	twoSumHashmap(nums, n, target, hashmapResult);

	printf("twoSum: [");
	if (result[0] != -1) {
		printf("%d, %d", result[0], result[1]);
	}
	printf("]\n");

	printf("twoSum_hashmap: [");
	if (hashmapResult[0] != -1) {
		printf("%d, %d", hashmapResult[0], hashmapResult[1]);
	}
	printf("]\n");

	free(nums);
	return 0;
}
