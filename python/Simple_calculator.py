#input two numbers from the user
a= int(input("enter first number= "))
b= int(input("enter second number= "))

print("1. Addition ")
print("2. Subtraction ")
print("3. Multiplication")
print("4. Division")

#choose one at a time from above options
ch=int(input("enter your choice= "))

#ch value should store value between 1 to 4
if(ch>=1 and ch<=4):
  if(ch==1):
    print(a+b)
  elif(ch==2):
    print(a-b)
  elif(ch==3):
    print(a*b)
  else:
    print(a/b)
else:
  print("wrong choice")
