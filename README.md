# Overclock Console | Hardware-to-Software Macro Controller

A personal portfolio project bridging physical hardware inputs with OS-level automation. This project features an **Arduino Uno** control pad that communicates over a serial interface with a **Python background daemon** to instantly launch productivity tools, native apps, and web environments at the press of a physical button.

---

## 📺 Project Demo

[![Watch the Demo](https://img.shields.io/badge/YouTube-Demo_Video-red?style=for-the-badge&logo=youtube)](YOUR_YOUTUBE_VIDEO_LINK_HERE)

*Click the badge above to watch the live demo showing hardware tactile inputs triggering real-time OS actions.*

---

## Tech Stack & Architecture

* **Hardware Layer:** Arduino Uno, Tactile Switches, Internal Pull-Up Resistors
* **Firmware:** Embedded C++ (Arduino)
* **Software/Backend:** Python 3, `pyserial` (Serial communication), `AppOpener` (Application dispatching), `webbrowser` (Automation)

```
[ Physical Button Press ] 
           │
           ▼ (Low Signal via INPUT_PULLUP)
 [ Arduino Uno Firmware ] 
           │
           ▼ (Serial Data Stream @ 9600 Baud)
  [ Python Background Daemon ] 
           │
           ▼ (OS System Call / Web API)
[ Target App / URL Launches ]
```

---

## System Design & Schematics

The circuit leverages internal pull-up resistors (`INPUT_PULLUP`) to maintain a clean digital HIGH state until a button press pulls the logic level LOW, eliminating the need for external pull-down resistors and ensuring hardware debouncing via software sequencing.


---

## Codebase Showcase

### 1. Firmware Implementation (`ArduinoCode.cpp`)
Efficiently monitors digital pins 10-13, implementing sequential conditional checking to stream light-weight macro triggers over the hardware serial buffer.

```cpp
const int W = 10;
const int A = 11;
const int S = 12;
const int D = 13;

void setup() {
  Serial.begin(9600);
  pinMode(W, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(S, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(W) == LOW) {
    Serial.print("W\n");
  }
  else if (digitalRead(A) == LOW) {
    Serial.print("A\n");
  }
  else if (digitalRead(S) == LOW) {
    Serial.print("S\n");
  }
  else if (digitalRead(D) == LOW) {
    Serial.print("D\n");
  }
}
```

### 2. Python Automation Daemon (`Console.py`)
An asynchronous-like polling loop that decodes incoming data streams from the microcontroller's COM port and matches inputs against native system paths and browser routing actions.

```python
import serial
import webbrowser
from AppOpener import open

# Establish connection with the microcontroller
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)

print("Overclock Console: Listening for hardware events...")

while True:
    data = arduino.readline().decode('utf-8').strip()

    if data == "W":
        print("Event Detected: W -> Launching Browser...")
        webbrowser.open("[https://www.youtube.com/@MylesHendler-VossPortfolioofPr](https://www.youtube.com/@MylesHendler-VossPortfolioofPr)")
    elif data == "A":
        print("Event Detected: A -> Launching Nvidia App...")
        open("Nvidia App")
    elif data == "S":
        print("Event Detected: S -> Launching Cookie Clicker...")
        open("Cookie Clicker")
```

---

## 💡 Key Engineering Takeaways
* **Hardware Efficiency:** Reduced physical component counts by handling pull-up logic via internal microcontroller registers.
* **Cross-Language Integration:** Implemented efficient data serialization over USB COM ports to seamlessly connect low-level firmware with a high-level scripting language.
