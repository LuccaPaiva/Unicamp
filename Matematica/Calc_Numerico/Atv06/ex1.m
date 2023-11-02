function [C, D] = ex1 (h, diag, dsup, dinf, t0)
  n = 5/h;
  mat = zeros(n);
  
  D = zeros(1, n);
  for i = 1:n
    D(1, i) = (i - 1)*h;
  endfor
  D(1, n) = n*h;
  D(1, 1) = 0
  
  for i = 1:n
    mat(i,i) = diag(D(n));
  endfor

  for i = 2:n
    mat(i - 1, i) = dsup(D(1, i - 1));
  endfor

  for i = 1:n - 2
    mat(i + 1, i) = dinf(D(1, i + 1));
  endfor

  mat(n, n - 1) = t0(5);

  y = ones(n , 1);
  y = y*0.025*(h^2)
  
  mat
  
  C = mat\y
  
endfunction
