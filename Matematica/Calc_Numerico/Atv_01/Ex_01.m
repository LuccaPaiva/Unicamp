E = @(m) (1 + 1/m)^m;
y = [];
for x = [1 10^3 10^6 10^9 10^12 10^15 10^18]  
  y = [y E(x)]
end
y