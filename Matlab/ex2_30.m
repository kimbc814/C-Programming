clear all;
close all;
clc;
function ydot=DerivCos(t,v)
ydot=cos(t);
return

t0=0; 
tf = 2*pi;
y0=0;

[t , y] = ode23('DerivCos', [t0 tf] , y0);

plot(t,y);