from skimage import data
import matplotlib.pyplot as plt
import numpy as np


img = data.camera().astype(np.float32)
plt.imshow(img, cmap='gray')
plt.show()

print(img.shape)
