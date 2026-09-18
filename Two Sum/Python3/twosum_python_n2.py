

class solution:
    def twoSum_brute(self, nums: list[int], target: int) -> list[int]:
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
    def twoSum_hashmap(self, nums: list[int], target: int) -> list[int]:
        # Create a dictionary to store the numbers and their indices.
        num_dict = {}
        # Iterate through the list of numbers.
        for i, num in enumerate(nums):
            # Skip values already stored in the dictionary.
            complement = target - num
            # Check if the complement is already in the dictionary.
            if complement in num_dict:
                # If found, return the indices of the two numbers.
                return [num_dict[complement], i]
            # Store the current number and its index in the dictionary.
            num_dict[num] = i


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
    print(solution().twoSum_brute(nums, target))
    print(solution().twoSum_hashmap(nums, target))