import sys
import struct

byte_order = sys.byteorder
print("Byte Order of system:", byte_order,"endian")
value = 0x5617
packed_little = list(struct.pack('<H', value))
packed_big = list(struct.pack('>H', value))
print("Packed bytes (little-endian):", packed_little)
print("Packed bytes (big-endian):", packed_big)
print("Stored in memory as (little-endian):")
for i in packed_little:
    print(hex(i))
print("Stored in memory as (big-endian):")
for i in packed_big:
    print(hex(i))