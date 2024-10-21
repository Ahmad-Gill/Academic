import socket
import threading


def handle_client(client_socket):
    global active_clients
    while True:
        data = client_socket.recv(1024).decode('utf-8')
        client_id = data.split()[-1]
        server_response = f"Hello, I am the server. Your ID is {client_id}"
        print(f"Server recieve: {data}")
        print(f"Server response: {server_response}")
        if data == 'done':
            break
        client_socket.send(server_response.encode('utf-8'))
    client_socket.close()
    active_clients -= 1

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1', 12345))
server_socket.listen()

print("Server started, waiting for clients...")

while True:
    client_socket, addr = server_socket.accept()
    print(f"Client connected from {addr}")
    threading.Thread(target=handle_client, args=(client_socket,)).start()
