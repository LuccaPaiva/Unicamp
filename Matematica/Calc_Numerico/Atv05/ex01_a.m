function [X, Y] = Heun(f, h, XRANGE, YINIT)
  #f e a funcao
  #h e o tamanho do passo
  #XRANGE = [x0 xFinal]
  #YNIT e o valor de y(xo)
  
  X(1) = XRANGE(1);
  Y(1) = YNIT;
  k = 1;#numero iteracoes
  
  while X(k) < XRANGE(2)
    X(k + 1) = X(k) + h;
    k1 = f(X(k), Y(k) + h*k1);
    k2 = f(X(k + 1), Y(k) + h*k1);
    Y(k + 1) = Y(k) + h*(k1 + k2)/2;
    k = k + 1;
   end
  
  
endfunction
