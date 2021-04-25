# -*- codecs: utf-8 -*-
import codecs
import sys
import numpy as np
import cv2

def tobnw(input):
    gray = cv2.cvtColor(input, cv2.COLOR_BGR2GRAY)
    gray = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5,5))
    gray = 255 - cv2.morphologyEx(gray, cv2.MORPH_CLOSE, kernel, iterations=2)
    return gray
    
def draw(input, output, name):
    gray = cv2.cvtColor(input, cv2.COLOR_BGR2GRAY)
    gray = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5,5))
    gray = 255 - cv2.morphologyEx(gray, cv2.MORPH_CLOSE, kernel, iterations=2)
    contours, hierarchy = cv2.findContours(gray, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for c in contours:
        # compute the center of the contour
        M = cv2.moments(c)
        cX = int(M["m10"] / M["m00"])
        cY = int(M["m01"] / M["m00"])
        # draw the contour and center of the shape on the image
        cv2.drawContours(output, [c], -1, (255, 255, 255), 2)
        cv2.putText(output, name, (cX, cY),
            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)                       

def drawAnomaly(input, output, name):
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5,5))
    gray = 255 - cv2.morphologyEx(input, cv2.MORPH_CLOSE, kernel, iterations=2)
    contours, hierarchy = cv2.findContours(gray, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for c in contours:
        # compute the center of the contour
        M = cv2.moments(c)
        cX = int(M["m10"] / M["m00"])
        cY = int(M["m01"] / M["m00"])
        # draw the contour and center of the shape on the image
        cv2.drawContours(output, [c], -1, (0, 0, 0), 2)
        cv2.putText(output, name, (cX, cY),
            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 2)  
            
img = cv2.imread('heat2.png', cv2.IMREAD_COLOR)
fullmask = cv2.imread('window2.png', cv2.IMREAD_COLOR)
windows = cv2.imread('window2.png', cv2.IMREAD_COLOR)
door = cv2.imread('door.png', cv2.IMREAD_COLOR)
mask = cv2.cvtColor(tobnw(fullmask), cv2.COLOR_GRAY2BGR)
mask = mask
masked = cv2.bitwise_or(img, mask)
mask = cv2.inRange(masked,(0, 0, 50),(120,120,255))
mask_rgb = cv2.cvtColor(mask,cv2.COLOR_GRAY2BGR)
mask_rgb = 255 - mask_rgb
masked = cv2.bitwise_and(img, mask_rgb)
cv2.imshow("masked", mask_rgb)
masked = cv2.cvtColor(masked, cv2.COLOR_BGR2GRAY)
cv2.imshow("masked_bnw", masked)
masked = cv2.threshold(masked, 0, 255, cv2.THRESH_BINARY)[1]
cv2.imshow("masked_bnw_thresh", masked)
drawAnomaly(masked, img, 'A')
draw(windows,img, 'W')
#(door, img, 'D')
cv2.imshow("Image", img)
cv2.imwrite("result.png", img)
cv2.waitKey(0)