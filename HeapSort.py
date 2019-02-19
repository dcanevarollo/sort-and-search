from random import *
# You can better understand what's going on here accessing:
# https://www.geeksforgeeks.org/heap-sort/


# Method called to maintain the heap structure on the tree/array
def heapify(array, size, i):
    largest = i
    left = 2*i+1
    right = 2*i+2

    # Checks if the left root exists and if it's greater than root
    if left < size and array[i] < array[left]:
        largest = left

    # Checks if the right root exists and if it's greater than root
    if right < size and array[largest] < array[right]:
        largest = right

    # Change the root if needed
    if largest != i:
        # Swap the values
        array[i], array[largest] = array[largest], array[i]

        # Recursively heapfys the new root
        heapify(array, size, largest)


# Main method called to sort the array
def heapsort(array):
    size = len(array)

    # Creates a max heap tree
    for i in range(size, -1, -1):
        heapify(array, size, i)

    # Extracts the elements in the array, one by one.
    # That elements will be ordered cause the heap structure let the max values
    # on the first entry of the array.
    for i in range(size-1, 0, -1):
        # Swap the i element (last one) with the first (largest)
        array[i], array[0] = array[0], array[i]
        heapify(array, i, 0)  # To maintain the heap structure after the swap


if __name__ == "__main__":
    print("Default array\n>", end=' ')
    array = []
    for _ in range(20):
        array.append(randint(0, 20))
        print(array[-1], end=' ')

    heapsort(array)

    size = len(array)
    print("\n\nSorted array\n>", end=' ')
    for i in range(size):
        print("%i" % array[i], end=' ')
