load("Harvard500.mat");
A = Problem.A;
P = Prob(A);

alfa = 0.85;
n = length(P);
V = (1 - alfa)*ones(n)*(1/n);
B = (alfa*P - eye(n));
x = -B\V;
S = sum(x, 2);
m = max(S);
indice = find(m == max(S))
m = m/n
