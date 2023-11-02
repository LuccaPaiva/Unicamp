clear all
clc

dif = @(x) (1 - 0.09*(5 - x));
vel = @(x) -(0.2 - 0.01*(5 - x));
dec = 0.05

h = 1
diag = @(x) 2*dif(x) + dec*h^2;
dsup = @(x) -dif(x) + vel(x)*h/2;
dinf = @(x) -dif(x) - vel(x)*h/2;
t0 = @(x) -2*dif(x);


[C, D] = ex1(h, diag, dsup, dinf, t0);

h = 1/2
[C1, D1] = ex1(h, diag, dsup, dinf, t0);

h = 1/4
[C2, D2] = ex1(h, diag, dsup, dinf, t0);

h = 1/8
[C3, D3] = ex1(h, diag, dsup, dinf, t0);

plot(D, C, D1, C1, D2, C2, D3, C3)
