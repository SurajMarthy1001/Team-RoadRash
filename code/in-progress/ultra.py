from machine import Pin
import utime
trigger = Pin(16, Pin.OUT)
echo = Pin(17, Pin.IN)
#htrigger = Pin(0, Pin.OUT)
#hecho = Pin(1, Pin.IN)
def ultra():
    
   trigger.low()
   #htrigger.low()
   utime.sleep_us(2)
   trigger.high()
   #htrigger.high()
   utime.sleep_us(5)
   trigger.low()
   #htrigger.low()
   
   while echo.value() == 0:
       signaloff = utime.ticks_us()
   while echo.value() == 1:
       signalon = utime.ticks_us()
   timepassed = signalon - signaloff
   distance = (timepassed * 0.0343) / 2
   
#    while hecho.value() == 0:
#        rsignaloff = utime.ticks_us()
#    while hecho.value() == 1:
#        rsignalon = utime.ticks_us()
#    rtimepassed = rsignalon - rsignaloff
#    rdistance = (rtimepassed * 0.0343) / 2
#    
   print("L:",distance)
while True:
   ultra()
   utime.sleep(0.25)
