import cv2
# Read an image
image = cv2.imread('lena.jpg')
# Load a pre-trained Haar cascade
face_cascade = cv2.CascadeClassifier('./sunglass-shop/haarcascade_frontalface_default.xml')
# Convert to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# Find contours
contours, _ = cv2.findContours(gray_image, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
# Draw contours
cv2.drawContours(image, contours, -1, (0, 255, 0), 3)
# Display image with contours
cv2.imshow('Contours', image)
cv2.waitKey(0)
cv2.destroyAllWindows()