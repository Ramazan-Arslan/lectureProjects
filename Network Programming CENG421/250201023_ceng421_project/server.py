#Ramazan Arslan / 250201023
#Sources:
    # https://www.youtube.com/watch?v=nmzzeAvQHp8
    # https://www.pythoncentral.io/how-to-check-if-an-object-has-an-attribute-in-python/
    # https://stackoverflow.com/questions/7961499/best-way-to-loop-over-a-python-string-backwards
import threading
import socket
host = '127.0.0.1'
port = 59000
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()
clients = []
aliases = []
allMessages = []
answers=[]
def broadcast(message):
    for client in clients:
        client.send(message)

def handle_client(client):
    player1=""
    player2=""
    while True:
        
            message = client.recv(1024)
            messageList = []
            allMessages.append(messageList)
            deneme= message
            for i in reversed(deneme):
                messageList.append(i)
            if(messageList[0] == 107 and messageList[1] == 99):
                if(messageList[-2] == 49):
                    player1="rock"
                    answers.append(player1)
                elif(messageList[-2] == 50):
                    player2="rock"
                    answers.append(player2)
               
            elif(messageList[0] == 114 and messageList[1] == 101):
                if(messageList[-2] == 49):
                    player1="paper"
                    answers.append(player1)
                elif(messageList[-2] == 50):
                    player2="paper"
                    answers.append(player2)
                

            elif(messageList[0] == 115 and messageList[1] == 114):
                if(messageList[-2] == 49):
                    player1="scissors"
                    answers.append(player1)
                elif(messageList[-2] == 50):
                    player2="scissors"
                    answers.append(player2)
 
            if(len(allMessages) == 2):
                if( ( answers[0] == 'rock' and answers[1] == 'paper') or ( answers[0] == 'paper' and answers[1] == 'scissors' ) or ( answers[0] == 'scissors' and answers[1] == 'rock' ) ):
                    if(allMessages[0][-2] == 49):
                        broadcast('\nP2 Won the game.\n'.encode('utf-8'))
                    else:
                        broadcast('\nP1 Won the game.\n'.encode('utf-8'))

                elif( ( answers[0] == 'rock' and answers[1] == 'scissors') or  ( answers[0] == 'paper' and answers[1] == 'rock') or  ( answers[0] == 'scissors' and answers[1] == 'paper') ):
                    if(allMessages[0][-2] == 50):
                        broadcast('\nP2 Won the game.\n'.encode('utf-8'))
                    else:
                        broadcast('\nP1 Won the game.\n'.encode('utf-8'))

                else :
                   broadcast('\nScoreless.\n'.encode('utf-8'))
                
                break;
       


def receive():
    while True:
        print('Server is running and listening ...')
        client, address = server.accept()
        print(f'connection is established with {str(address)}')
        client.send('alias?'.encode('utf-8'))
        alias = client.recv(1024)
        aliases.append(alias)
        clients.append(client)
        print(f'The alias of this client is {alias}'.encode('utf-8'))
        broadcast(f'{alias} has connected to game'.encode('utf-8'))
        if( len(aliases) == 2):
            broadcast('\nThe game is starting now.\n'.encode('utf-8'))
            broadcast('rock, paper ,scissors ?'.encode('utf-8'))
        thread = threading.Thread(target=handle_client, args=(client,))
        thread.start()


if __name__ == "__main__":
    receive()