import socket 

customer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
customer.connect(('127.0.0.1', 8080))
customer.sendall(b"Hello from Python!")
print("Message sent to the C++ server")

customer.close()
