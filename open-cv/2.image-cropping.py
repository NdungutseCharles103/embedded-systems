import cv2
# Read an image
image = cv2.imread('lenna.png')
# Crop image
cropped_image = image[100:300, 200:400]
# Display cropped image
cv2.imshow('Cropped Image', cropped_image)
cv2.waitKey(0)
cv2.destroyAllWindows()