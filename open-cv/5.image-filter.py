import cv2
# Read an image
image = cv2.imread('lena.jpg')
# Apply blur
blurred_image = cv2.GaussianBlur(image, (15, 15), 0)
# Display blurred image
cv2.imshow('Blurred Image', blurred_image)
cv2.waitKey(0)
cv2.destroyAllWindows()