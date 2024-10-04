import socket
import threading
import re 


STUDENT_FILE = 'STUDENT_FILE.txt'




def get_total_students():
    with open(STUDENT_FILE, 'r') as file:
        students = file.readlines()
    return [s.strip() for s in students]                            # Return list of roll numbers
def check_in(roll_number):
    with open(STUDENT_FILE, 'r') as file:
        students = file.readlines()
    students = [s.strip() for s in students]  
    if roll_number in students:
        return False  #                                              Student is already checked in

    with open(STUDENT_FILE, 'a') as file:
        file.write(roll_number + '\n')                                 # Append new student
    return True  

def check_out(roll_number):
    with open(STUDENT_FILE, 'r') as file:
        students = file.readlines()
    students = [s.strip() for s in students]                                 # Retrieve all students 

    if roll_number in students:
        students.remove(roll_number)                                     # Remove specific student 
        with open(STUDENT_FILE, 'w') as file:
            for student in students:
                file.write(student + '\n')                                       # Write back remaining students
        return True
    return False

def is_valid_format(message):
    pattern = r'^[A-Z0-9]{2}-[A-Z0-9]{4}-(CI|CO)$'
    return re.match(pattern, message) is not None

def handle_client(client_message, client_address):
    message = client_message.decode()
    print(f"Received message: {message} from {client_address}")
    if not is_valid_format(message):
        response = "Invalid format. Use YY-AAAA-CI or YY-AAAA-CO."
    else:
        parts = message.split('-')
        roll_number = parts[0] + '-' + parts[1]
        action = parts[2]

        if action == "CI":                                                              # Check-in
            if check_in(roll_number):
                response = f"Welcome Student {roll_number}!"
            else:
                response = "You are already checked in."
        elif action == "CO":                                                                     # Check-out
            if check_out(roll_number):
                response = f"Goodbye Student {roll_number}! Have a nice day."
            else:
                response = "You didn't check in today."
        else:
            response = "Invalid action. Use 'CI' for check-in and 'CO' for check-out."
    total_students = get_total_students()
    print("Total Students are = ",total_students)
    sock.sendto(response.encode(), client_address)

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('127.0.0.1', 2000))
print("Server is listening for messages...\n")

while True:
    client_message, client_address = sock.recvfrom(2000)
    
    threading.Thread(target=handle_client, args=(client_message, client_address)).start()
