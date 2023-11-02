clc
clear all
k = 1000;
po = 100;
r = 0.025;
A = log(k/po);
tm = k/2;
p = @(t) k*exp(-A*exp(-r*t)) - tm;
a = 40;
b= 50;

e = 1e-3;
itMax = 1e3;
[x, a, b, iter] = Bisseccao(a, b, p, e, e, itMax)
#Plotar Grafico
fplot(p, [0, 100]), grid

