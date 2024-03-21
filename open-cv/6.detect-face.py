import cv2
# Read an image
image = cv2.imread('lenna.png')
# Load a pre-trained Haar cascade
face_cascade = cv2.CascadeClassifier('face-recognition/models/haarcascade_frontalface_default.xml')
# Detect faces
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))
# Draw rectangles around faces
for (x, y, w, h) in faces:
 cv2.rectangle(image, (x, y), (x+w, y+h), (255, 0, 0), 2)
# Display image with detected faces
cv2.imshow('Faces Detected', image)
cv2.waitKey(0)
cv2.destroyAllWindows()