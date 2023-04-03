import numpy as np
import matplotlib.pyplot as plt


# Initial Conditions #

from cmath import sqrt


x=7.5
y=3
u=0

# Parameters #
h=0.01
xf=15
k=1

def f(u):
    return k*sqrt(1+u**2)

y_arr=[]
x_arr=[]
u_arr=[]

while (x<xf):
    y=y+h*u
    u=u+h*f(u)
    x=x+h
    y_arr.append(y)
    u_arr.append(u)
    x_arr.append(x)


plt.plot(x_arr,y_arr,label="Euler")
plt.legend()
plt.show()