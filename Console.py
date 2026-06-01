import serial
import webbrowser
from AppOpener import open
# Change 'COM3' to whatever port your Arduino is on (check Arduino IDE)
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)

print("Overclock Console: Listening...")

while True:
    data = arduino.readline().decode('utf-8').strip()

    if data == "W":
        print("Button W pressed! Launching Browser...")
        webbrowser.open("https://www.youtube.com/@MylesHendler-VossPortfolioofPr")
    elif data == "A":
        print("Button A pressed! Launching Nvidia App...")
        open("Nvidia App")
    elif data == "S":
        print("Button S pressed! Launching Cookie Clicker...")
        open("Cookie Clicker")