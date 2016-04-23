## Commands for Managing a Session

Command | Purpose
---|---|
clc | Clears command window
clear | Removes variables from memory
exist | Checks for existence of file or variable
global | Declares variables to be global
help | Searches for a help topic
lookfor | Searches help entries for a keyword
quit | Stops MATLAB
who | Lists current variables
whos | Lists current variables (long display)



## Commands for Working with the System

Command | Purpose
---|---|
cd | Changes current directory
date | Displays current date
delete | Deletes a file
diary | Switches on/off diary file recording
dir | Lists all files in current directory
load | Loads workspace variables from a file
path | Displays search path
pwd	| Displays current directory
type | Displays contents of a file


## Input and Output Commands

MATLAB provides the following input and output related commands

Command	| Purpose
---|---|
disp | Displays contents of an array or string
fscanf | Read formatted data from a file
format | Controls screen-display format
fprintf | Performs formatted writes to screen or file
input | Displays prompts and waits for input
; | Suppresses screen printing


The fscanf and fprintf commands behave like C scanf and printf functions They support the following format codes

Format Code	| Purpose
---|---|
%s | Format as a string
%d | Format as an integer
%f | Format as a floating point value
%e | Format as a floating point value in scientific notation
%g | Format in the most compact form: %f or %e
\n | Insert a new line in the output string
\t | Insert a tab in the output string


The format function has the following forms used for numeric display

Format Function | Display up to
---|---|
format short | Four decimal digits (default)
format long | 16 decimal digits
format short e | Five digits plus exponent
format long e | 16 digits plus exponents
format bank	| Two decimal digits
format + | Positive, negative, or zero
format rat | Rational approximation
format compact | Suppresses some line feeds
format loose | Resets to less compact display mode



## Vector, Matrix and Array Commands

The following table shows various commands used for working with arrays, matrices and vectors

Command | Purpose
---|---|
cat | Concatenates arrays
find | Finds indices of nonzero elements
length | Computes number of elements
linspace | Creates regularly spaced vector
logspace | Creates logarithmically spaced vector
max | Returns largest element
min | Returns smallest element
prod | Product of each column
reshape | Changes size
size | Computes array size
sort | Sorts each column
sum | Sums each column
eye | Creates an identity matrix
ones | Creates an array of ones
zeros | Creates an array of zeros
cross | Computes matrix cross products
dot | Computes matrix dot products
det | Computes determinant of an array
inv | Computes inverse of a matrix
pinv | Computes pseudoinverse of a matrix
rank | Computes rank of a matrix
rref | Computes reduced row echelon form
cell | Creates cell array
celldisp | Displays cell array
cellplot | Displays graphical representation of cell array
num2cell | Converts numeric array to cell array
deal | Matches input and output lists
iscell | Identifies cell array



## Plotting Commands

MATLAB provides numerous commands for plotting graphs. The following table shows some of the commonly used commands for plotting

Command| Purpose
---|---|
axis | Sets axis limits
fplot | Intelligent plotting of functions
grid | Displays gridlines
plot | Generates xy plot
print | Prints plot or saves plot to a file
title | Puts text at top of plot
xlabel | Adds text label to x-axis
ylabel | Adds text label to y-axis
axes | Creates axes objects
close | Closes the current plot
close al | lCloses all plots
figure | Opens a new figure window
gtext | Enables label placement by mouse
hold | Freezes current plot
legend | Legend placement by mouse
refresh | Redraws current figure window
set | Specifies properties of objects such as axes
subplot | Creates plots in subwindows
text | Places string in figure
bar | Creates bar chart
loglog | Creates log-log plot
polar | Creates polar plot
semilogx | Creates semilog plot (logarithmic abscissa)
semilogy | Creates semilog plot (logarithmic ordinate)
stairs | Creates stairs plot
stem | Creates stem plot

