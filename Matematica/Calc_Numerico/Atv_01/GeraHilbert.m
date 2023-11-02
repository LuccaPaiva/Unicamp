function [H] = GeraHilbert(N)
  H = zeros(N,N);
  for i=1:N
    for j=1:N
      
      H(i,j) = 1/(i+j-1);
      
    end
  end
endfunction
