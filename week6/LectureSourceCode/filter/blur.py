# Blurs an image

from os import get_handle_inheritable
from PIL import Image, ImageFilter

# Blur Image
before = Image.open("bridge.bmp")
after = before.filer(ImageFilter.BoxBlur(1))
after.save("out.bmp") 