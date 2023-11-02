f = @(t, y) (1 + 0.5*cos(2*pi*t))*(1 - y/(1 + 0.5*sin(3*pi*t/2)));

[X1, Y1, sol] = RK4(f, 0, 0.4, 0.125, 80);
[X2, Y2] = Heun(f, 0.03125/2, [0 10], 0);

plot(sol,'linewidth', 2);#Azul
hold;
plot( X2.*8, Y2, 'linewidth', 2);#Vermelho

sol(80)
Y2(641)