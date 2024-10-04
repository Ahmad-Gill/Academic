import socket


client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)    #use IPv4    AF_NET address family     SOCK_STREAM==TCP conection

# Connect to the server running on localhost at port 12345
client_socket.connect(('127.0.0.1', 12345))

while True:
    message = input("Enter message (or 'DISCONNECT' to quit): ")

    client_socket.send(message.encode('utf-8'))
    if message == 'DISCONNECT':
        break
    try:
        response = client_socket.recv(1024).decode('utf-8')
        print(f"Server response: {response}")
    except (ConnectionResetError, ConnectionAbortedError):
        print("Connection was aborted by the host or reset by the server.")
        client_socket.close()
        break

client_socket.close()
