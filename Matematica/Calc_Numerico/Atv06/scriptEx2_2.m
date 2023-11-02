clear all
clc
x = [28 35 49 56]'

n = 4

y = [2294 2821 3118 2899]'

P = polyfit(x,y,length(x));

T = TabelaDifDiv(x, y);

pre = output_precision(10);

([x,T])

P2 = @(k)  2294 + 75.2857142857*(k - 28) + -2.5748299320*(k - 28)*(k - 35) + 0.0026724976*(k - 28)*(k - 35)*(k - 49);

Erro = @(k) 0.0026724976*(k - 28)*(k - 35)*(k - 49);

r1 = polyval(P, 42)
r2 = P2(42)

E = Erro(42)

t1 = linspace(0,56);
z1 = polyval(P,t1);

t2 = linspace(28, 56, 28);
z2 = zeros(1, 28);


for i = 1:28
  z2(1, i) = P2(i + 27);
endfor
z2;

y2 = ones(1, n);
for i = 1:n
  y2(1, i) = P2(x(i));
endfor
y2;

plot(t1, z1, 'linewidth', 8, t2, z2, 'linewidth', 8)
hold on;
plot(x, y, 'o', 'linewidth', 8)#, x, y2, 'o', 'linewidth', 4)
hold on;

plot(42, r1, 'o', 'linewidth', 8)
hold on;
plot(42, r2, 'o', 'linewidth', 8)




