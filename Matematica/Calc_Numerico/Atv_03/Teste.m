printf("Teste 5\n")
load("sherman5.mat");
A = Problem.A;
b = Problem.b;

n = rows(A);
x0 = zeros(n);
kmax = 100;
tau = 1.e-4;


[xj,Drj]=MetodoJacobi(A,b,x0,kmax,tau);
semilogy(Drj);

grid;
axis([1, length(Drj), min(Drj), max(Drj)]);
hold on;

[xs,Drs]=MetodoGaussSeidel(A,b,x0,kmax,tau);

semilogy(Drs);
xlabel("Iteracoes"); ylabel("Diferença Relativa");
title("Comparacoes Metodos- 05");
grid;
axis([1, length(Drs), min(Drs), max(Drs)]);