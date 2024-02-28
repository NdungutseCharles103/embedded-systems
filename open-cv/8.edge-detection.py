import cv2
# Read an image
image = cv2.imread('lena.jpg')
# Convert to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# Apply Canny edge detection
edges = cv2.Canny(gray_image, 50, 150)
# Display edges
cv2.imshow('Edges', edges)
cv2.waitKey(0)
cv2.destroyAllWindows()