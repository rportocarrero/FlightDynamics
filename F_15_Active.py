# This file denotes the lateral-directional dynamics of the F-15 Active
# Technology demonstrator.

import numpy as np

alpha_0 = 2
V_0 = 793

# Lateral-directional stability derivatives
Y_beta = -0.15
Y_delta_r = 0.05
Y_delta_ds = 0.035
Y_delta_dc = -0.025
L_beta = -22.5
L_p = -2.05
L_r = 3.15
L_delta_r = -28.4
L_delta_r =4.2
L_delta_ds = -34.2
L_delta_dc = 5.14
N_beta = 4.4
N_p = 0.11
N_r = -0.17
N_delta_r = -3.75
N_delta_ds = -1.4
N_delta_dc = -2.40

A = np.array([[Y_beta, np.sin(2*np.pi*alpha_0/360), -np.cos(2*np.pi*alpha_0/360), g*np.cos(2*np.pi*alpha_0/360)/V_0],[L_beta, L_p, L_r, 0],[N_beta, N_p, N_r, 0],[0, 1, np.tan(2*np.pi*alpha_0/360), 0]])
B = np.array([[],[],[],[]]) 
C = np.array([])
D = np.array([])
