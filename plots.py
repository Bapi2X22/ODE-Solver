import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('res.txt',sep="\t",names=["t","y"])

plt.figure(1,figsize=(10, 8))
plt.plot(df.t,df.y,"o")
plt.legend(fontsize=20)


