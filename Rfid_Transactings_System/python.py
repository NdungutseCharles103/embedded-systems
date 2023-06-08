import serial
import time

# Create a serial object with the same baud rate as Arduino
ser = serial.Serial('COM17', 9600)

# Wait for the connection to be established
time.sleep(2)

# # Send a character to Arduino to start the communication
print('Press any key to start connection...')
initializer = input()
ser.write(initializer.encode())

# Read the money amount from Arduino
money = ser.readline().decode('utf-8').strip()
print(f"Available Money: ${money}")

# Read the points amount from Arduino
points = ser.readline().decode('utf-8').strip()
print(f"Available Points: {points}")

# Read the prompt from Arduino
prompt = ser.readline().decode('utf-8').strip()
print(prompt)

# Enter 'm' or 'p' to use money or points
choice = input()

# Send the choice to Arduino
ser.write(choice.encode())

# Read the response from Arduino
response = ser.readline().decode('utf-8').strip()
print(response)

# Enter the amount to deduct from money or points
amount = input()

# Send the amount to Arduino
ser.write(amount.encode())

# Read the final message from Arduino
message = ser.readline().decode('utf-8').strip()
print(message)

# Close the serial connection
ser.close()
