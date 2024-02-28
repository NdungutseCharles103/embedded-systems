import cv2
import matplotlib.pyplot as plt
# Read an image
image = cv2.imread('lena.jpg')
# Display the image
cv2.imshow('Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()