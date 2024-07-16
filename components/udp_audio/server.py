import pyaudio
import socket

"""
Listen on udp port 6055 for audio data and stream directly to output speaker.
"""

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", 6056))

# Create an audio object
p = pyaudio.PyAudio()

# Open stream
stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, output=True)

# Listen for incoming audio
while True:
    try:
        data, addr = sock.recvfrom(1024)
        # print("received message: %s" % data)
        stream.write(data)
    except KeyboardInterrupt:
        break

stream.stop_stream()
stream.close()
p.terminate()

sock.close()
