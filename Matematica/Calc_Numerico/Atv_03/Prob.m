function [P] = Prob(A)
  n = length(A);
  S = sum(A);
  f = 1/n;
  #P = (1/n)*ones(n , n);
  for i = 1:n
    for j = 1:n
      if(S(j) >= 1)
        P(i, j) = A(i, j)/S(j);
      else
        P(i, j) = f;
       endif
    endfor
  endfor
endfunction
