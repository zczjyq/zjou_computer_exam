import cv2

# 加载图像
image = cv2.imread('./images/nums.jpg')
# 转换为灰度图
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# 应用二值化阈值
_, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY_INV)
# 查找轮廓
contours, _ = cv2.findContours(binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
# 初始化计数器
large_contour_count = 0
min_area = 10000  # 设置面积阈值，根据实际情况调整

# 遍历轮廓并计算面积
for contour in contours:
    area = cv2.contourArea(contour)
    if area > min_area:
        large_contour_count += 1
        cv2.drawContours(image, [contour], -1, (0, 255, 0), 2)  # 绘制满足条件的轮廓

# 显示图像
cv2.imshow('Contoured Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
# 输出符合条件的曲别针数量
print(f"曲别针数量为: {large_contour_count}")