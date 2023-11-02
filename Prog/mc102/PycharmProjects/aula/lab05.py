t = int(input())
c = int(input())
a = input()
b = []
s = []
for num in a.strip().split():
    b.append(int(num))
s.append(0)
for cont in range(0, t):
    s.append(s[cont] + b[cont])
    if s[cont + 1] >= c:
        print('sim')
        print(cont + 1)
        quit()
print('nao')
print(t + 1)
