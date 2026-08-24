import random
import time
import matplotlib.pyplot as plt


# Linear Search
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


# Binary Search
def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1


# Input sizes
sizes = [1000, 5000, 10000, 50000, 100000]

linear_times = []
binary_times = []


# Compare execution time
for n in sizes:

    # Generate random array
    arr = random.sample(range(1, 1000000), n)

    # Target at the last position
    target = arr[-1]

    # Binary search requires sorted array
    sorted_arr = sorted(arr)

    # Linear Search
    start = time.perf_counter()
    linear_search(arr, target)
    end = time.perf_counter()

    linear_times.append(end - start)

    # Binary Search
    start = time.perf_counter()
    binary_search(sorted_arr, target)
    end = time.perf_counter()

    binary_times.append(end - start)


# Display results
print("Input Size\tLinear Search\tBinary Search")

for i in range(len(sizes)):
    print(
        sizes[i],
        "\t\t",
        linear_times[i],
        "\t",
        binary_times[i]
    )


# Plot graph
plt.figure(figsize=(9, 5))

plt.plot(
    sizes,
    linear_times,
    marker="o",
    label="Linear Search"
)

plt.plot(
    sizes,
    binary_times,
    marker="o",
    label="Binary Search"
)

plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Linear Search vs Binary Search")

plt.legend()
plt.grid(True)

plt.show()


# Time Complexity
print("\nTime Complexity:")
print("Linear Search - Best: O(1), Average: O(n), Worst: O(n)")
print("Binary Search - Best: O(1), Average: O(log n), Worst: O(log n)")
