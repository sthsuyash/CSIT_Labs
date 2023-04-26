#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

#include "name.c"

// structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} message;

key_t key;
int msgid;

void sendmsg(key_t key)
{
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Write Data : ");
    fgets(message.mesg_text, MAX, stdin);

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data send is : %s \n", message.mesg_text);
}

void getmsg()
{

    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // display the message
    printf("Data Received is : %s \n",
           message.mesg_text);

    // to destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);
}

int main()
{
    // ftok to generate unique key
    key = ftok("progfile", 65);
    sendmsg(key);
    getmsg();

    name("4(b)", "Suyash Shrestha", 22, 'B');

    return 0;
}
