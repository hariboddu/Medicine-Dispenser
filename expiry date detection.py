import datetime
import re
import sys
import os
now = datetime.datetime.now()
print(now)
import pytesseract
from PIL import Image
import cv2
import os


f2 = pytesseract.image_to_string(Image.open('5.jpg'),lang='eng')



f = open('save.txt','w')
f2 = f2.encode('utf-8')
f.write(f2)
date_list = []

if f2 == []:
	print("No data has been processed from image")
	sys.exit()

        
#print("10")
#x = re.findall(r"^\d.*\d",f2)
x1 = re.findall(r"\d{4}[-/.]\d{2}[-/.]\d{2}",f2)
if x1!=[] :
	#print("1")
	validbef=0
	for i in range(len(x1)) :
		year = int(x1[i][0:4],10)
		month  = int(x1[i][5:7],10)
		if year>=now.year and year<=2022:		
			if month<=12 and month>0  :
				if month>=now.month :
					#print(x1)
					print("Not Expired!!")
					sys.exit()
				else:
					print("Expired")
					#print(x1)
					sys.exit()
					
		else:
			if month<=12 and month>0  :
				if validbef<=2 :
					validbef=validbef+1
				else :
					break
	if validbef==2:
		print("Expired")
		#print(x1)
		sys.exit()
	elif validbef==1:
		print("Not Sure")
		sys.exit()
#print("11")
x2 = re.findall(r"\d{2}[-/.]\d{2}[-/.]\d{4}",f2)
if x2!=[] :
	#print("2")
	validbef=0
	for i in range(len(x2)) :
		year = int(x2[i][6:10],10)
		month  = int(x2[i][3:5],10)
		if year>=now.year and year<=2022:		
			if month<=12 and month>0  :
				if month>=now.month :
					print("Not Expired!!")
					#print(x2)
					sys.exit()
				else:
					print("Expired")
					#print(x2)
					sys.exit()
					
		else:
			if month<=12 and month>0  :
				if validbef<=2 :
					validbef=validbef+1
				else :
					break
	if validbef==2:
		print("Expired")
		sys.exit()
	elif validbef==1:
		print("Not Sure")
		sys.exit()

x3 = re.findall(r"\d{2}[-/.]\d{4}",f2)
if x3!=[] :
	#print("3")
	validbef=0
	for i in range(len(x3)) :
		year = int(x3[i][3:7],10)
		month  = int(x3[i][0:2],10)
		if year>=now.year and year<=2022:		
			if month<=12 and month>0  :
				if month>=now.month :
					print("Not Expired!!")
					#print(x3)
					sys.exit()
				else:
					print("Expired")
					#print(x3)
					sys.exit()
					
		else:
			if month<=12 and month>0  :
				if validbef<=2 :
					validbef=validbef+1
				else :
					break
	if validbef==2:
		print("Expired")
		sys.exit()
	elif validbef==1:
		print("Not Sure")
		sys.exit()

x4 = re.findall(r"\d{4}[-/.]\d{2}",f2)
if x4!=[] :
	#print("4")
	validbef=0
	for i in range(len(x4)) :
		year = int(x4[i][0:4],10)
		month  = int(x4[i][5:7],10)
		if year>=now.year and year<=2022:		
			if month<=12 and month>0  :
				if month>=now.month :
					print("Not Expired!!")
					#print(x4)
					sys.exit()
				else:
					print("Expired")
					#print(x4)
					sys.exit()
					
		else:
			if month<=12 and month>0  :
				if validbef<=2 :
					validbef=validbef+1
				else :
					break
	if validbef==2:
		print("Expired")
		sys.exit()
	elif validbef==1:
		print("Not Sure")
		sys.exit()


print("Text extracted doesn't contain any dates")
sys.exit()








