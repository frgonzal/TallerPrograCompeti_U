registro = input()

A, B = 0, 0
for i in range(0,len(registro),2):
    if registro[i] == "A":
        A += int(registro[i+1]) 
    else:
        B += int(registro[i+1]) 

if A > B:
    print("A")
else:
    print("B")
