# This is a sample Python script.
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.cluster import KMeans
from sklearn.neighbors import NearestNeighbors

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    class1 = np.random.multivariate_normal(mean=[0, 0], cov=[[1, 0], [0, 0.1]], size=2000)
    class2= np.random.multivariate_normal(mean=[5, 5], cov=[[1, 0], [0, 0.1]], size=2000)

    myData = np.concatenate((class1, class2))
    myDF = pd.DataFrame(myData, columns=['Var1', 'Var2'])
    myDF.to_csv("Example1.txt", sep=' ')


    class1 = np.random.multivariate_normal(mean=[0, 0, 0], cov=[[1, 0, 0], [0, 0.1, 0], [0, 0, 1]], size=1000000)
    class2 = np.random.multivariate_normal(mean=[5, 5, 5], cov=[[1, 0, 0], [0, 0.1, 0], [0, 0, 1]], size=1000000)
    class3 = np.random.multivariate_normal(mean=[10,10, 10], cov=[[1, 0, 0], [0, 0.1, 0], [0, 0, 1]], size=1000000)

    myData = np.concatenate((class1, class2, class3))
    myDF = pd.DataFrame(myData)#, columns=['Var1', 'Var2', 'Var3'])
    myDF.to_csv("Example2.txt", sep=' ', index = False, header=False)

