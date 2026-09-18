import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Solution {
	public int[] twoSum_brute(int[] nums, int target) {
		for (int i = 0; i < nums.length - 1; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (nums[i] + nums[j] == target) {
					return new int[] {i, j};
				}
			}
		}
		return new int[0];
	}

	public int[] twoSum_hashmap(int[] nums, int target) {
		Map<Integer, Integer> numMap = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int complement = target - nums[i];
			if (numMap.containsKey(complement)) {
				return new int[] {numMap.get(complement), i};
			}
			numMap.put(nums[i], i);
		}
		return new int[0];
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter list length: ");
		int n = scanner.nextInt();
		int[] nums = new int[n];

		for (int i = 0; i < n; i++) {
			System.out.printf("Enter number %d of %d: ", i, n - 1);
			nums[i] = scanner.nextInt();
		}

		System.out.print("Enter target: ");
		int target = scanner.nextInt();
		Solution solution = new Solution();
		System.out.println(java.util.Arrays.toString(solution.twoSum_brute(nums, target)));
		System.out.println(java.util.Arrays.toString(solution.twoSum_hashmap(nums, target)));
		scanner.close();
	}
}