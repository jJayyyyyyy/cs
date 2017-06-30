from PIL import Image
import sys

# RGBA-white, which is RGB-white with alpha-0
white = (255, 255, 255, 0)

def get_square(img):
	size = img.size
	length, width = size[0:2]
	edgeLength = max(length, width)
	newSize = (edgeLength, edgeLength)
	square = Image.new('RGBA', newSize, white)	# RGBA
	region = ( (edgeLength - length)//2, (edgeLength - width)//2 )
	square.paste(img, region)
	print('sqaure size: ', square.size)
	square.save('sqaure.png', 'png')

	return square

def resize_640(img):
	size = img.size
	length, width = size[0:2]
	newSize = (640, 640)
	newImage = img.resize(newSize, Image.ANTIALIAS)
	print('resized image: ', newImage.size)
	newImage.save('square_640.png', 'png')
	
	return newImage

def get_frame(img):
	size = img.size
	newSize = (800, 800)
	square = Image.new('RGBA', newSize, 'white')	# RGBA, but 'white' to add white-color frame
	region = (80, 80)
	square.paste(img, region)
	print('size with frame: ', square.size)
	square.save('square_800_with_frame.png', 'png')

	return square

def get_mask():
	# logo.png should be a 200*200 png image
	logo = Image.open('logo.png').convert('RGBA')
	logoSize = logo.size
	diameter = logoSize[0]
	white = (255, 255, 255, 0)
	size = (diameter, diameter)

	# background
	bg = Image.new('RGBA', size, white)
	radius = diameter / 2
	center = 0.0 + float(diameter/2)
	logoLoad = logo.load()
	bgLoad = bg.load()

	for i in range(diameter):
		for j in range(diameter):
			x = abs(i - center + 0.5)
			y = abs(j - center + 0.5)
			dis = pow(x, 2) + pow(y, 2)
			if dis <= pow(radius, 2):
				bgLoad[i, j] = logoLoad[i, j]
	return bg

def main():
	filename = sys.argv[1]
	img = Image.open(filename)
	square = get_square(img)
	square640 = resize_640(square)
	square800 = get_frame(square640)
	
	portrait = square800
	mask = get_mask()
	alpha = mask.split()[3]
	region = (600, 600)
	portrait.paste(mask, region, mask=alpha)
	portrait.show()
	portrait.save('portrait_with_logo.png', 'png')

if __name__ == '__main__':
	main()
