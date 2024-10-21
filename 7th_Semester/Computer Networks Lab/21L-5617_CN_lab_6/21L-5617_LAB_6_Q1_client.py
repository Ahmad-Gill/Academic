import socket


client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)    #use IPv4    AF_NET address family     SOCK_STREAM==TCP conection

# Connect to the server running on localhost at port 12345
client_socket.connect(('127.0.0.1', 12345))

while True:
    message = input("Enter message your id is 0-9: ")
    while True:
        message = input("Enter message (format: 'helo i am client my id is 0-9'): ")
        
        if message.startswith("helo i am client my id is") and message.split()[-1].isdigit():
            client_id = message.split()[-1]
            
            if 0 <= int(client_id) <= 9:
                client_socket.send(message.encode('utf-8'))
                break  
            else:
                print("Error: ID is out of range (0-9).")
        else:
            print("Error: Invalid message format.")



    try:
        response = client_socket.recv(1024).decode('utf-8')
        print(f"Server response: {response}")
    except (ConnectionResetError, ConnectionAbortedError):
        print("Connection was aborted by the host or reset by the server.")
        client_socket.close()
        break

client_socket.close()
