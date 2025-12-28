def bubble_sort(my_list):
    n = len(my_list)
    for i in range(n):
        for j in range(0, n - i - 1):
            if my_list[j] > my_list[j + 1]:
                my_list[j], my_list[j + 1] = my_list[j + 1], my_list[j]
    return my_list
  
my_list = [64, 34, 25, 12, 22, 11, 90]

bubble_sort(my_list)

print("Отсортированный массив:", my_list)
