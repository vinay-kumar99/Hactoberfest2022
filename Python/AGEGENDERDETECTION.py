# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 08:51:30 2020

@author: Lenovo
"""


import cv2
import face_recognition

webcam_video_stream=cv2.VideoCapture(0)
all_face_locations=[]

while True:
    r,current_frame=webcam_video_stream.read()
    current_frame_small=cv2.resize(current_frame,(0,0),fx=0.25,fy=0.25)
    #no_of_times_to_upsample
    all_face_locations=face_recognition.face_locations(current_frame_small,number_of_times_to_upsample=2,model='hog')
    for index,current_face_locations in enumerate(all_face_locations):
        top_pos,right_pos,bottom_pos,left_pos=current_face_locations
        top_pos=top_pos*4
        right_pos=right_pos*4
        bottom_pos=bottom_pos*4
        left_pos=left_pos*4
        print("Face found {} at top:{},right:{},bottom:{},left:{}".format(index+1,top_pos,right_pos,bottom_pos,left_pos))
        current_face_image=current_frame[top_pos:bottom_pos,left_pos:right_pos]
        AGMEANVALUES=(78.4263377603,87.7689143744,114.895847746)
        faceimageblob=cv2.dnn.blobFromImage(current_face_image,1,(227,227),AGMEANVALUES,swapRB=False)
        #GENDER
        genderlabel=['MALE','FEMALE']
        genderprotext='dataset/gender_deploy.prototxt'
        gendercaffemodel='dataset/gender_net.caffemodel'
        gendercov=cv2.dnn.readNet(gendercaffemodel,genderprotext)
        gendercov.setInput(faceimageblob)
        genderprediction=gendercov.forward()
        gender=genderlabel[genderprediction[0].argmax()]
        #AGE
        agelist=['(0-2)','(4-6)','(8-12)','(15-20)','(25-32)','(38-43)','(48-53)','(60-100)']
        ageprotext='dataset/age_deploy.prototxt'
        agecaffemodel='dataset/age_net.caffemodel'
        agecov=cv2.dnn.readNet(agecaffemodel,ageprotext)
        agecov.setInput(faceimageblob)
        ageprediction=agecov.forward()
        age=agelist[ageprediction[0].argmax()]
        cv2.rectangle(current_frame,(left_pos,top_pos),(right_pos,bottom_pos),(0,0,255),2)
        
        font=cv2.FONT_HERSHEY_DUPLEX
        cv2.putText(current_frame,gender+" "+age+"years",(left_pos-50,bottom_pos+32),font,1,(0,255,0),1)
    
    cv2.imshow("Webcam video",current_frame)
        
    if cv2.waitKey(1)&0xFF==ord('q'):
        break
    
webcam_video_stream.release()
cv2.destroyAllWindows()
