% In MATLAB environment, every variable is an array or matrix.

x = sqrt(16);

y=(-1):0.5:1;

% In case you foeget the Variables, the <who> and <whos> command display
% all the variable you've used.

%who;

%whos;



%short (default)
format short
x = 7 + 10/3 + 5 ^ 1.2;

format long
x = 7 + 10/3 + 5 ^ 1.2;


% The format rat command gives the closest rational expression resulting from a calculation.
% For example

format rat;
a = 3.3 / 1.2;

% MATLAB will return the following result
% a = 11/4 



% Creating Vectors

% Row Vectors (using <space ( )> or <comma (,)> to delimit the elements)
r1 = [1 2 3 4];
r2 = [1, 2, 3, 4];

% Column Vectors (using <semicolon (;)>)
c = [5; 6; 7; 8];


% Matrix
m1 = [  1, 2, 3;
        4, 5, 6;
        7, 8, 9];
m2 = [1 2; 3 4];
