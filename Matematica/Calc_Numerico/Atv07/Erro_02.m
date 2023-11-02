clear all
clc
x = [1 2 3 4 5]'
n = 5
y = [1 1 2 6 24]'

pre = output_precision(10);

P2 = @(k)  1 + 0*(k - 1) + 0.5*(k - 1)*(k - 2) + (1/3)*(k - 1)*(k - 2)*(k - 3) + 0.375*(k - 1)*(k - 2)*(k - 3)*(k - 4);

Erro = @(k) (1/3)*(k - 0)*(k - 1)*(k - 2)*(k - 3);

lim = 1000;

t = linspace(1,5, lim);

z2 = zeros(1, lim);
for i = 1:lim
  z2(1, i) = P2(t(i));
 endfor
z3 = spline(x, y, t);

R = gamma(t);
e1 = abs(R - z2);
e2 = abs(R - z3);

erro_medio_Newton = mean(e1)
erro_medio_Spline = mean(e2)
erro_max_Newton = max(e1)
erro_max_Spline = max(e2)

plot(t, e1, 'linewidth', 6, t, e2, 'linewidth', 6)
leg = legend("Erro Polinomio", "Erro Spline", "location", "northwest");
tit = title("Erro das Funcoes");

set (tit, "fontsize", 40);
set(leg, "fontsize", 30);