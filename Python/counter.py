import os

with open(os.getcwd() +'/DSA/countin.txt', 'r') as in_file:
    number = int(in_file.read())

with open(os.getcwd() +'/DSA/countout.txt', 'w') as out_file:
    for i in range(1,number+1):
        out_file.write(str(i) + '\n')