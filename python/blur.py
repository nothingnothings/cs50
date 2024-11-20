import sys
from PIL import Image, ImageFilter

if len(sys.argv) != 3:
    print("Usage: python blur.py <input image> <output image>")
    sys.exit(1)

input_image = sys.argv[1]
output_image = sys.argv[2]

image = Image.open(input_image)
blurred = image.filter(ImageFilter.BoxBlur(1))
blurred.save(output_image)
