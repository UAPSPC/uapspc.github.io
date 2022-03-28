#!/usr/bin/python3
a,b=input().split()
print('{{:0{}b}}'.format(len(a)).format(int(a[::-1].replace("A","0").replace("B","1"),2)+int(b))[::-1].replace("0","A").replace("1","B"))
