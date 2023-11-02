#programa que le 4 valores, e ve se e possivel soma-los de determinada forma que eles fiquem equivalentes
#Lucca Paiva RA240229
lista = []
for c in range(0, 4):
    lista.append(int(input()))
lista = sorted(lista)
if (lista[0] + lista[3] == lista[1] + lista[2]) or (lista[0] + lista[1] + lista[2] == lista[3]):
    print('sim')
else:
    print('nao')