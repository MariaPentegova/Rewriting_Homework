def do_eratosthenes(n):
    numbers = [True] * (n + 1) #все числа изначально простые
    numbers[0] = False  
    numbers[1] = False 

    for i in range(2, n + 1):
        if numbers[i]==True:
            for j in range(i*i, n + 1, i):
                numbers[j] = False

    for i in range(2, n + 1):
        if numbers[i]:
            print(i, end=' ')

num = int(input("Enter the number: "))
do_eratosthenes(num)
