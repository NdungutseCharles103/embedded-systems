import cv2
# Read an image
image = cv2.imread('lena.jpg')
# Rotate image
rows, cols = image.shape[:2] 
M = cv2.getRotationMatrix2D((cols/2, rows/2), 45, 1)
rotated_image = cv2.warpAffine(image, M, (cols, rows))
# Display rotated image
cv2.imshow('Rotated Image', rotated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()