import tkinter as tk
from tkinter import *
import threading
import cv2
from PIL import Image, ImageTk
import os
import sys
import webbrowser
import datetime
import serial
import threading
import time
from tkintermapview import TkinterMapView
import pygame
import numpy as np
import dlib
from imutils import face_utils
import RPi.GPIO as GPIO



def resource_path(relative_path):   
    try:       
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)

#to initialize the video of GUI
def play_video():
    cap = cv2.VideoCapture("Documents//Downloads//WhatsApp Video 2023-01-27 at 14.09.02.mp4")  # Replace with your video file path
    while True:
        ret, frame = cap.read()
        if not ret:
            cap.release()
            break
        frame = cv2.resize(frame, (root.winfo_screenwidth(), root.winfo_screenheight()))
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        photo = ImageTk.PhotoImage(image=Image.fromarray(frame))
        label.config(image=photo)
        label.photo = photo
        root.update()
    cap.release()

#To exit the fullscreen
def exit_fullscreen(event):
    root.attributes("-fullscreen", False)
    root.destroy()

#To create NEW MAP window on already existing window
def open_map_window():
    # Create a new window
    map_window = tk.Toplevel(root)
    map_widget = TkinterMapView(map_window , width=600 ,height=400, corner_radius =0)
    map_widget.pack(fill="both",expand=True)

    map_widget.set_tile_server("https://mt0.google.com/vt/lyrc=m&hl=en&x={x}&y={y}&z={z}&s=Ga",max_zoom=22)

    map_widget.set_address("Pune India",marker=True)

    # Set the geometry to place it on the right side of the screen
    window_width = 850  # Width of the new window
    screen_width = root.winfo_screenwidth()  # Width of the screen
    x_position = screen_width - window_width  # Calculate the X position
    map_window.geometry(f"{window_width}x800+{x_position}+0")

def music_player():
    music_window = Toplevel(root)
    music_window.title("Music Player")
    screen_width = music_window.winfo_screenwidth()
    screen_height = music_window.winfo_screenheight()
    window_width = 200  # Width of the new window
    window_height = 200  # Height of the new window
    x_position = screen_width - window_width  # Calculate the x position
    y_position = 0  # You can adjust this value if needed
    music_window.geometry(f"{window_width}x{window_height}+{x_position}+{y_position}")
    pygame.mixer.init()

    # List of songs
    songs = [
        "Documents/Downloads/Arjan Vailly Animal.mp3",
        "Documents/Downloads/O Maahi Dunki.mp3",
        "Documents/Downloads/Papa Meri Jaan.mp3",
        "Documents/Downloads/Abrars Entry Jamal.mp3",
    ]

    def play(selected_song):
        pygame.mixer.music.load(selected_song)
        pygame.mixer.music.play(loops=0)

    # Callback function for the "Play Song" button
    def play_selected_song():
        selected_song = song_var.get()
        if selected_song:
            play(selected_song)

    # Dropdown menu for song selection
    song_var = StringVar(music_window)
    song_var.set(songs[0])  # Set default song
    song_menu = OptionMenu(music_window, song_var, *songs)
    song_menu.pack(pady=10)

    # Button to play the selected song
    play_button = Button(music_window, text="Play Selected Song", font=("Helvetica", 16), command=play_selected_song)
    play_button.pack(pady=10)



#To create NEW Camera Window on already existing window
def start_camera_stream():
    new_window = tk.Toplevel(root)
    new_window.title("Camera Stream")
    screen_width = new_window.winfo_screenwidth()
    screen_height = new_window.winfo_screenheight()
    window_width = 640  # Width of the new window
    window_height = 480  # Height of the new window
    x_position = 0  # Place it on the left side
    y_position = 0  # You can adjust this value if needed
    new_window.geometry(f"{window_width}x{window_height}+{x_position}+{y_position}")
    cap = cv2.VideoCapture(0)  # Use the default camera (change the index if needed)

    def update_camera_stream():
        ret, frame = cap.read()
        if ret:
            # Define points and colors
            pt1 = (80, 400)  # HORIZONTAL RED LEFT
            pt2 = (520, 400)  # HORIZONTAL RED RIGHT
            pt3 = (45, 480)  # VERTICAL RED LOWER LEFT
            pt4 = (560, 480)  # VERTICAL RED LOWER RIGHT
            pt5 = (140, 300)  # HORIZONTAL YELLOW LEFT
            pt6 = (470, 300)  # HORIZONTAL YELLOW RIGHT
            pt7 = (200, 200)  # HORIZONTAL GREEN LEFT
            pt8 = (410, 200)  # HORIZONTAL GREEN RIGHT
            color_red = (0, 0, 255)
            color_yellow = (0, 255, 255)
            color_green = (0, 255, 0)

# Draw red gridlines
            cv2.line(frame, pt1, pt2, color_red, thickness=2, lineType=8)
            cv2.line(frame, pt3, pt1, color_red, thickness=2)
            cv2.line(frame, pt4, pt2, color_red, thickness=2)

# Draw yellow gridlines
            cv2.line(frame, pt5, pt6, color_yellow, thickness=2)
            cv2.line(frame, pt1, pt5, color_yellow, thickness=2)
            cv2.line(frame, pt2, pt6, color_yellow, thickness=2)

# Draw green gridlines
            cv2.line(frame, pt7, pt8, color_green, thickness=2)
            cv2.line(frame, pt5, pt7, color_green, thickness=2)
            cv2.line(frame, pt6, pt8, color_green, thickness=2)

            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            photo = ImageTk.PhotoImage(image=Image.fromarray(frame))
            label.config(image=photo)
            label.photo = photo
            new_window.after(10, update_camera_stream)

    label = tk.Label(new_window)
    label.pack()
    update_camera_stream()


# GPIO setup
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
buzzer_pin = 36
LED_PIN = 29
GPIO.setup(buzzer_pin, GPIO.OUT)
GPIO.setup(LED_PIN, GPIO.OUT)

# Initializing the camera and taking the instance
cap = cv2.VideoCapture(0)

# Initializing the face detector and landmark detector
hog_face_detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")

# Status marking for the current state
sleep = 0
drowsy = 0
active = 0
status = ""
color = (0, 0, 0)

# Global variable to keep track of whether drowsiness detection is active
drowsiness_detection_active = False

def start_stop_drowsiness_detection():
    global drowsiness_detection_active
    drowsiness_detection_active = not drowsiness_detection_active

    if drowsiness_detection_active:
        # Reset GPIO and start the detection thread
        GPIO.output(buzzer_pin, GPIO.LOW)
        GPIO.output(LED_PIN, GPIO.LOW)
        detection_thread = threading.Thread(target=drowsiness_detection)
        detection_thread.start()
    else:
        # Stop the detection thread and cleanup GPIO
        GPIO.output(buzzer_pin, GPIO.LOW)
        GPIO.output(LED_PIN, GPIO.LOW)

def compute(ptA, ptB):
    dist = np.linalg.norm(ptA - ptB)
    return dist

def blinked(a, b, c, d, e, f):
    up = compute(b, d) + compute(c, e)
    down = compute(a, f)
    ratio = up / (2.0 * down)

    # Checking if it is blinked
    if ratio > 0.25:
        return 2
    elif 0.21 < ratio <= 0.25:
        return 1
    else:
        return 0

def drowsiness_detection():
    global drowsiness_detection_active
    global sleep, drowsy, active, status, color

    while drowsiness_detection_active:
        _, frame = cap.read()
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = hog_face_detector(gray)

        for face in faces:
            x1, y1, x2, y2 = face.left(), face.top(), face.right(), face.bottom()
            face_frame = frame.copy()
            cv2.rectangle(face_frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

            landmarks = predictor(gray, face)
            landmarks = face_utils.shape_to_np(landmarks)

            left_blink = blinked(landmarks[36], landmarks[37], landmarks[38],
                                 landmarks[41], landmarks[40], landmarks[39])
            right_blink = blinked(landmarks[42], landmarks[43],
                                  landmarks[44], landmarks[47], landmarks[46], landmarks[45])

            if left_blink == 0 or right_blink == 0:
                sleep += 1
                drowsy = 0
                active = 0
                if sleep > 1:
                    status = "SLEEPING !!!"
                    print("SLEEPING !!!")
                    GPIO.output(buzzer_pin, GPIO.HIGH)
                    GPIO.output(LED_PIN, GPIO.HIGH)

                    time.sleep(0.2)
                    color = (0, 0, 255)

            elif 0.21 < left_blink <= 0.25 or 0.21 < right_blink <= 0.25:
                sleep = 0
                active = 0
                drowsy += 1
                if drowsy > 1:
                    status = "Drowsy !"
                    GPIO.output(buzzer_pin, GPIO.HIGH)
                    GPIO.output(LED_PIN, GPIO.HIGH)

                    time.sleep(0.2)
                    color = (0, 0, 255)

            else:
                drowsy = 0
                sleep = 0
                active += 1
                if active > 1:
                    status = "Active :)"
                    print("Active !!!")

                    GPIO.output(buzzer_pin, GPIO.LOW)
                    GPIO.output(LED_PIN, GPIO.LOW)
                    color = (0, 0, 255)

            cv2.putText(frame, status, (100, 100), cv2.FONT_HERSHEY_SIMPLEX, 1.2, color, 3)

            for n in range(0, 68):
                (x, y) = landmarks[n]
                cv2.circle(face_frame, (x, y), 1, (255, 255, 255), -1)

        cv2.imshow("Frame", frame)
        key = cv2.waitKey(1)
        if key == 27:
            break

#main GUI Window
root = tk.Tk()
root.attributes("-fullscreen", True)
label = tk.Label(root)
label.pack(fill="both", expand=True)
root.bind("<Escape>", exit_fullscreen)

# Add Buttons and other widgets on GUI once the video is launched
def add_buttons_and_widgets():
   
    

# Music Button
    music_button = tk.Button(root,text="music", font=("Helvectia",10),fg="black",bg="white",command=music_player)
    music_button.place(relx=0.55, rely=0.230, height=50, width=150)

# Navigation Button
    navigation_button = tk.Button(root,text="navigation",font=("Helvectia",10),fg="black",bg="white",command=open_map_window)
    navigation_button.place(relx=0.55,rely=0.453,height=55,width=150)

# Reverse_parking Button
    reverse_button = tk.Button(root,text="reverse parking",font=("Helvectia",10),fg="black",bg="white",command=start_camera_stream)
    reverse_button.place(relx=0.880,rely=0.220,height=50,width=150)
    
# Collision warning
    start_stop_button = tk.Button(root, text="Innovation" if drowsiness_detection_active else "Start Drowsiness Detection", command=start_stop_drowsiness_detection)
    start_stop_button.place(relx=0.880,rely=0.450,height=55,width=150)
   
# Exit
    exit_button = tk.Button(root,text="Exit",font=("Helvectia",10),fg="black",bg="white",command=root.destroy)
    exit_button.place(relx=0.55,rely=0.690,height=50,width=150)



# Initial values
value1 = 50
value2 = 250

# Time interval (in seconds) for increasing/decreasing values
interval = 5  # Change this to your desired interval

# Create a function to update the labels
def update_labels():
    global value1, value2,label1,label2
    if value1 > 36:
        value1 -= 2
    if value2 > 180:
        value2 -= 10
    # Create a label to display the values
    label1 = tk.Label(root, text=value1,font=("Calibri",35),fg="white",bg="black")
    label1.place(relx=0.350,rely=0.332)
    # Create another table to display the values
    label2 = tk.Label(root,text=value2,font=("Calibri",35),fg="white",bg="black")
    label2.place(relx=0.350,rely=0.580)
    # Call this function again after the specified interval
    root.after(interval * 1000, update_labels)

# Create a function to update the GUI label with received serial data
def read_serial(port, label):
    ser = serial.Serial(port, 9600)  # Replace 'port' with the actual serial port name
    while True:
        data = ser.readline().decode('utf-8').strip()  # Read and decode data from the serial port
        label.config(text=data)  # Update the GUI label with the received data
        time.sleep(1)  # Add a 1-second delay between updates

        # Check if the data exceeds 25 and change label color accordingly
        if float(data) > 25:
            label.config(fg="red")  # Change label text color to red
        else:
            label.config(fg="white")  # Set label text color back to white if the condition is not met

        time.sleep(1)  # Add a 3-second delay between updates


# Real-time data Display Labels
def start_after_video():
    # Speed Label
    speed_label = tk.Label(root,text="",font=("Calibri",20),fg="white",bg="black")
    speed_label.place(relx=0.120,rely=0.460)

    # Start threads to read serial data and update the GUI for each port
    serial_thread1 = threading.Thread(target=read_serial, args=('/dev/ttyACM0', speed_label))
    serial_thread1.daemon = True
    serial_thread1.start()



      


 # Start playing the video in the background
video_thread = threading.Thread(target=play_video)
video_thread.daemon = True
video_thread.start()


# After playing the video, wait for a few seconds and then add buttons and widgets
root.after(10000, add_buttons_and_widgets)  # Delay adding widgets for 5 seconds

root.after(13000,start_after_video)        # Delay updating real-time-data for 12 seconds

root.after(13000,update_labels)           # battery level and drive range information



# Run the GUI
root.mainloop()