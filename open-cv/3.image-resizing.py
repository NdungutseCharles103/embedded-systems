import cv2
# Read an image
image = cv2.imread('lenna.png')
# Resize image
resized_image = cv2.resize(image, (500, 400))
# Display resized image
cv2.imshow('Resized Image', resized_image)
cv2.waitKey(0)
cv2.destroyAllWindows()