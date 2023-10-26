import numpy as np

def load_data():
    data = np.loadtxt("data/ex1data1.txt", delimiter=',')
    X = data[:,0]
    y = data[:,1]
    return X, y

def load_data_multi():
    data = np.loadtxt("data/houses.txt", delimiter=',')
    v = data[:,0]
    w = data[:,1]
    x = data[:,2]
    y = data[:,3]
    z= data[:,4]
    return v, w, x, y, z
