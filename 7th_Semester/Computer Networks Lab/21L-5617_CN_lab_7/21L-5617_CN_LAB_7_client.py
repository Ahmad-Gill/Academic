import socket
import re 

def is_valid_cnic(cnic):
    pattern = r'^\d{5}-\d{7}-\d{1}$'
    return re.match(pattern, cnic) is not None

def main():
    try:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect(("127.0.0.1", 8080))
        print("Connected to the server.")
        name = input("Enter your name: ")
        while True:
            cnic = input("Enter your CNIC (format: 34569-1245743-3): ")
            if is_valid_cnic(cnic):
                break
            else:
                print("Invalid CNIC format. Please try again.")
        client_socket.sendall(f"{name},{cnic}".encode())
        response = client_socket.recv(1024).decode()
        print(response)  
        if "Authenticated" in response:
            candidate_info = client_socket.recv(1024).decode()
            print(candidate_info) 
            if "Error: You have already cast your vote" in response:
                print("You have already voted. Exiting...")
                return 
            vote = input("Enter your vote: ")
            client_socket.sendall(vote.encode())
            final_response = client_socket.recv(1024).decode()
            print(final_response)

    except ConnectionRefusedError:
        print("Unable to connect to the server. Please check if the server is running.")
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        client_socket.close() 

if __name__ == "__main__":
    main()
