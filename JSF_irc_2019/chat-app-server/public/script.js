const socket = io('http://localhost:3000')
const messageContainer = document.getElementById('message-container')
const roomContainer = document.getElementById('room-container')
const messageForm = document.getElementById('send-container')
const messageInput = document.getElementById('message-input')


if (messageForm != null) {
    const name = prompt('What is your name ? ')
    socket.emit('new-user', roomName, name)
}

socket.on('chat-message-log-failed', data => {
    appendMessage('LOGIN FAILED')
})

socket.on('room-list', data => {
    appendMessage('room list: ['+data.join(", ")+']')
})

socket.on('chat-message', data => {
    appendMessage(`${data.user}[${data.room}]: ${data.message}`)
})

socket.on('user-connected', data => {
    appendMessage(`${data.user} connected inside ${data.room}`)
})

socket.on('chat-message-log', data => {
    for (key in data.messages) {
        appendMessage(`${data.messages[key].user}: ${data.messages[key].message}`)
    }
    appendMessage('You joined the room')
})

socket.on('room-deleted', room => {
    appendMessage(`room ${room} deleted`)
})

socket.on('user-disconnected', data => {
    appendMessage(`${data.name} disconnected of room ${data.room}`)
})

socket.on('room-created', name => {
    const roomElement = document.createElement('div')
    const roomLinkElement = document.createElement('a')
    roomElement.classList.add("row")
    roomElement.append(roomLinkElement)
    roomLinkElement.href = `/${name}`
    roomLinkElement.text = name
    roomContainer.append(roomElement);
})

messageForm.addEventListener('submit', e => {
    e.preventDefault()
    const message = messageInput.value
    appendMessage(`You: ${message}`)
    socket.emit('send-chat-message', roomName, message)
    messageInput.value = ''
})

function appendMessage(message) {
    const messageElement = document.createElement('div')
    messageElement.innerText = message
    messageContainer.append(messageElement)
}

function deleteroom() {
    // requete post pour delete la room actuelle
    fetch(`/delete/${roomName}`, {
        method: 'DELETE',
        headers: {'Content-type': 'application/json; charset=UTF-8'}   
    })
}