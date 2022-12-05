import utime
from machine import Pin

lmotorm1 = Pin(14, Pin.OUT)
lmotorm2 = Pin(15, Pin.OUT)

def forward():
   lmotorm1.high()
   lmotorm2.low()

def backward():
   lmotorm1.low()
   lmotorm2.high()

def stop():
   lmotorm1.low()
   lmotorm2.low()

def test():
   forward()
   utime.sleep(2)
   backward()
   utime.sleep(2)
   stop()

for i in range(5):
	test()
