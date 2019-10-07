import logging
import socket

log = logging.getLogger(__name__)


class SocketManagerError(Exception):
    pass


class SocketManager(object):
    _socket = None

    def __init__(self, host='nanpy.local', port=5678):
        self.host = host
        self.port = port

    def open(self):
        log.debug('opening:%s:%s', self.host, self.port)
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._socket.connect((self.host, self.port))

    def close(self):
        log.debug('closing:%s:%s', self.host, self.port)
        if self._socket:
            self._socket.close()
            self._socket = None

    def write(self, value):
        if not self._socket:
            self.open()
        log.debug('sending:%s', repr(value))
        self._socket.sendall(bytes(value, 'latin-1'))

    def readline(self):
        if not self._socket:
            self.open()
        s = b''
        while 1:
            c = self._socket.recv(1)
            log.debug('recv: %s', repr(c.decode()))
            if c.decode() == '\r':
                continue
            if c.decode() == '\n':
                break
            if c.decode() == '':
                break
            s += c

        log.debug('received:%s', repr(s))
        s = s.decode()
        if not len(s):
            raise SocketManagerError('timeout!')
        return s
