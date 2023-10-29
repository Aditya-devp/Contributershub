import time
from hashlib import sha256
string = input("Enter sometihing to calculate its hash: ")
print(f"The hash of {string} is {sha256(string.encode('ascii')).hexdigest()}")