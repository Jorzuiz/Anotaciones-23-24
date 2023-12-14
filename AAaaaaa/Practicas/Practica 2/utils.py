import numpy as np

def load_data():
    data = np.loadtxt("data/ex1data1.txt", delimiter=',')
    X = data[:,0]
    y = data[:,1]
    return X, y

def load_data_multi():
    data = np.loadtxt("data/houses.txt", delimiter=',')
    # thing = data[:,:-1] matriz de dos dimensiones, desdela 0 es :, desdela 0 a la -1
    # thing2 = data[:,-1:] se salta la columna 1 y va al final?
    # thing 3 = data[:,3:4]
    x = data[:,:-1]
    return x
