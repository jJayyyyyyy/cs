def get_BMP():
    s = 'hello world.'
    width = 4
    height = 1
    raw_size = len(s)
    HEADER_SIZE = 54
    total_size = HEADER_SIZE + raw_size
    
    with open('test.bmp', 'wb') as f:
        f.write( 'BM'.encode('utf-8') )
        f.write( bytes([ total_size ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( b'\x00\x00\x00\x00')
        f.write( bytes([ HEADER_SIZE ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( b'\x28\x00\x00\x00')
        f.write( bytes([ width ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( bytes([ height ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( b'\x01\x00\x18\x00\x00\x00\x00\x00')
        f.write( bytes([ raw_size ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
        f.write( s.encode('utf-8') )
    
get_BMP()
