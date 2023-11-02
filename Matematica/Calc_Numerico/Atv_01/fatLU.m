function [L, U] = fatLU(A)
  n = size(A)
  L = eye(n)
  
  for j = 1:n-1
    for i = j+1:n
      l(i, j) = A(i, j)/A(i, j);
      for k=j+1:n
        A(i, k) = A(i, k)-L(i, j)*A(j, k);
      endfor
    endfor
  endfor
  U = triu(A);
  
endfunction
