from PIL import Image, ImageGrab
import sys
import getopt


def get_name(argv):
    file_name = ""
    try:
        opts, args = getopt.getopt(argv, "n:", ["name="])
    except getopt.GetoptError:
        print("Use -n to Enter the pic name")
        sys.exit(-1)
    for opt, arg in opts:
        if opt in ["-n", "--name"]:
            file_name = arg
        else:
            print("Use -n to Enter the pic name")
            sys.exit(-1)
    if file_name == "":
        print("Use -n to Enter the pic name")
        sys.exit(-1)
    return file_name


if __name__ == "__main__":
    file_name = get_name(sys.argv[1:])
    im = ImageGrab.grabclipboard()
    if isinstance(im, Image.Image):
        print("image:size:%s, mode: %s" % (im.size, im.mode))
        im.save("./screenshots/" + file_name + ".png")

    elif im:
        for filename in im:
            try:
                print("filename: %s" % filename)
                im = Image.open(filename)
            except IOError:
                pass  # ignore this file
            else:
                print("ImageList: size : %s, mode: %s" % (im.size, im.mode))
    else:
        print("no pic in clipboard.")
