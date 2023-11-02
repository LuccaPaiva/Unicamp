clc
clear all

N = 10 % Número de sub-intervalos deve ser par.
a = 1.8;
b = 2;
M = 300;
u = 1.7;
sig = 0.1;

f = @(x) M*exp(-(x - u).^2/(2*(sig^2)))/(sig*sqrt(2*pi));

t = linspace(a,b,N+1);
h=(b-a)/N;

t1 = linspace(1, 2.5, 100);
y = f(t1);

I = (h/3)*(f(t(1)) + 4*sum(f(t(2:2:N))) + 2*sum(f(t(3:2:N-1))) + f(t(N+1)))




e = @(x) exp(-50*(x - 1.7).^2)*(1.19683*(10^11)*(x.^4) - 8.13842*(10^11)*(x.^3)
 + 2.06812*(10^12)*(x.^2) - 2.32759*(10^12)*x + 9.78885*(10^11))';

y = e(t)
max(abs(y))
erro = max(abs(y))*h^4*(b - a)/180




#plot(t1, y, 'linewidth', 8);
#leg = legend("Funcao N");
#set(leg, "fontsize", 20);