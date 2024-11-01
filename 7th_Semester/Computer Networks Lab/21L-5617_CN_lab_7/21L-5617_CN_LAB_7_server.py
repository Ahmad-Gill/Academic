import socket
import threading
import re  
VOTERS_LIST_FILE = "Voters_List.txt"
CANDIDATES_LIST_FILE = "Candidates_List.txt"
VOTES_OUTPUT_FILE = "Votes.txt"

def is_valid_cnic(cnic):
    pattern = r'^\d{5}-\d{7}-\d{1}$'
    return re.match(pattern, cnic) is not None

def handle_client(client_socket):
    try:
        client_data = client_socket.recv(1024).decode()
        name, cnic = client_data.split(',')
        if not is_valid_cnic(cnic):
            client_socket.sendall("Invalid CNIC format. Please try again.\n".encode())
            return

        with open(VOTERS_LIST_FILE, 'r') as f:
            registered_voters = f.read().splitlines()
        with open(VOTES_OUTPUT_FILE, 'r') as f:
                votes = f.read().splitlines()

        if any(f"{name}/{cnic}" in vote for vote in votes):
                client_socket.sendall("Error: You have already cast your vote".encode())
                return

        if f"{name}/{cnic}" in registered_voters:
            client_socket.sendall("Authenticated! Here are the candidates:\n".encode())
            with open(CANDIDATES_LIST_FILE, 'r') as f:
                candidates = f.readlines()
                candidates_string = ''.join(candidates)
            client_socket.sendall(candidates_string.encode() + b'\n')
            with open(VOTES_OUTPUT_FILE, 'r') as f:
                votes = f.read().splitlines()

            if any(f"{name}/{cnic}" in vote for vote in votes):
                client_socket.sendall("Error: You have already cast your vote".encode())
                return
            vote = client_socket.recv(1024).decode().strip()
            with open(CANDIDATES_LIST_FILE, 'r') as f:
                candidates = f.readlines()
                accepted_votes = [candidate.split()[-1] for candidate in candidates]

            if vote in accepted_votes:
                with open(VOTES_OUTPUT_FILE, 'a') as f:
                    f.write(f"{name}/{cnic}: {vote}\n")
                client_socket.sendall("Thank you for voting!\n".encode())
            else:
                client_socket.sendall("Invalid vote. Please select a proper pole name.\n".encode())
        else:
            client_socket.sendall("Authentication failed. You are not registered to vote.\n".encode())

    except Exception as e:
        client_socket.sendall(f"An error occurred: {e}\n".encode())
    finally:
        client_socket.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("127.0.0.1", 8080))
    server_socket.listen(5)
    print("Server is running and waiting for connections...")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr}")
        threading.Thread(target=handle_client, args=(client_socket,)).start()

if __name__ == "__main__":
    main()
