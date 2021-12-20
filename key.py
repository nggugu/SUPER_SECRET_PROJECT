from pynput import keyboard
import serial
import subprocess
import time

bashCommand = "sudo chmod 666 /dev/ttyUSB0"
output = subprocess.check_output(['bash','-c', bashCommand])

SERIALPORT = "/dev/ttyUSB0"
BAUDRATE = 115200

ser = serial.Serial(SERIALPORT, BAUDRATE)

ser.bytesize = serial.EIGHTBITS #number of bits per bytes

ser.parity = serial.PARITY_NONE #set parity check: no parity

ser.stopbits = serial.STOPBITS_ONE #number of stop bits

ser.timeout = 2              #timeout block read

ser.xonxoff = False     #disable software flow control

ser.rtscts = False     #disable hardware (RTS/CTS) flow control

ser.dsrdtr = False       #disable hardware (DSR/DTR) flow control

ser.writeTimeout = 0     #timeout for write


if (ser.isOpen() == False):
	ser.open()

ser.flushInput() #flush input buffer, discarding all its contents
ser.flushOutput() #flush output buffer, aborting current output


plus="+"
minus="-"


pressed = {}

def on_press(key):

    letter=str(key)

    if key not in pressed: # Key was never pressed before
        pressed[key] = False

    if not pressed[key]: # Same logic
        pressed[key] = True
#        ser.write(plus.encode())
#        time.sleep(100/1000)
        ser.write(letter.encode())

def on_release(key):  # Same logic
    letter=str(key)
    pressed[key] = False
#    ser.write(minus.encode())
#    time.sleep(100/1000)
    ser.write(letter.encode())

# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()

# ...or, in a non-blocking fashion:
listener = keyboard.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()

