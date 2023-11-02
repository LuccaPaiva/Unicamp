a = 1;
f = @(t) a^(t - 1)*exp(-t);
n =100;
x = linspace(0, 10, n + 1)
y = ones(1, n + 1);
for i = 1:n + 1
  y(1, i) = f(x(i));
 endfor
plot(x, y)