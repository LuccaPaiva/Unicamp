function [xk, yk, sol] = RK4(f, x0, u0, h, n)
  xk = x0;
  yk = yo;
  sol = zeros(n, 1);
  for i = 1:n
    k1 = f(xk, yk);
    k2 = f(xk + (h/2), yk + (h/2)*k1);
    k3 = f(xk + (h/2), yk + (h/2)*k2);
    k4 = f(xk + h, yk + k3*h);
    yk = yk + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
    xk = xk + h;
    sol(i) = yk;    
  endfor
endfunction
