import socket
import threading

def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024).decode('utf-8')
        
        if data == 'done':
            break
        inverted_for_server = ' '.join([word[::-1] if any(v in word for v in "aeiouAEIOU") else word for word in data.split()])
        print(f"Server received (inverted vowels only): {inverted_for_server}")
        inverted_for_client = ' '.join([word[::-1] for word in data.split()])
        client_socket.send(inverted_for_client.encode('utf-8'))
    
    client_socket.close()

# Set up the server
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1', 12345))
server_socket.listen()

print("Server started, waiting for clients...")

while True:
    client_socket, addr = server_socket.accept()
    print(f"Client connected from {addr}")
    threading.Thread(target=handle_client, args=(client_socket,)).start()
