import socket
import threading

active_clients = 0
max_clients = 3

def handle_client(client_socket):
    global active_clients
    while True:
        data = client_socket.recv(1024).decode('utf-8')
        if data == 'DISCONNECT':
            break
        modified_data = f"Server echo: {data}"  
        client_socket.send(modified_data.encode('utf-8'))
        print(f"Sent to client: {modified_data}")
    client_socket.close()
    active_clients -= 1

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1', 12345))
server_socket.listen()

print("Server started, waiting for clients...")

while True:
    client_socket, addr = server_socket.accept()

    if active_clients < max_clients:
        print(f"Client connected from {addr}")
        active_clients += 1
        threading.Thread(target=handle_client, args=(client_socket,)).start()
    else:
        print("Server Full, waiting for a client to disconnect.")
        client_socket.send("Server Full".encode('utf-8'))
        client_socket.close()
