import mediapipe as mp
import time
import cv2
import math

cap = cv2.VideoCapture(0)
cap.set(3, 800)
cap.set(4, 600)


class poseDetector():

    def __init__(self, mode=False, upBody=False, smooth=True, detectionCon=0.5, trackCon=0.5):
        self.mode = mode
        self.upbody = upBody
        self.smooth = smooth
        self.detectionCon = detectionCon
        self.trackCon = trackCon

        self.mpDraw = mp.solutions.drawing_utils
        self.mypose = mp.solutions.pose
        self.pose = self.mypose.Pose()

    def findPos(self, img, Draw=True):

        imgRBG = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.pose.process(imgRBG)

        if self.results.pose_landmarks:
            if Draw:
                self.mpDraw.draw_landmarks(
                    img, self.results.pose_landmarks, self.mypose.POSE_CONNECTIONS)

        return img

    def findpoints(self, img, Draw=True):
        self.lmlist = []
        if self.results.pose_landmarks:
            for id, lm in enumerate(self.results.pose_landmarks.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x*w), int(lm.y*h)

                self.lmlist.append([id, cx, cy])

                if Draw:
                    cv2.circle(img, (cx, cy), 5, (0, 255, 0), 3, cv2.FILLED)

        return self.lmlist

    def findAngle(self, img, p1, p2, p3, Draw=True):
        x1, y1 = self.lmlist[p1][1:]
        x2, y2 = self.lmlist[p2][1:]
        x3, y3 = self.lmlist[p3][1:]
        
        angle = math.degrees(math.atan2(y3-y2, x3-x2) - math.atan2(y1-y2, x1-x2))
        
        if angle < 0:
            angle += 360
        
        if Draw:
            cv2.line(img, (x1,y1), (x2, y2), (0,0,0), 5)
            cv2.line(img, (x3,y3), (x2, y2), (0,0,0), 5)
            cv2.circle(img, (x1, y1), 5, (255, 0, 0), cv2.FILLED)
            cv2.circle(img, (x1, y1), 10, (255, 0, 0), 3)
            cv2.circle(img, (x2, y2), 5, (255, 0, 0), cv2.FILLED)
            cv2.circle(img, (x2, y2), 10, (255, 0, 0), 3)
            cv2.circle(img, (x3, y3), 5, (255, 0, 0), cv2.FILLED)
            cv2.circle(img, (x3, y3), 10, (255, 0, 0), 3)
        
        return angle

def main():
    pTime = 0

    detector = poseDetector()
    while True:
        success, img = cap.read()

        img = detector.findPos(img)

        lmlist = detector.findpoints(img)

        print(lmlist)

        cTime = time.time()
        fps = 1/(cTime - pTime)
        pTime = cTime
        cv2.putText(img, str(int(fps)), (40, 70),
                    cv2.FONT_HERSHEY_COMPLEX, 3, (0, 0, 255), 3, cv2.FILLED)

        # img = cv2.resize(img, (400 ,600))

        cv2.imshow("Image", img)
        cv2.waitKey(1)


if __name__ == "__main__":
    main()
