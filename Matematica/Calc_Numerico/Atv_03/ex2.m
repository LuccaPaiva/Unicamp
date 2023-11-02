caso = "5";
printf(strcat("Caso: ", caso, "\n"))
load(strcat("sherman", caso, ".mat"));
A = Problem.A;
b = Problem.b;

#Verificando esprcidade
T = issparse(A)
num = nnz(A);
N = length(A)
p = 100*num/(N*N)
nz = nnz(diag(A))
d = det(A)
#Verificando se pode ser resolvida
r = rank(A) # Se rank = N --> é nao singular(det != 0)


tic;[x1, Dr1] = MetodoJacobi(A, b); TempoJacobi = toc
tic;[x2, Dr2] = MetodoGaussSeidel(A, b); TempoGaussSeidel = toc
tic;x3 = A\b; TempoBarra = toc
  
#Comparacoes
c = cond(A)
Erro1 = Dr1(length(Dr1))
Erro2 = Dr2(length(Dr2))
Residuo1 = norm(b-A*x1)/norm(b)
Residuo2 = norm(b-A*x2)/norm(b)
Residuo3 = norm(b-A*x3)/norm(b)
Erro1 < c*Residuo1
Erro2 < c*Residuo2

