''' link to standard credit cards 
https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards'''

# TODO
# AMEX 34 37
# VISA 4
# Master Card 51, 52, 53, 54, or 55

number = input("Number: ")
temp = list(number)
length = len(temp)
sum = 0


for i in range(length - 2, -1, -2):
    newlist = []
    newlist.append(int(temp[i]) * 2)
    for i in newlist:
        if len(str(i)) == 1:
            sum += i
        else:
            for j in str(i):
                sum += int(j)

for i in range(length - 1, -1, -2):
    sum += int(temp[i])


if length == 13 or length == 15 or length == 16:
    if sum % 10 == 0:
        if number[0] == "4":
            print("VISA\n")
        elif number[0] == "5" and number[1] in ["1", "2", "3", "4", "5"]:
            print("MASTERCARD\n")
        elif number[0] == "3" and number[1] in ["4", "7"]:
            print("AMEX\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


else:
    print("INVALID\n")