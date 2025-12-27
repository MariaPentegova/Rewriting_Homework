import pytest
import random

def heapify(nums, heap_size, root_index):  
    largest = root_index
    l_child = (2 * root_index) + 1
    r_child = (2 * root_index) + 2

    if l_child < heap_size and nums[l_child] > nums[largest]:
        largest = l_child

    if r_child < heap_size and nums[r_child] > nums[largest]:
        largest = r_child

    if largest != root_index:
        nums[root_index], nums[largest] = nums[largest], nums[root_index]
        heapify(nums, heap_size, largest)

def heap_sort(nums):  
    n = len(nums)
    
    for i in range(n, -1, -1):
        heapify(nums, n, i)

    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0)

def test_empty():
    arr = []
    heap_sort(arr)
    assert arr == []

def test_single_element():
    arr = [42]
    heap_sort(arr)
    assert arr == [42]

def test_sorted_array():
    arr = [1, 2, 3, 4, 5]
    heap_sort(arr)
    assert arr == sorted(arr)

def test_reverse_sorted_array():
    arr = [5, 4, 3, 2, 1]
    heap_sort(arr)
    assert arr == sorted(arr)
    
def test_duplicates():
    arr = [2, 3, 2, 1, 3, 1]
    heap_sort(arr)
    assert arr == sorted(arr)

def test_all_equal():
    arr = [7, 7, 7, 7]
    heap_sort(arr)
    assert arr == [7, 7, 7, 7]

def test_negative_numbers():
    arr = [-3, -1, -7, 4, 0]
    heap_sort(arr)
    assert arr == sorted(arr)
    
def test_large_array():
    arr = list(range(1000, 0, -1))
    expected = list(range(1, 1001))
    heap_sort(arr)
    assert arr == expected

def test_random_arrays():
    for _ in range(10):
        size = random.randint(0, 1000)
        arr = [random.randint(-10000, 10000) for _ in range(size)]
        arr_copy = arr[:]
        heap_sort(arr)
        assert arr == sorted(arr_copy)
