scores = {}

def push():
    n = int(input('Enter number of teams : '))
    for i in range(n):
        name = input('Enter team name : ')
        w = int(input('Enter wins : '))
        l = int(input('Enter losses : '))
        scores[name] = [w, l]

    t = input('Enter team name to find : ')
    print('winning percentage of', t, 'is', (scores[t][0]/sum(scores[t]))*100)

def foo():
    team = [i[0] for i in scores.values()]
    print(team)

while True:
    ch= int(input('1. (a)\n2. (b)\n3. (c)\n\nChoice: '))
    if ch==1:
        push()

    elif ch==2: 
        foo()
    
    else:
        exit()
