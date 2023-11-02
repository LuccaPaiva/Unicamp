f = @(x) [x(1) + cosh(x(2)) - 1; x(1) + cosh(x(2) + 1) - 2];
fl = @(x) [1, sinh(x(2)); 1,  sinh(x(2) + 1)];

x0 = [0; 0.5];
e1 = 1e-3;

it_max = 100;

[r, it] = MetodoNewtonSist(f, fl, x0, e1, e1, it_max)