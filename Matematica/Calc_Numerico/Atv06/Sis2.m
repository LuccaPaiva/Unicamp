function [xs, ys] = Sis2 (h)
  n = 5/h;

  x = linspace(h, 5, n);

  A = -(1 - 0.09*(5 - x));
  B = -(0.2 - 0.01*(5 - x));
  C = 0.05;
  f = 0.025*ones(n, 1);

  mat = zeros(n , n);
  mat(1,1) = h^2*C(1)-2*A(1);
  mat(1,2) = A(1)+h*B(1)/2;
  for k = 2:n-1
    mat(k,k-1) = A(k) - h*B(k)/2;
    mat(k,k) = h^2*C - 2*A(k);
    mat(k,k+1) = A(k) + h*B(k)/2;
  end
  mat(n,n-1) = 2*A(n);
  mat(n,n) = h^2*C-2*A(n);
  g = h^2*f;

  xs = [0, x];
  ys = [0; mat\g];
endfunction
