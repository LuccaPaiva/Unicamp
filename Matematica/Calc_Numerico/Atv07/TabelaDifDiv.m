function T = TabelaDifDiv(x, y)
  N = length(x);
  T = zeros(N,N);
  T(:,1) = y;
  for j=2:N+1
    for i=1:N-j+1
      T(i,j) = (T(i,j-1)-T(i+1,j-1))/(x(i)-x(j+i-1));
    end
  end

endfunction
