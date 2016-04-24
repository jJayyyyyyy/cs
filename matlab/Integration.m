% Indefinite Integral
syms x;
f = 2*x;
int(f);

% Definite Integral
% int(x, a, b) means integrate from a to b
int(2*x, 1, 4)



% example: Find the area under the curve: f(x) = x^2 * cos(x), for −4 ≤ x ≤ 9.
f = x^2*cos(x);
ezplot(f, [-4,9]);
a = int(f, -4, 9);
disp('Area: '), disp(double(a));