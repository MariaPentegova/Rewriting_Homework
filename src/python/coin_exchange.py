num = int(input('Enter the number: '))

nominal_1 = len('Pentegova')
nominal_2 = len('Maria')
nominal_3 = len('Sergeevna')

for i_1 in range(num // nominal_1 + 1):
    for i_2 in range(num // nominal_2 + 1):
        for i_3 in range(num // nominal_3 + 1):
            if i_1 * nominal_1 + i_2 * nominal_2 + i_3 * nominal_3 == num:
                print(i_1,'*',nominal_1,'+',i_2,'*',nominal_2,'+',i_3,'*',nominal_3)
                exit()  
print("-42!")
