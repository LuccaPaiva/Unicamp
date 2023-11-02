clc
clear all

h = 1;
[x1, y1] = Sis2(h);

h = 1/2;
[x2, y2] = Sis2(h);

h = 1/4;
[x3, y3] = Sis2(h);

h = 1/8;
[x4, y4] = Sis2(h);

h = 1/16;
[x5, y5] = Sis2(h);

h = 1/32;
[x6, y6] = Sis2(h);


plot(x1, y1, 'linewidth', 8, x2, y2, 'linewidth', 8, x3, y3, 'linewidth', 8, x4, y4, 'linewidth', 8,
x5, y5, 'linewidth', 6, x6, y6, 'linewidth', 4); grid;
leg = legend("h=1", "h=1/2", "h=1/4", "h=1/8", "h=1/16", "h=1/32", "location", "northwestoutside");
legend boxoff;
tit = title("Concentracao de Poluente x Profundidade");
yl = ylabel ("Concentracao de Poluente");
xl = xlabel("Profundidade (m)");
set (yl, "fontsize", 30);
set (xl, "fontsize", 30);
set (tit, "fontsize", 40);
set (leg, "fontsize", 30);