import sys

try:
    n = int(input('Enter a number in decimal notation: '))
except (ValueError, KeyboardInterrupt):
    print('Invalid Input')
    sys.exit()
hexx = {'0': '0', '1': '1', '2': '2', '3': '3', '4': '4', '5': '5', '6': '6', '7': '7',
        '8': '8', '9': '9', '10': 'A', '11': 'B', '12': 'C', '13': 'D', '14': 'E', '15': 'F'}

while True: #Menu driven program
    choice = int(input('''=======DECIMAL CONVERTOR=======\n\t1. To Binary\n\t2. To Octahedral\n\t3. To Hexadecimal\n\n'''"Enter choice: "))
    def base(num, base):
        i = ''
        k = ''
        while num != 0:
            r = num % base
            num = num//base
            i += hexx[str(r)]
        for j in range(len(i)):
            k += i[-j-1]
        print(k)
    #Calling functions by choice 
    if choice == 1:
        print('\nBinary is', end=' ')
        base(n, 2)
    elif choice == 2:
        print('Octal is', end=' ')
        base(n, 8)
    elif choice == 3: 
        print('Hexadecimal is', end=' ')
        base(n, 16)
    elif choice == 4:
        exit()
    else:
        print('Invalid input!')
        pass
        
    while True: #Checking for other bases
        ch = input('\nDo you want to convert to another base(y/n)?\t')
        if ch=='n' or ch=='N' or ch=='NO' or ch=='No':
            sys.exit()
        elif ch=='y' or ch=='Y' or ch=='YES' or ch=='yes':
            try:
                b = int(input('Enter the base:\t'))
                print('Base', b, 'equivalent is', end=' ')
                base(n, b)
            except (ValueError, KeyboardInterrupt):
                print('Invalid Input')
                pass
        else:
            print('Invalid Input')
            pass
