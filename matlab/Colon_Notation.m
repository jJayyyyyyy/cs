% The colon(:) is one of the most useful operator in MATLAB.
% It is used to create vectors, subscript arrays, and specify for iterations.

% If you want to create a row vector, containing integers from 1 to 10, you write
a = 1:10;

% If you want to specify an increment value other than one, for example
b = 100: -5: 50;

% More
A = [1 2 3 4; 4 5 6 7; 7 8 9 10];
B = A(1:2,3:4);
A
B

% A is a Matrix
% A(i:j, m:n) shows a new matrix made of <ith to jth row> and <mth to nth
% column> of Matrix-A