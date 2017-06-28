from PIL import Image
import sys

portrait = 'portrait.jpeg'
logo = 'logo.png'

def circle():
	old_img = Image.open(logo).convert("RGBA")
	size = old_img.size
	diameter = min(size[0], size[1])
	if size[0] != size[1]:
		size = (diameter, diameter)
		old_img = old_img.resize( size, Image.ANTIALIAS)
	
	rgb_white = (255, 255, 255, 0)
	size = (diameter, diameter)

	white_img = Image.new('RGBA', size, rgb_white)

	old_img_load = old_img.load()
	white_img_load = white_img.load()
	
	radius = diameter / 2
	center = 0.0 + float(diameter/2)

	for i in range(diameter):
		for j in range(diameter):
			x = abs(i - center + 0.5)
			y = abs(j - center + 0.5)
			l = pow(x, 2) + pow(y, 2)
			if l <= pow(radius, 2):
				white_img_load[i, j] = old_img_load[i, j]
	return white_img


def get_portrait(filename):
	old_img = Image.open(filename)
	old_size = old_img.size

	new_size = (old_size[0] + 200, old_size[1] + 200)
	new_img = Image.new('RGB', new_size, 'white')

	region = ( (new_size[0] - old_size[0])//2, (new_size[1] - old_size[1])//2 )

	new_img.paste(old_img, region)

	mask = circle()
	a = mask.split()[3]
	box = (old_size[0], old_size[1], new_size[0], new_size[1])
	new_img.paste(mask, box, mask=a)

	return new_img

def main():
	filename = sys.argv[1]
	portrait = get_portrait(filename)
	portrait.show()
	# portrait.save('new_portrait.png', 'png')

main()

def others():
	# r = 118
	# border = (700-r, 700-r, 700+r, 700+r)

	# draw = ImageDraw.Draw(new_img)
	# draw.ellipse( border, fill=(255, 255, 255, 0)  )

	# mask = Image.open('logo.png')
	pass