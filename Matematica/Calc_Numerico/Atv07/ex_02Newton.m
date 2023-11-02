clear all
clc
x = [1 2 3 4 5]'
n = 5
y = [1 1 2 6 24]'



T = TabelaDifDiv(x, y);

pre = output_precision(10);

([x,T])

P2 = @(k)  1 + 0*(k - 1) + 0.5*(k - 1)*(k - 2) + (1/3)*(k - 1)*(k - 2)*(k - 3) + 0.375*(k - 1)*(k - 2)*(k - 3)*(k - 4);

Erro = @(k) (1/3)*(k - 0)*(k - 1)*(k - 2)*(k - 3);

t = linspace(0,5, 100);
z1 = gamma(t);

z2 = zeros(1, 100);
for i = 1:100
  z2(1, i) = P2(t(i));
 endfor

x = [1 2 3 4 5]
y = [1 1 2 6 24]
z3 = spline(x, y, t);
b = spline(x, y);
b

plot(t, z1, 'linewidth', 8, t, z2, 'linewidth', 6, 
t, z3, 'linewidth', 4, x, y, 'o', 'linewidth', 8)


tit = title("Interpolacao dos Pontos");
yl = ylabel ("Eixo y");
xl = xlabel("Eixo x");
leg = legend("Gamma", "Polinomio", "Spline", "Pontos Base", "location", "northwest");


set (yl, "fontsize", 30);
set (xl, "fontsize", 30);
set (tit, "fontsize", 40);
set(leg, "fontsize", 30);










