% <syms> means symbolic variables and functions
syms t
f = 3*t^2 + 2*t^(-2);
diff(f);



% Find the Maxima and Minima of a Curve

% first plot it --->
syms x
y = 2*x^3 + 3*x^2 - 12*x + 17;
ezplot(y)             % to plot sym, use ezplot()

% to find some local maxima and minima based on the graph --->
syms x
y = 2*x^3 + 3*x^2 - 12*x + 17;
ezplot(y, [-2, 2])      % based on the graph

% use derivative
g = diff(y);

% solve it
s = solve(g);
% it gives out s=1, -2
% This agrees with our plot

% So let us evaluate the function f at the critical points x = 1, -2.
% We can substitute a value in a symbolic function by using the subs command.
subs(y, 1), subs(y, -2);



% Differential Equation. (When needed, learn it.)



