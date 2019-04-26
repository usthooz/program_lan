import numpy as np

a = np.array([1,2,3])
print(a)

b = np.array([[1, 2], [3, 4]])
print(b)

# 最小维度
c = np.array([1, 2, 3, 4, 5], ndmin=2)
print(c)

# dtype 参数
d = np.array([1, 2, 3], dtype=complex)
print(d)
