ch= int(input('1. (a)\n2. (b)\n3. (c)\n\nChoice: '))

#For part (a)
if ch==1:
    n = int(input('Enter number of teams : '))
    scores = {}
    for i in range(n):
        name = input('Enter team name : ')
        w = int(input('Enter wins : '))
        l = int(input('Enter losses : '))
        scores[name] = [w, l]

    t = input('Enter team name to find : ')
    print('winning percentage of', t, 'is', (scores[t][0]/sum(scores[t]))*100)

#For part (b)
if ch==2: 
    team = [i[0] for i in scores.values()]
    print(team)

#For part (c)
if ch==3: 
    rec = []
    for i in scores:
        if scores[i][0] > 0:
            rec.append(i)
    print(rec)

if ch==4:
    exit()

else:
    pass
