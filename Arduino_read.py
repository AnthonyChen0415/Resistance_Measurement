import time
import serial
n = 0
flag = 1
ser = serial.Serial(
  port = 'COM4',
  baudrate = 9600,
  parity = serial.PARITY_ODD,
  stopbits = serial.STOPBITS_TWO,
  bytesize = serial.SEVENBITS
)
data = ''
#ser.write(b'1')
while flag:
  data = ser.readline()
  #if data.strip()=="begin":
  f = open('F:/Master/MasterThesis/res/test.txt','a')
  result = data.strip()
  f.write(bytes.decode(result)+'\n')
  print(data)
  n = n+1
  if n == 10:
      flag = 0
  #if data.strip() == " b'10' ":
      #f.close()
      #break
