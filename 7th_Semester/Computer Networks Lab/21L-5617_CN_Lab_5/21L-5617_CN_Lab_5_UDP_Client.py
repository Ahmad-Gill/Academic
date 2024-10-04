import socket

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('127.0.0.1', 2000)

try:
    while True:
        client_message = input("Enter Message (format: YY-AAAA-CI or YY-AAAA-CO, type 'ok' to exit): ")
        if client_message.lower() == "ok":
            print("Exiting the client.")
            break
        sock.sendto(client_message.encode(), server_address)
        server_message, _ = sock.recvfrom(2000)
        print(f"Server Message: {server_message.decode()}")

except Exception as e:
    print(f"An error occurred: {e}")

finally:
    sock.close()
