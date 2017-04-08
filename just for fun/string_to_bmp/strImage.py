import math, sys

def get_string(filename):
    with open(filename, 'r') as f:
        s = '\n' + f.read()
    return align_string(s)

def align_string(s):
    # align the size of string to multiple of 12
    raw_size = len(s)
    whitespace = 12 - raw_size%12
    s = s + ' '*whitespace
    return s

def get_width(raw_size):
    width = math.floor( math.sqrt( raw_size/3 ) )
    if width > 4:
        width = width - width%4
    else:
        width = 4
    return width

def get_height(raw_size, width):
    return raw_size//3//width

def make_BMP(target, s, raw_size, width, height ):
    HEADER_SIZE = 54
    total_size = HEADER_SIZE + raw_size
    with open(target, 'wb') as f:
        f.write( 'BM'.encode('utf-8') )
        f.write( bytes([ total_size%256 ]) + bytes([ total_size//256 ]) + bytes([total_size//256//256]) + bytes([0]) )
        f.write( b'\x00\x00\x00\x00')
        f.write( bytes([ HEADER_SIZE ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( b'\x28\x00\x00\x00')
        f.write( bytes([ width ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( bytes([ height ]) + bytes([0]) + bytes([0]) + bytes([0]) )
        f.write( b'\x01\x00\x18\x00\x00\x00\x00\x00')
        f.write( bytes([ raw_size%256 ]) + bytes([ raw_size//256 ]) + bytes([total_size//256//256]) + bytes([0]) )
        f.write( b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
        f.write( s.encode('utf-8') )

def main(src, target):
    s = get_string(src)
    raw_size = len(s)
    width = get_width(raw_size)
    height = get_height(raw_size, width)

    make_BMP(target, s, raw_size, width, height)

if __name__ == '__main__':
    main(sys.argv[1], 'demo2.bmp')