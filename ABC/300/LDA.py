import numpy as np
import matplotlib.pyplot as plt
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis

# 入力データ
X = np.array([[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7], [7, 8], [8, 9]])
y = np.array([0, 0, 0, 0, 1, 1, 1, 1])

# フィッシャーの線形判別を行う
clf = LinearDiscriminantAnalysis()
clf.fit(X, y)

# 判別直線の傾きと切片を取得する
w = clf.coef_[0]
b = clf.intercept_

# 入力データをプロットする
plt.scatter(X[:, 0], X[:, 1], c=y)

# 判別直線をプロットする
x = np.linspace(np.min(X[:, 0]), np.max(X[:, 0]), 100)
y = (-w[0] * x - b) / w[1]
plt.plot(x, y)

# 分析前の画像を保存する
plt.savefig('before.png')

# 入力データに判別直線を射影する
X_projected = clf.transform(X)

# 射影されたデータをプロットする
plt.scatter(X_projected[:, 0], np.zeros_like(X_projected), c=y)

# 分析後の画像を保存する
plt.savefig('after.png')
