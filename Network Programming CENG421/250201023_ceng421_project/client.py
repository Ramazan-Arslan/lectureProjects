#Ramazan Arslan / 250201023
#Sources:
    # https://www.youtube.com/watch?v=nmzzeAvQHp8
    # https://www.pythoncentral.io/how-to-check-if-an-object-has-an-attribute-in-python/
    # https://stackoverflow.com/questions/7961499/best-way-to-loop-over-a-python-string-backwards
import threading
import socket
alias = input('Choose an nickname for game : ')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 59000))

def client_receive():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if message == "alias?":
                client.send(alias.encode('utf-8'))
            else:
                print(message)
        except:
            print('Error!')
            client.close()
            break


def client_send():
    while True:
        message = f'{alias}: {input("")}'
        client.send(message.encode('utf-8'))


receive_thread = threading.Thread(target=client_receive)
receive_thread.start()

send_thread = threading.Thread(target=client_send)
send_thread.start()