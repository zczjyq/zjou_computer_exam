import cv2
import numpy as np

# 加载图像
image = cv2.imread('./images/xiacitest.jpg')

# 转换为灰度图
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# 应用高斯模糊
blur = cv2.GaussianBlur(gray, (7,7), 0)

# 应用Canny边缘检测
edged = cv2.Canny(blur, 10, 29)
# 将边缘图像转换为彩色
edged_colored = cv2.cvtColor(edged, cv2.COLOR_GRAY2BGR)
# 在原始图像上叠加边缘，边缘以白色显示
overlay = cv2.bitwise_or(image, edged_colored)

cv2.imshow("Original", image)
cv2.imshow("Red Edge Overlay", overlay)
cv2.waitKey(0)
cv2.destroyAllWindows()