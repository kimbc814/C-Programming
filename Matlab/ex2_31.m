clear all;
close all;
clc;
function xdot=VanDerPol(t,x)
xdot(1,1)=x(2);
xdot(2,1)=x(2)*(1-x(1)^2)-x(1);
return

t0=0;
tf=20;
x0=[0 0.25];

[t,x] = ode23(@VanDerPol,[t0 tf],x0);

plot(t,x);