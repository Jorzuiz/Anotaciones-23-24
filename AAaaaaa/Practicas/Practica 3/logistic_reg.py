import numpy as np
import copy
import math


def sigmoid(z):
    """
    Compute the sigmoid of z

    Args:
        z (ndarray): A scalar, numpy array of any size.

    Returns:
        g (ndarray): sigmoid(z), with the same shape as z

    """
    
    #z = np.array(z)
    
    g = 1 / (1 + np.exp(-z))

    return g


#########################################################################
# logistic regression
#
def compute_cost(X, y, w, b, lambda_=None):
    """
    Computes the cost over all examples
    Args:
      X : (ndarray Shape (m,n)) data, m examples by n features
      y : (array_like Shape (m,)) target value
      w : (array_like Shape (n,)) Values of parameters of the model
      b : scalar Values of bias parameter of the model
      lambda_: unused placeholder
    Returns:
      total_cost: (scalar)         cost
    """
    
    m = len(y)  # Number of training examples
    z = np.dot(X, w) + b
    h = sigmoid(z)  # Sigmoid function

    #print(h.shape, y.shape)
    # Calculate the cost
    total_cost = (1 / m) * np.sum(-y * np.log(h) - ((1 - y) * np.log(1 - h)))

    return total_cost


def compute_gradient(X, y, w, b, lambda_=None):
    """
    Computes the gradient for logistic regression

    Args:
      X : (ndarray Shape (m,n)) variable such as house size
      y : (array_like Shape (m,1)) actual value
      w : (array_like Shape (n,1)) values of parameters of the model
      b : (scalar)                 value of parameter of the model
      lambda_: unused placeholder
    Returns
      dj_db: (scalar)                The gradient of the cost w.r.t. the parameter b.
      dj_dw: (array_like Shape (n,1)) The gradient of the cost w.r.t. the parameters w.
    """
    
    m = len(y)  # Number of training examples
    z = np.dot(X, w) + b
    h = sigmoid(z)  # Sigmoid function

    # Calculate the gradients
    dj_db = (1 / m) * np.sum(h - y)
    dj_dw = (1 / m) * np.dot(X.T, (h - y))


    return dj_db, dj_dw


#########################################################################
# regularized logistic regression
#
def compute_cost_reg(X, y, w, b, lambda_=1):
    """
    Computes the cost over all examples
    Args:
      X : (array_like Shape (m,n)) data, m examples by n features
      y : (array_like Shape (m,)) target value 
      w : (array_like Shape (n,)) Values of parameters of the model      
      b : (array_like Shape (n,)) Values of bias parameter of the model
      lambda_ : (scalar, float)    Controls amount of regularization
    Returns:
      total_cost: (scalar)         cost 
    """
    
    m = len(y)  # Number of training examples
    z = np.dot(X, w) + b
    z = np.clip(z, -1000, 1000)  # Avoid overflow
    h = sigmoid(z)  # Sigmoid function

    # Calculate the standard logistic regression cost
    log_loss = (1 / m) * np.sum(-y * np.log(h) - (1 - y) * np.log(1 - h))

    # Calculate the regularization term
    regularization = (lambda_ / (2 * m)) * np.sum(w**2)  # Exclude the bias term (w0)

    # Combine the two terms to get the total cost
    total_cost = log_loss + regularization

    return total_cost


def compute_gradient_reg(X, y, w, b, lambda_=1):
    """
    Computes the gradient for linear regression 

    Args:
      X : (ndarray Shape (m,n))   variable such as house size 
      y : (ndarray Shape (m,))    actual value 
      w : (ndarray Shape (n,))    values of parameters of the model      
      b : (scalar)                value of parameter of the model  
      lambda_ : (scalar,float)    regularization constant
    Returns
      dj_db: (scalar)             The gradient of the cost w.r.t. the parameter b. 
      dj_dw: (ndarray Shape (n,)) The gradient of the cost w.r.t. the parameters w. 

    """
    m = len(y)  # Number of training examples
    z = np.dot(X, w) + b
    z = np.clip(z, -1000, 1000)  # Avoid overflow
    h = sigmoid(z)  # Sigmoid function

    # Calculate the gradient without regularization
    dj_db = 1 / m * np.sum(h - y)
    dj_dw = 1 / m * np.dot(X.T, (h - y))

    # Add the regularization term (except for the bias term)
    dj_dw += (lambda_ / m) * w

    return dj_db, dj_dw


#########################################################################
# gradient descent
#
def gradient_descent(X, y, w_in, b_in, cost_function, gradient_function, alpha, num_iters, lambda_=None):
    """
    Performs batch gradient descent to learn theta. Updates theta by taking 
    num_iters gradient steps with learning rate alpha

    Args:
      X :    (array_like Shape (m, n)
      y :    (array_like Shape (m,))
      w_in : (array_like Shape (n,))  Initial values of parameters of the model
      b_in : (scalar)                 Initial value of parameter of the model
      cost_function:                  function to compute cost
      alpha : (float)                 Learning rate
      num_iters : (int)               number of iterations to run gradient descent
      lambda_ (scalar, float)         regularization constant

    Returns:
      w : (array_like Shape (n,)) Updated values of parameters of the model after
          running gradient descent
      b : (scalar)                Updated value of parameter of the model after
          running gradient descent
      J_history : (ndarray): Shape (num_iters,) J at each iteration,
          primarily for graphing later
    """

    w = w_in
    b = b_in
    J_history = np.zeros(num_iters)

    for i in range(num_iters):
        J_history[i] = cost_function(X, y, w, b, lambda_)
        
        dj_db, dj_dw = gradient_function(X, y, w, b, lambda_)

        w -= alpha * dj_dw
        b -= alpha * dj_db


    return w, b, J_history


#########################################################################
# predict
#
def predict(X, w, b):
    """
    Predict whether the label is 0 or 1 using learned logistic
    regression parameters w and b

    Args:
    X : (ndarray Shape (m, n))
    w : (array_like Shape (n,))      Parameters of the model
    b : (scalar, float)              Parameter of the model

    Returns:
    p: (ndarray (m,1))
        The predictions for X using a threshold at 0.5
    """

    m = X.shape[0]
    p = np.zeros((m, 1))

    # Calculate the probabilities using the logistic function
    z = np.dot(X, w) + b
    h = sigmoid(z)
    # Apply the threshold at 0.5 to make predictions
    p = (h >= 0.5).astype(int)

    return p