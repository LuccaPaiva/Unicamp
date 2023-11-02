#programa q recebe diametro e altura de cilindro, calcula seu volume
#com isso, ve se é possivel abastecer 3 postos
#Lucca Paiva ra240229
#inputs
d = float(input())
h = float(input())
a = float(input())
b = float(input())
c = float(input())
#volume
vol = ((d/2)**2) * 3.14 * h * 1000
#condicionais para verificar
if vol - a >= 0:
    print(f'posto A foi reabastecido')
    vol = vol - a
else:
    print(f'posto A nao foi reabastecido')
if vol - b >= 0:
    print(f'posto B foi reabastecido')
    vol = vol - b
else:
    print(f'posto B nao foi reabastecido')
if vol - c >=0:
    print(f'posto C foi reabastecido')
else:
    print(f'posto C nao foi reabastecido')