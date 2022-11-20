import cv2

a = cv2.imread("resources/background.bmp")
cv2.imshow('a',a)
cv2.waitKey(1000)
a = cv2.imread("resources/single_rock.bmp")
cv2.imshow('a',a)
cv2.waitKey(1000)