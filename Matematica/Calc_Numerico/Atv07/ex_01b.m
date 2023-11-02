clc
clear all
e = @(x) exp(-50*(x - 1.7).^2)*(1.19683*(10^11)*(x.^4) - 8.13842*(10^11)*(x.^3)
 + 2.06812*(10^12)*(x.^2) - 2.32759*(10^12)*x + 9.78885*(10^11))';
a = 1.8;
b = 2;
N = 10;
t = linspace(a, b, N+1);
y = e(t)
plot(t, y)
max(y)
h = (b-a)/N
erro = max(abs(y))*h^4*(b - a)/180