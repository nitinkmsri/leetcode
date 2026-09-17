

class solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # Check every possible first number except the final one.
        for i in range(len(nums)-1):
            # Compare the number at index i with each following number.
            for j in range(i+1,len(nums)):
                # Add the two selected numbers together.
                a =nums[i] + nums[j]
                # If their sum matches the target, return both indices.
                if a == target:
                    A = [i,j]
                    return A


if __name__ == "__main__":
    # Ask the user how many numbers will be entered.
    n = int(input("Enter list length: "))
    # Read each number individually so the list contains exactly n values.
    nums = []
    for i in range(n):
        nums.append(int(input(f"Enter number {i} of {n-1}: ")))
    # Ask for the sum that the two numbers must equal.
    target = int(input("Enter target: "))
    # Run the two-sum algorithm and display the returned indices.
    print(solution().twoSum(nums, target))