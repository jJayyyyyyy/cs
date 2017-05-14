#!/usr/bin/env python
# -*- coding: utf-8 -*-

from PIL import Image, ImageChops

img = Image.open('demo.bmp')
i_img = ImageChops.invert(img)
i_img.save('demo.bmp')
