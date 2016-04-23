% MATLAB supports various numeric classes that include signed and unsigned 
% integers and single-precision and double-precision floating-point numbers.
% By default, MATLAB stores all numeric values as double-precision floating 
% point numbers.

% You can choose to store any number or array of numbers as integers or as 
% single-precision numbers.

% All numeric types support basic array operations and mathematical 
% operations.

a = single([5.32 3.47 6.28]) .* 7.5;
b = double([5.32 3.47 6.28]) .* 7.5;
c = int8([5.32 3.47 6.28]) .* 7.5;
d = int16([5.32 3.47 6.28]) .* 7.5;


e = int32([5.32 3.47 6.28]) .* 7.5;
g = num2cell(e);