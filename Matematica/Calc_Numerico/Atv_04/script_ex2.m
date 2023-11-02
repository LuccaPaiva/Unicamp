clc
clear all
f = @(D) sqrt(400 - D^2)*(sqrt(900 - D^2) - 8) - 8*sqrt(900 - D^2);
a = 15;
b = 18;
f(a)
f(b)
e1 = 10^-3;
e2 = 10^-3;

[resp, a, b, it] = Bisseccao(a, b, f, e1, e2, 1000)
