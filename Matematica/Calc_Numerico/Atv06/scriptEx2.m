clear all
clc
x = [0 6 14 21 28 35 49 56]';


n = 8;

y = [2546 2347 2219 2261 2294 2821 3118 2899]';

P = polyfit(x,y,length(x));

T = TabelaDifDiv(x, y);

pre = output_precision(10);

([x,T]);

P2 = @(k) (2546 + -33.1666666667*(k - 0) + 0.9861111111*(k - 0)*(k - 6)  + 0.0355820106*(k - 0)*(k - 6)*(k - 14) + 
-0.0040798074*(k - 0)*(k - 6)*(k - 14)*(k - 21) + 0.0004098557*(k - 0)*(k - 6)*(k - 14)*(k - 21)*(k - 28) + 
-0.0000195348*(k - 0)*(k - 6)*(k - 14)*(k - 21)*(k - 28)*(k - 35) + 
0.0000007157*(k - 0)*(k - 6)*(k - 14)*(k - 21)*(k - 28)*(k - 35)*(k - 49));

Erro = @(k) (k - 0)*(k - 6)*(k - 14)*(k - 21)*(k - 28)*(k - 35)*(k - 49);


r1 = polyval(P, 42);
r2 = P2(42);

E = abs(Erro(42));

t1 = linspace(0,56);
z1 = polyval(P,t1);

t2 = linspace(0, 56, 57);
z2 = zeros(1, 57);


for i = 1:57
  z2(1, i) = P2(i - 1);
endfor

y2 = ones(1, n);
for i = 1:n
  y2(1, i) = P2(x(i));
endfor

#----------------------------------------------

a = [28 35 49 56]';

n = 4;

b = [2294 2821 3118 2899]';

R = polyfit(a,b,length(a));

T2 = TabelaDifDiv(a, b);

pre = output_precision(10);

([a,T2])

R2 = @(k)  2294 + 75.2857142857*(k - 28) + -2.5748299320*(k - 28)*(k - 35) + 0.0026724976*(k - 28)*(k - 35)*(k - 49);

Erro3 = @(k) 0.0026724976*(k - 28)*(k - 35)*(k - 49);

r3 = polyval(R, 42);
r4 = R2(42);

E2 = abs(Erro3(42));

u1 = linspace(0,56);
w1 = polyval(P,t1);

u2 = linspace(28, 56, 29);
w2 = zeros(1, 28);


for i = 1:29
  w2(1, i) = R2(i + 27);
endfor

v2 = ones(1, n);
for i = 1:n
  v2(1, i) = R2(a(i));
endfor
v2;




plot(t1, z1, 'linewidth', 8, t2, z2, 'linewidth', 8);
hold on;
plot(u1, w1, 'linewidth', 8, u2, w2, 'linewidth', 8);
hold on;

plot(x, y, 'o', 'linewidth', 8, 42, r1, 'o', 'linewidth', 8, 42, r2, 'o', 'linewidth',
 8, 42, r3, 'o', 'linewidth', 8)
hold on;

tit = title("Casos de Covid");
yl = ylabel ("Casos Graves de Covid");
xl = xlabel("Tempo em Dias");
#leg = legend("", "Dif Div grau 7", "Poli Fit grau 3",
 #"Dif Div grau 3", "Pontos Base", "location", "northwest");


#set (leg, "fontsize", 30);
set (yl, "fontsize", 30);
set (xl, "fontsize", 30);
set (tit, "fontsize", 40);

printf("Erro 1: %f \n", E);

printf("Erro 2: %f \n", E2);

printf("Numero de casos dado por P1: %f \n", r1);
printf("Numero de casos dado por P2: %f \n", r4);

printf("Numero de casos dado por F1: %f \n", r2);
printf("Numero de casos dado por F2: %f \n", r3);


