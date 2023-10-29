import sys

n = int(input("Enter a 3 digit number: "))
k = int(input("Enter the value of k(2 or 3): "))
l=[int(a) for a in str(n)]
l1=[]

if(k==2):
  for i in l:
    for j in l:
        c = str(i) + str(j)
        l1.append(c)
elif(k==3):
  for i in l:
    for j in l:
      for k in l:
        for i in l:
          c = str(i) + str(j) + str(k)
          l1.append(c)
else:
  print("Wrong value of k. Try again.")
  sys.exit(0)

for i in range (0,len(l1),1):
  for j in range (i+1,len(l1),1):
    if l1[i]==l1[j]:
      l1[j]='repetition'

for i in range (0,len(l1),1):
  if (l1[i]!= 'repetition'):
    print(l1[i])
