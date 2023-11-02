load("1138_bus.mat");
A = Problem.A;
#letra A
printf("Letra A\n")
num = nnz(A)
N = length(A)
p = 100*num/(N*N)

#Letra B
printf("\nLetra B\nO tipo da matriz é: ")
matrix_type(A)
if(A' == A)
  printf("È simetrica\n")
else
  printf("Nao é simetrica\n")
endif

#Letra C
printf("\nLetra C\n")
xsol = 0.5 + sin( 2*pi*(0:N-1)'/(N-1));
b = A*xsol;
c = cond(A)
tic; xn = A\b; Tempo = toc
Residuo1 = norm(b-A*xn)/norm(b)
Erro1 = norm(xsol-xn)/norm(xsol)

Erro1 < c*Residuo1

#Letra D
printf("\nLetra D\n")
G = chol(A);
Gt = G';
tic; xm = G\(Gt\b); Tempo1 = toc
tic; G = chol(A); xm = G\(G'\b); Tempo2 = toc
Residuo2 = norm(b-A*xm)/norm(b)
Erro2 = norm(xsol-xm)/norm(xsol)

Erro2 < c*Residuo2

