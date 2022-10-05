# Stack operations using a list

st = []
r = []

def push():
    print('--STACK--')
    x = int(input('Book_No: '))
    y = input('Book_Name: ')
    r = [x, y]
    st.append(r)

def display():
    if len(st) > 0:
        for i in range(len(st)-1, -1, -1):
            print(st[i])
    else:
        print('Underflow')

def pop():
    if st[0] == ():
        print('Underflow!')
    else:
        p = int(input('Index of element to pop: '))
        if p > len(st):
            print('Index out of range')
        else:
            st.pop(p)
            print(f'Element popped is {r} from {st} with position {p}')

while True:
    ch = int(input('Enter choice: '))
    if ch == 1:
        m = int(input('Enter no. of elements: '))
        for i in range(m):
            push()
    elif ch == 2:
        display()
    elif ch == 3:
        pop()
    elif ch == 4:
        exit()
    else:
        print('Invalid choice!')
